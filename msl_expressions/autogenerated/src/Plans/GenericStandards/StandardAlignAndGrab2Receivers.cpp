#include "Plans/GenericStandards/StandardAlignAndGrab2Receivers.h"

/*PROTECTED REGION ID(inccpp1462368682104) ENABLED START*/ //Add additional includes here
#include "msl_robot/robotmovement/RobotMovement.h"
#include "engine/model/EntryPoint.h"
#include "engine/RunningPlan.h"
#include "engine/Assignment.h"
#include "engine/model/Plan.h"
#include <RawSensorData.h>
#include <Ball.h>
#include <Robots.h>
#include <pathplanner/PathPlanner.h>
#include "obstaclehandler/Obstacles.h"
#include <msl_robot/MSLRobot.h>
#include <msl_robot/kicker/Kicker.h>
#include <MSLWorldModel.h>
using nonstd::optional;
using nonstd::make_optional;
using nonstd::nullopt;
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1462368682104) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    StandardAlignAndGrab2Receivers::StandardAlignAndGrab2Receivers() :
            DomainBehaviour("StandardAlignAndGrab2Receivers")
    {
        /*PROTECTED REGION ID(con1462368682104) ENABLED START*/ //Add additional options here
        this->ratio = 0;
        this->ballRadius = 0;
        this->minOppDist = 0;
        this->sc = nullptr;
        this->minCloserOffset = 0;
        this->passCorridorWidth = 0;
        this->maxTurnAngle = 0;
        this->canPass = true;
        this->startTime = 0;
        this->tol = 0;
        this->minTol = 0;
        this->oldAngleErr = 0;
        this->angleIntErr = 0;
        this->trans = 0;
        this->haveBallCounter = 0;
        this->canPassCounter = 1;
        this->canPassThreshold = 1;
        /*PROTECTED REGION END*/
    }
    StandardAlignAndGrab2Receivers::~StandardAlignAndGrab2Receivers()
    {
        /*PROTECTED REGION ID(dcon1462368682104) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void StandardAlignAndGrab2Receivers::run(void* msg)
    {
        /*PROTECTED REGION ID(run1462368682104) ENABLED START*/ //Add additional options here
        msl::RobotMovement rm;
        auto ownPos = wm->rawSensorData->getOwnPositionVisionBuffer().getLastValidContent(); // actually ownPosition corrected
        auto egoBallPos = wm->ball->getPositionEgo();
        // return if necessary information is missing
        if (!ownPos || !egoBallPos)
        {
            return;
        }

        canPass = true;
        optional<geometry::CNPointAllo> alloTarget = nullopt;
        auto alloBall = egoBallPos->toAllo(*ownPos);

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
            shared_ptr<vector<int>> ids = parent->getAssignment()->getRobotsWorking(ep);
            // exactly one robot is receiver
            if (ids->size() > 0 && ids->at(0) != -1)
            {
                // get receiver position by id
                auto pos = wm->robots->teammates.getTeammatePositionBuffer(ids->at(0)).getLastValidContent();
                if (pos)
                {
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
            shared_ptr<vector<int>> ids = parent->getAssignment()->getRobotsWorking(ep2);
            // exactly one robot is receiver
            if (ids->size() > 0 && ids->at(0) != -1)
            {
                // get receiver position by id
                auto pos = wm->robots->teammates.getTeammatePositionBuffer(ids->at(0)).getLastValidContent();
                if (pos)
                {
                    recPos2 = make_optional<geometry::CNPointAllo>(pos->x, pos->y);
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
        geometry::CNPointAllo passPoint;
        if (recPos1->y < 0.0)
        {
            passPoint = geometry::CNPointAllo(recPos1->x, -wm->field->getFieldWidth() / 2 + 1000.0);
        }
        else
        {
            passPoint = geometry::CNPointAllo(recPos1->x, wm->field->getFieldWidth() / 2 - 1000.0);
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
            if (opponentTooClose && canPass)
            {
                canPass = false;
            }
//            if ( canPass && geometry::absDeltaAngle(
//                    ownPos->theta + M_PI,
//                    (passPoint - make_shared < geometry::CNPoint2D > (ownPos->x, ownPos->y))->angleTo()) > maxTurnAngle)
//            {
//                canPass = false;
//            }

            // some calculation to check whether any obstacle is inside the pass vector triangle
            auto ball2PassPoint = passPoint - alloBall;
            double passLength = ball2PassPoint.length();
            auto ball2PassPointOrth = geometry::CNVecAllo(-ball2PassPoint.y, ball2PassPoint.x).normalize() * ratio
                    * passLength;
            auto left = passPoint + ball2PassPointOrth;
            auto right = passPoint - ball2PassPointOrth;
            if (canPass && !outsideTriangle(alloBall, right, left, ballRadius, *obs)
                    && !outsideCorridore(alloBall, passPoint, this->passCorridorWidth, *obs))
            {
                canPass = false;
            }
        }
        // Hack coimbra 17
        if (canPass)
        {
            this->canPassCounter = max(-4, min(this->canPassCounter + 1, 5));
        }
        else
        {
            this->canPassCounter = max(-4, min(this->canPassCounter - 1, 5));
        }
        if (this->canPassCounter > this->canPassThreshold)
        {
            this->canPassThreshold = -2;
            cout << "SAAG2R: aiming to receiver" << endl;
            alloTarget = recPos1;
        }
        else
        {
            this->canPassThreshold = 2;
            cout << "SAAG2R: aiming to alternative receiver" << endl;
            alloTarget = recPos2;
        }

        msl_actuator_msgs::MotionControl mc;
        if (egoBallPos->length() > 900)
        {
            // Drive close to the ball, until dist < 900
            // replaced with new moveToPoint method
//            mc = msl::RobotMovement::moveToPointCarefully(egoBallPos, egoBallPos, 0, nullptr);
            query.egoDestinationPoint = egoBallPos;
            query.egoAlignPoint = egoBallPos;
            mc = rm.moveToPoint(query);

//			cout << "SAAG2R: egoBallPos->length() > 900 ROT: \t" << mc.motion.rotation << endl;
            if (mc.motion.angle != NAN)
            {
                send(mc);
            }
            else
            {
                cout << "motion command is NaN!!" << endl;
            }
            return;
        }

        bool haveBall = wm->ball->haveBall();
        if (!haveBall)
        {
            haveBallCounter = 0;
        }

        if (egoBallPos->length() > 450)
        {
            // Drive closer to the ball, but don't rotate
            // replaced with new moveToPoint method
//            mc = msl::RobotMovement::moveToPointCarefully(egoBallPos, egoBallPos, 0, nullptr);
            query.egoDestinationPoint = egoBallPos;
            query.egoAlignPoint = egoBallPos;
            mc = rm.moveToPoint(query);

            mc.motion.rotation = 0;
            mc.motion.translation = min(600.0, egoBallPos->length() / 1.66);
//			cout << "SAAG2R: egoBallPos->length() > 450 ROT: \t" << mc.motion.rotation << endl;
            if (mc.motion.angle != NAN)
            {
                send(mc);
            }
            else
            {
                cout << "motion command is NaN!!" << endl;
            }

            return;
        }

        double rot = this->trans / egoBallPos->length();

        auto egoMatePos = alloTarget->toEgo(*ownPos);

        geometry::CNPointEgo direction;

        double dangle = geometry::deltaAngle(this->robot->kicker->kickerAngle, egoMatePos.angleZ());

        double cross = egoMatePos.x * egoBallPos->y - egoMatePos.y * egoBallPos->x;
        double fac = -(cross > 0 ? 1 : -1);
        if (fabs(dangle) < 12.0 * M_PI / 180.0)
        {
            direction = egoBallPos->rotateZ(-fac * M_PI / 2.0).normalize() * this->trans * 0.66;
        }
        else
        {
            direction = egoBallPos->rotateZ(-fac * M_PI / 2.0).normalize() * this->trans;
        }

        double balldangle = geometry::deltaAngle(this->robot->kicker->kickerAngle, egoBallPos->angleZ());
        if (egoBallPos->length() > 350 && fabs(dangle) > 35.0 * M_PI / 180.0)
        {
            mc.motion.angle = direction.angleZ();
            mc.motion.translation = direction.length() * 1.6;
            mc.motion.rotation = fac * rot * 1.6;
//			cout << "SAAG2R: egoBallPos->length() > 350 && fabs(dangle) > 35.0 * M_PI / 180.0 ROT: \t"
//					<< mc.motion.rotation << endl;
            send(mc);
            return;
        }

        if (!haveBall)
        {
            if (fabs(balldangle) > 20.0 * M_PI / 180.0)
            {
                mc.motion.rotation = (balldangle > 0 ? 1 : -1) * 0.8;
                mc.motion.angle = M_PI;
                mc.motion.translation = 100;
//				cout << "SAAG2R: fabs(balldangle) > 20.0 * M_PI / 180.0 ROT: \t" << mc.motion.rotation << endl;
                send(mc);
                return;
            }
            else
            {
                mc.motion.rotation = balldangle * 0.5;
                mc.motion.angle = egoBallPos->angleZ();
                mc.motion.translation = egoBallPos->length() * 1.5;
//				cout << "SAAG2R: fabs(balldangle) > 20.0 * M_PI / 180.0 else ROT: \t" << mc.motion.rotation << endl;
                send(mc);
                return;
            }
        }

        angleIntErr += dangle;
        mc.motion.angle = direction.angleZ();
        mc.motion.translation = direction.length();
        mc.motion.rotation = fac * rot * (2 * fabs(0.8 * dangle + 0.1 * angleIntErr + 2 * (dangle - oldAngleErr)));
        oldAngleErr = dangle;
        if (haveBall)
        {
            haveBallCounter++;
            double runningTimeMS = (double)((wm->getTime() - startTime) / 1000000ul);
            if (runningTimeMS > 6000)
            {
                mc.motion.angle = M_PI;
                mc.motion.rotation = 0.0;
                mc.motion.translation = 100.0;
                cout << "SAAG2R: haveBall" << endl;
                this->setSuccess(true);
            }
            else if (haveBallCounter > 3
                    && ((runningTimeMS <= 3000.0 && fabs(dangle) < this->minTol)
                            || fabs(dangle)
                                    < this->minTol
                                            + max(0.0, (this->tol - this->minTol) / (3000.0 / (runningTimeMS - 3000.0)))))
            {
                mc.motion.angle = M_PI;
                mc.motion.rotation = 0.0;
                mc.motion.translation = 100.0;
                cout << "SAAG2R: haveBall esle if" << endl;
                this->setSuccess(true);
            }
        }
//		cout << "SAAG2R: last mc ROT: \t" << mc.motion.rotation << endl;
        send(mc);

        /*PROTECTED REGION END*/
    }
    void StandardAlignAndGrab2Receivers::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1462368682104) ENABLED START*/ //Add additional options here
        this->haveBallCounter = 0;
        this->angleIntErr = 0;
        this->oldAngleErr = 0;
        this->haveBallCounter = 0;
        this->startTime = wm->getTime();
        auto sc = supplementary::SystemConfig::getInstance();
        this->minTol = (*sc)["Behaviour"]->get<double>("StandardAlign.MinAlignTolerance", NULL);
        this->tol = (*sc)["Behaviour"]->get<double>("StandardAlign.AlignTolerance", NULL);
        this->minCloserOffset = (*this->sc)["Behaviour"]->get<double>("Pass", "MinCloserOffset", NULL);
        this->ballRadius = (*this->sc)["Rules"]->get<double>("Rules.BallRadius", NULL);
        this->ratio = tan((*this->sc)["Behaviour"]->get<double>("ThrowIn", "freeOppAngle", NULL) / 2);
        this->passCorridorWidth = (*this->sc)["Behaviour"]->get<double>("ThrowIn", "passCorridorWidth", NULL);
        this->maxTurnAngle = (*this->sc)["Behaviour"]->get<double>("ThrowIn", "maxTurnAngle", NULL);
        this->minOppDist = (*this->sc)["Behaviour"]->get<double>("ThrowIn", "minOppDist", NULL);
        this->trans = (*sc)["Behaviour"]->get<double>("StandardAlign.AlignSpeed", NULL);
        string tmp;
        bool success = true;
        this->canPass = true;
        this->canPassCounter = 1;
        this->canPassThreshold = 1;
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
            cerr << "SAAG2R: Parameter does not exist" << endl;
        }

        /*PROTECTED REGION END*/
    }
    /*PROTECTED REGION ID(methods1462368682104) ENABLED START*/ //Add additional methods here
    bool StandardAlignAndGrab2Receivers::outsideCorridore(geometry::CNPointAllo ball, geometry::CNPointAllo passPoint,
                                                          double passCorridorWidth,
                                                          vector<geometry::CNPointAllo>& points)
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

    bool StandardAlignAndGrab2Receivers::outsideCorridoreTeammates(geometry::CNPointAllo ball,
                                                                   geometry::CNPointAllo passPoint,
                                                                   double passCorridorWidth,
                                                                   vector<geometry::CNPointAllo>& points)
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

    bool StandardAlignAndGrab2Receivers::outsideTriangle(geometry::CNPointAllo a, geometry::CNPointAllo b,
                                                         geometry::CNPointAllo c, double tolerance,
                                                         vector<geometry::CNPointAllo>& points)
    {
        auto a2b = b - a;
        auto b2c = c - b;
        auto c2a = a - c;
        for (int i = 0; i < points.size(); i++)
        {
            auto p = points.at(i);
            auto a2p = p - a;
            auto b2p = p - b;
            auto c2p = p - c;

            if ((a2p.x * a2b.y - a2p.y * a2b.x) / a2p.normalize().length() < tolerance
                    && (b2p.x * b2c.y - b2p.y * b2c.x) / b2p.normalize().length() < tolerance
                    && (c2p.x * c2a.y - c2p.y * c2a.x) / c2p.normalize().length() < tolerance)
            {
                return false;
            }

        }
        return true;
    }
/*PROTECTED REGION END*/
} /* namespace alica */
