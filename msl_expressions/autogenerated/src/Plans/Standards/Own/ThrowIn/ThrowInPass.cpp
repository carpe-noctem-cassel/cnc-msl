using namespace std;
#include "Plans/Standards/Own/ThrowIn/ThrowInPass.h"

/*PROTECTED REGION ID(inccpp1462363192018) ENABLED START*/ //Add additional includes here
#include "msl_robot/robotmovement/RobotMovement.h"
#include "engine/model/EntryPoint.h"
#include "engine/RunningPlan.h"
#include "engine/Assignment.h"
#include "engine/model/Plan.h"
#include <RawSensorData.h>
#include <Ball.h>
#include <Robots.h>
#include <pathplanner/PathPlanner.h>
#include <msl_robot/kicker/Kicker.h>
#include <msl_robot/MSLRobot.h>
#include <msl_helper_msgs/PassMsg.h>
#include <MSLWorldModel.h>
using geometry::CNPointAllo;
using geometry::CNPointEgo;
using geometry::CNVecEgo;
using geometry::CNVecAllo;
using nonstd::nullopt;
using nonstd::make_optional;
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1462363192018) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    ThrowInPass::ThrowInPass() :
            DomainBehaviour("ThrowInPass")
    {
        /*PROTECTED REGION ID(con1462363192018) ENABLED START*/ //Add additional options here
        this->ratio = 0;
        this->closerFactor = 0;
        this->ballRadius = 0;
        this->minOppDist = 0;
        this->sc = nullptr;
        this->passCorridorWidth = 0;
        this->maxTurnAngle = 0;
        this->canPass = true;
        this->maxVel = 2000;
        this->pRot = 2.1;
        this->dRot = 0.0;
        this->lastRotError = 0;
        this->minRot = 0.1;
        this->maxRot = M_PI * 4;
        this->accel = 2000;
        this->arrivalTimeOffset = NAN;
        this->sentPm = false;
        /*PROTECTED REGION END*/
    }
    ThrowInPass::~ThrowInPass()
    {
        /*PROTECTED REGION ID(dcon1462363192018) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void ThrowInPass::run(void* msg)
    {
        /*PROTECTED REGION ID(run1462363192018) ENABLED START*/ //Add additional options here
        auto ownPos = wm->rawSensorData->getOwnPositionVisionBuffer().getLastValidContent(); // actually ownPosition corrected
        auto egoBallPos = wm->ball->getPositionEgo();
        // return if necessary information is missing
        if (!ownPos || !egoBallPos)
        {
            return;
        }

        if (sentPm && !wm->ball->haveBall())
        {
            this->setSuccess(true);
        }

        canPass = true;
        CNPointAllo alloTarget;
        auto alloBall = egoBallPos->toAllo(*ownPos);

        int recId = -1;
        int aRecId = -1;
        EntryPoint* ep = getParentEntryPoint(teamMateTaskName1);
        if (ep != nullptr)
        {
            // get the plan in which the behavior is running
            auto parent = this->runningPlan->getParent().lock();
            if (parent == nullptr)
            {
                cout << "parent null" << endl;
                return;
            }
            // get robot ids of robots in found entry point
            auto ids = parent->getAssignment()->getRobotsWorking(ep);
            // exactly one robot is receiver
            if (ids->size() > 0 && ids->at(0) != -1)
            {
                // get receiver position by id
                auto pos = wm->robots->teammates.getTeammatePositionBuffer(ids->at(0)).getLastValidContent();
                if (pos)
                {
                    recId = ids->at(0);
                    recPos1 = make_optional<geometry::CNPointAllo>(pos->x, pos->y);
                }
                else
                {
                    recPos1 = nullopt;
                }
            }
        }

        EntryPoint* ep2 = getParentEntryPoint(teamMateTaskName2);
        if (ep2 != nullptr)
        {
            // get the plan in which the behavior is running
            auto parent = this->runningPlan->getParent().lock();
            if (parent == nullptr)
            {
                cout << "parent null" << endl;
                return;
            }
            // get robot ids of robots in found entry point
            auto ids = parent->getAssignment()->getRobotsWorking(ep2);
            // exactly one robot is receiver
            if (ids->size() > 0 && ids->at(0) != -1)
            {
                // get receiver position by id
                auto pos = wm->robots->teammates.getTeammatePositionBuffer(ids->at(0)).getLastValidContent();
                if (pos)
                {
                    aRecId = ids->at(0);
                    recPos2 = make_optional<CNPointAllo>(pos->x, pos->y);
                }
                else
                {
                    recPos2 = nullopt;
                }
            }
        }

        if (!recPos1 && !recPos2)
        {
            return;
        }
        // make the passpoints closer to the receiver
        CNPointAllo passPoint;
        if (recPos1->y < 0.0)
        {
            passPoint = CNPointAllo(recPos1->x, -wm->field->getFieldWidth() / 2 + 1000.0);
        }
        else
        {
            passPoint = CNPointAllo(recPos1->x, wm->field->getFieldWidth() / 2 - 1000.0);
        }

        if (!wm->field->isInsidePenalty(passPoint, 0.0))
        {

            // min dist to opponent
            auto obs = wm->robots->opponents.getOpponentsAlloClusteredBuffer().getLastValidContent();
            bool opponentTooClose = false;
            for (int i = 0; i < obs->size(); i++)
            {
                if (obs->at(i).distanceTo(passPoint) < minOppDist)
                {
                    opponentTooClose = true;
                    break;
                }
            }
            if (canPass && opponentTooClose)
            {
                canPass = false;
            }
//            if (canPass && geometry::absDeltaAngle(
//                    ownPos->theta + M_PI,
//                    (passPoint - make_shared < geometry::CNPoint2D > (ownPos->x, ownPos->y))->angleTo()) > maxTurnAngle)
//            {
//                canPass = false;
//            }

            // some calculation to check whether any opponent is inside the pass vector triangle
            auto ball2PassPoint = passPoint - alloBall;
            double passLength = ball2PassPoint.length();
            auto ball2PassPointOrth = CNVecAllo(-ball2PassPoint.y, ball2PassPoint.x).normalize() * ratio * passLength;
            auto left = passPoint + ball2PassPointOrth;
            auto right = passPoint - ball2PassPointOrth;
            if (canPass && !outsideTriangle(alloBall, right, left, ballRadius, *obs)
                    && !outsideCorridore(alloBall, passPoint, this->passCorridorWidth, *obs))
            {
                canPass = false;
            }

            // no opponent was in dangerous distance to our pass vector, now check our teammates with other parameters
            auto matePoses = wm->robots->teammates.getTeammatesAlloClusteredBuffer().getLastValidContent();
            if (canPass && matePoses
                    && !outsideCorridoreTeammates(alloBall, passPoint, this->ballRadius * 4, *matePoses))
            {
                canPass = false;
            }

        }
        int bestReceiverId = -1;
        if (canPass)
        {
            alloTarget = recPos1;
            bestReceiverId = recId;
        }
        else
        {
            alloTarget = recPos2;
            bestReceiverId = aRecId;
        }
        msl_actuator_msgs::MotionControl mc;
        auto ballVel = this->wm->ball->getVisionBallVelocityBuffer().getLastValidContent();
        CNVecEgo ballVel2;
        if (!ballVel)
        {
            ballVel2 = CNVecEgo(0, 0);
        }
        else if (ballVel->length() > 5000)
        {
            auto v = ballVel->normalize() * 5000;
            ballVel2 = v;
        }
        else
        {
            ballVel2 = ballVel;
        }
        auto aimPoint = passPoint.toEgo(*ownPos);
        double aimAngle = aimPoint.angleZ();
        double ballAngle = egoBallPos->angleZ();
        double deltaAngle = geometry::deltaAngle(ballAngle, aimAngle);
        if (abs(deltaAngle) < M_PI / 36)
        { // +/-5 degree
          //Kick && PassMsg
            msl_helper_msgs::PassMsg pm;
            msl_msgs::Point2dInfo pinf;
            // Distance to aim point * direction of our kicker = actual pass point destination
            double dist = aimPoint.length();
            auto dest = CNPointEgo(-dist, 0);
            dest = dest.toAllo(*ownPos);
            pinf.x = dest.x;
            pinf.y = dest.y;
            pm.destination = pinf;
            pinf = msl_msgs::Point2dInfo();
            pinf.x = ownPos->x;
            pinf.y = ownPos->y;
            pm.origin = pinf;
            pm.receiverID = bestReceiverId;
            msl_actuator_msgs::KickControl km;
            km.enabled = true;
            km.kicker = 1; //(ushort)KickHelper.KickerToUseIndex(egoBallPos->angleTo());

            auto goalReceiverVec = dest - alloTarget;
            double v0 = 0;
            double distReceiver = goalReceiverVec.length();
            double estimatedTimeForReceiverToArrive = (sqrt(2 * accel * distReceiver + v0 * v0) - v0) / accel;
            //considering network delay and reaction time 1s?:
            estimatedTimeForReceiverToArrive += 1.0;
            pm.validFor = (unsigned long long)(estimatedTimeForReceiverToArrive * 1000000000.0 + 300000000.0); // this is sparta!
            if (closerFactor < 0.01)
            {
                km.power = (ushort)this->robot->kicker->getKickPowerPass(aimPoint.length());
            }
            else
            {
                km.power = (ushort)this->robot->kicker->getPassKickpower(
                        dist, estimatedTimeForReceiverToArrive + arrivalTimeOffset);
            }

            send(km);
            if (this->robot->kicker->lowShovelSelected)
            {
                send(pm);
                this->sentPm = true;
            }

        }
        auto dstscan = this->wm->rawSensorData->getDistanceScanBuffer().getLastValidContent();
        if (dstscan  && (*dstscan)->size() != 0)
        {
            double distBeforeBall = minFree(egoBallPos->angleZ(), 200, *dstscan);
            if (distBeforeBall < 250)
                this->setFailure(true);
        }
        mc = msl_actuator_msgs::MotionControl();
        mc.motion.rotation = deltaAngle * pRot + (deltaAngle - lastRotError) * dRot;
        double sign = geometry::sgn(mc.motion.rotation);
        mc.motion.rotation = sign * min(this->maxRot, max(abs(mc.motion.rotation), this->minRot));
        lastRotError = deltaAngle;
        double transBallOrth = egoBallPos->length() * mc.motion.rotation; //may be negative!
        double transBallTo = min(1000.0, ballVel2.length()); //Math.Max(ballPos.Distance(),ballVel2.Distance());
        auto driveTo = egoBallPos->rotateZ(-M_PI / 2.0);
        driveTo = driveTo.normalize() * transBallOrth;
        driveTo = driveTo + egoBallPos->normalize() * transBallTo;
        if (driveTo.length() > maxVel)
        {
            driveTo = driveTo.normalize() * maxVel;
        }
        mc.motion.angle = driveTo.angleZ();
        mc.motion.translation = driveTo.length();

        send(mc);

        /*PROTECTED REGION END*/
    }
    void ThrowInPass::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1462363192018) ENABLED START*/ //Add additional options here
        this->sentPm = false;
        auto sc = supplementary::SystemConfig::getInstance();
        this->closerFactor = (*this->sc)["Behaviour"]->get<double>("Pass", "CloserFactor", NULL);
        this->ballRadius = (*this->sc)["Rules"]->get<double>("Rules.BallRadius", NULL);
        this->ratio = tan((*this->sc)["Behaviour"]->get<double>("ThrowIn", "freeOppAngle", NULL) / 2);
        this->passCorridorWidth = (*this->sc)["Behaviour"]->get<double>("ThrowIn", "passCorridorWidth", NULL);
        this->maxTurnAngle = (*this->sc)["Behaviour"]->get<double>("ThrowIn", "maxTurnAngle", NULL);
        this->minOppDist = (*this->sc)["Behaviour"]->get<double>("ThrowIn", "minOppDist", NULL);
        this->maxVel = (*this->sc)["Behaviour"]->get<double>("Behaviour", "MaxSpeed", NULL);
        this->pRot = (*this->sc)["Dribble"]->get<double>("AlignAndPass", "RotationP", NULL);
        this->dRot = (*this->sc)["Dribble"]->get<double>("AlignAndPass", "RotationD", NULL);
        this->minRot = (*this->sc)["Dribble"]->get<double>("AlignAndPass", "MinRotation", NULL);
        this->maxRot = (*this->sc)["Dribble"]->get<double>("AlignAndPass", "MaxRotation", NULL);
        this->accel = (*this->sc)["Dribble"]->get<double>("AlignAndPass", "ReceiverRobotAcceleration", NULL);
        this->arrivalTimeOffset = (*this->sc)["Behaviour"]->get<double>("Pass", "ArrivalTimeOffset", NULL);
        string tmp;
        bool success = true;
        try
        {
            success &= getParameter("TeamMateTaskName1", tmp);
            if (success)
            {
                teamMateTaskName1 = tmp;
            }

            success &= getParameter("TeamMateTaskName2", tmp);
            if (success)
            {
                teamMateTaskName2 = tmp;
            }

        }
        catch (exception& e)
        {
            cerr << "Could not cast the parameter properly" << endl;
        }
        if (!success)
        {
            cerr << "SA2P: Parameter does not exist" << endl;
        }

        /*PROTECTED REGION END*/
    }
    /*PROTECTED REGION ID(methods1462363192018) ENABLED START*/ //Add additional methods here
    bool ThrowInPass::outsideCorridore(CNPointAllo ball, CNPointAllo passPoint, double passCorridorWidth,
                                       vector<CNPointAllo> &points)
    {
        for (int i = 0; i < points.size(); i++)
        {
            if (geometry::distancePointToLineSegment(points.at(i).x, points.at(i).y, ball, passPoint)
                    < passCorridorWidth)
            {
                return false;
            }
        }
        return true;
    }

    bool ThrowInPass::outsideCorridoreTeammates(CNPointAllo ball, CNPointAllo passPoint, double passCorridorWidth,
                                                vector<geometry::CNPointAllo> &points)
    {
        for (int i = 0; i < points.size(); i++)
        {
            if (geometry::distancePointToLineSegment(points.at(i).x, points.at(i).y, ball, passPoint)
                    < passCorridorWidth && ball.distanceTo(points.at(i)) < ball.distanceTo(passPoint) - 100)
            {
                return false;
            }
        }
        return true;
    }

    bool ThrowInPass::outsideTriangle(CNPointAllo a, CNPointAllo b, CNPointAllo c, double tolerance,
                                      vector<CNPointAllo> &points)
    {
        auto a2b = b - a;
        auto b2c = c - b;
        auto c2a = a - c;
        CNVecAllo a2p;
        CNVecAllo b2p;
        CNVecAllo c2p;
        CNPointAllo p;
        for (int i = 0; i < points.size(); i++)
        {
            p = points.at(i);
            a2p = p - a;
            b2p = p - b;
            c2p = p - c;

            if ((a2p.x * a2b.y - a2p.y * a2b.x) / a2p.normalize().length() < tolerance
                    && (b2p.x * b2c.y - b2p.y * b2c.x) / b2p.normalize().length() < tolerance
                    && (c2p.x * c2a.y - c2p.y * c2a.x) / c2p.normalize().length() < tolerance)
            {
                return false;
            }

        }
        return true;
    }

    double ThrowInPass::minFree(double angle, double width, shared_ptr<vector<double>> dstscan)
    {
        double sectorWidth = 2.0 * M_PI / dstscan->size();
        int startSector = mod((int)floor(angle / sectorWidth), dstscan->size());
        double minfree = dstscan->at(startSector);
        double dist, dangle;
        for (int i = 1; i < dstscan->size() / 4; i++)
        {
            dist = dstscan->at(mod((startSector + i), dstscan->size()));
            dangle = sectorWidth * i;
            if (abs(dist * sin(dangle)) < width)
            {
                minfree = min(minfree, abs(dist * cos(dangle)));
            }

            dist = dstscan->at(mod((startSector - i), dstscan->size()));
            if (abs(dist * sin(dangle)) < width)
            {
                minfree = min(minfree, abs(dist * cos(dangle)));
            }

        }
        return minfree;
    }

    int ThrowInPass::mod(int x, int y)
    {
        int z = x % y;
        if (z < 0)
            return y + z;
        else
            return z;
    }

/*PROTECTED REGION END*/
} /* namespace alica */
