#include "Plans/Behaviours/Intercept.h"

/*PROTECTED REGION ID(inccpp1458757170147) ENABLED START*/ //Add additional includes here
#include <Ball.h>
#include <RawSensorData.h>
#include <Game.h>
#include <msl_robot/kicker/Kicker.h>
#include <pathplanner/PathProxy.h>
#include <msl_robot/MSLRobot.h>
#include <msl_robot/robotmovement/RobotMovement.h>
#include <msl_robot/robotmovement/MovementQuery.h>
#include <pathplanner/PathPlannerQuery.h>
using nonstd::make_optional;
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1458757170147) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    Intercept::Intercept() :
            DomainBehaviour("Intercept")
    {
        /*PROTECTED REGION ID(con1458757170147) ENABLED START*/ //Add additional options here
        sc = supplementary::SystemConfig::getInstance();
        pp = msl::PathProxy::getInstance();

        lastDistErr = 0;
        distIntErr = 0;

        lastRotErr = 0;
        rotIntErr = 0;

        maxBallVelocity = (*sc)["Drive"]->get<double>("Drive.Intercept.MaxBallVelocity", NULL);
        catchRadius = (*sc)["Drive"]->get<double>("Drive.Carefully.CatchRadius", NULL);

        prot = (*sc)["Drive"]->get<double>("Drive.Intercept.RotationP", NULL);
        pirot = (*sc)["Drive"]->get<double>("Drive.Intercept.RotationI", NULL);
        pdrot = (*sc)["Drive"]->get<double>("Drive.Intercept.RotationD", NULL);

        pdist = (*sc)["Drive"]->get<double>("Drive.Intercept.DistanceP", NULL);
        pidist = (*sc)["Drive"]->get<double>("Drive.Intercept.DistanceI", NULL);
        pddist = (*sc)["Drive"]->get<double>("Drive.Intercept.DistanceD", NULL);

        minDistErr = (*sc)["Drive"]->get<double>("Drive.Intercept.minDistErr", NULL);

        maxVel = (*sc)["Behaviour"]->get<double>("Behaviour.MaxSpeed", NULL);

        /*PROTECTED REGION END*/
    }
    Intercept::~Intercept()
    {
        /*PROTECTED REGION ID(dcon1458757170147) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void Intercept::run(void* msg)
    {
        /*PROTECTED REGION ID(run1458757170147) ENABLED START*/ //Add additional options here
//        this->setSuccess(true);

        // ACQUIRE NECESSARY DATA
        auto ownPos = this->wm->rawSensorData->getOwnPositionVisionBuffer().getLastValidContent();
        msl_actuator_msgs::MotionControl mc;
        if (!ownPos)
        {
            mc = this->robot->robotMovement->driveRandomly(500);
            send(mc);
            return;
        }

        auto egoBallPos = this->wm->ball->getPositionEgo();
        auto od = this->wm->rawSensorData->getCorrectedOdometryBuffer().getLastValidContent();
        if (!egoBallPos || !od)
        {
            return;
        }

        auto egoBallVel = this->wm->ball->getVisionBallVelocityBuffer().getLastValidContent();
        if (!egoBallVel)
        {
            cout << "Intercept: No ego ball vel" << endl;
            egoBallVel = make_optional<geometry::CNVecEgo>(0, 0);
        }
        else if (egoBallVel->length() > this->maxBallVelocity)
        {
            cout << "ballVel available Intercept" << endl;
            egoBallVel = egoBallVel->normalize() * this->maxBallVelocity;
        }

        // Ball is outside field, so drive to its position mapped into field
        auto alloBall = egoBallPos->toAllo(*ownPos);
        if (!this->wm->field->isInsideField(alloBall))
        {
            auto egoTarget = this->wm->field->mapInsideField(alloBall).toEgo(*ownPos);

            this->query.egoDestinationPoint = make_optional<geometry::CNPointEgo>(egoTarget);
            this->query.egoAlignPoint = egoBallPos;
//            auto additonalPopints = make_shared<vector<shared_ptr<geometry::CNPoint2D>>>();
//            additonalPopints->push_back(alloBall);
//            this->query->additionalPoints = additonalPopints;
            mc = this->robot->robotMovement->moveToPoint(query);
            if (egoTarget.length() < catchRadius)
            {
                mc.motion.translation = 0;
            }

            send(mc);
            return;
        }

        //TODO BUG something weird going on with allo/ego, see egoPredBall
        geometry::CNPointEgo predBall(egoBallPos->x, egoBallPos->y);
//		if (egoBallVel->length() > 4000.0)
//		{
        geometry::CNPositionEgo predPos(0.0, 0.0, 0.0);
        double timestep = 33;
        double rot = od->motion.rotation * timestep / 1000.0;
        for (int i = 1; i * timestep < 160; i++)
        {
            if (i > 6)
            {
                break;
            }
            predPos.x += cos(od->motion.angle + predPos.theta) * od->motion.translation * timestep / 1000.0;
            predPos.y += sin(od->motion.angle + predPos.theta) * od->motion.translation * timestep / 1000.0;
            predPos.theta += rot;

            predBall.x += egoBallVel->x * timestep / 1000.0;
            predBall.y += egoBallVel->y * timestep / 1000.0;

            if (predBall.distanceTo(predPos.getPoint()) < 250 + 110) //robotRadius+ballRadius
            {
                break;
            }
        }

        //this used to be commented in
//        auto egoPredBall = predBall.toEgo(*predPos);
        auto egoPredBall = predBall;
        //TODO dirty fix to avoid crashing into the surrounding
        if (!this->wm->field->isInsideField(predPos.getPoint().toAllo(*ownPos)))
        {
            cout << "not in field interccept" << endl;
            msl_actuator_msgs::MotionControl mc;
            mc.motion.angle = 0;
            mc.motion.rotation = 0;
            mc.motion.translation = 0;
            send(mc);
            return;
        }
//		}
        // PID controller for minimizing the distance between ball and me
        double distErr = max(egoPredBall.length(), minDistErr);
        double controlDist = distErr * pdist + distIntErr * pidist + (distErr - lastDistErr) * pddist;

        distIntErr += distErr - 1000.0; // reduce I part of the controller, when you are closer than 1 m to the ball
        distIntErr = max(0.0, min(800.0, distIntErr)); // never drive away from the ball, cause of the I part
        lastDistErr = distErr;

        geometry::CNVecEgo egoVelocity;
        auto currentGameState = this->wm->game->getGameState();
        if (currentGameState == msl::GameState::OppBallPossession)
        {
            egoVelocity = geometry::CNVecEgo(0, 0);
        }
        else
        {
            egoVelocity = *egoBallVel;
        }
//		cout << "Intercept: egoVelocity: " << egoVelocity->toString() << endl;
        egoVelocity.x += controlDist * cos(egoPredBall.angleZ());
        egoVelocity.y += controlDist * sin(egoPredBall.angleZ());
//		cout << "Intercept: egoVelocity: " << egoVelocity->toString() << endl;

        auto pathPlanningVec = egoVelocity.normalize() * min(egoVelocity.length(), egoPredBall.length());
        geometry::CNPointEgo pathPlanningPoint(pathPlanningVec.x, pathPlanningVec.y);
        auto alloDest = pathPlanningVec.toAllo(*ownPos);
        if (this->wm->field->isInsideField(alloBall, -150)
                && !this->wm->field->isInsideField(geometry::CNPointAllo(alloDest.x, alloDest.y)))
        {
            //pathPlanningPoint = wm->field->mapInsideField((alloDest, alloBall - ownPos))->alloToEgo(*ownPos);
            pathPlanningPoint = this->wm->field->mapInsideField((alloDest, alloBall - alloDest)).toEgo(*ownPos);
        }

        query.blockOppGoalArea = true;
        query.blockOwnGoalArea = true;
        cout << "in intercept" << endl;

        //SEGFAULT
        auto pathPlanningResult = pp->getEgoDirection(pathPlanningPoint, msl::PathEvaluator(),msl::PathPlannerQuery());
        if (!pathPlanningResult)
        {
            mc.motion.angle = pathPlanningPoint.angleZ();
        }
        else
        {
            mc.motion.angle = pathPlanningResult->angleZ();
        }

        mc.motion.translation = min(this->maxVel, max(pathPlanningResult->length(), egoVelocity.length()));

// PID controller for minimizing the kicker angle to ball
        double angleGoal = msl::Kicker::kickerAngle;
        double rotErr = geometry::deltaAngle(angleGoal, egoBallPos->angleZ());
        double controlRot = rotErr * prot + rotIntErr * pirot + (rotErr - lastRotErr) * pdrot;
        controlRot = max(-4 * M_PI, min(4 * M_PI, controlRot));

        rotIntErr += rotErr;
        rotIntErr = max(-2 * M_PI, min(2 * M_PI, rotIntErr));
        lastRotErr = rotErr;

// this is nice stuff but only when we are not approaching the opponent
        if (egoBallPos->length() < 700
                && (currentGameState == msl::GameState::OwnBallPossession
                        || currentGameState == msl::GameState::NobodyInBallPossession))
        {
            controlRot *= 2.3;
            //we probably translate to fast and cannot rotate anymore: So translate slower
            if (fabs(rotErr) > M_PI / 6)
            {
                mc.motion.translation *= min((fabs(rotErr) - M_PI / 6) / (M_PI * 5.0 / 6.0), egoBallVel->length());
            }
        }
        mc.motion.rotation = controlRot;

// Special handling for things around critical areas
        auto tmpMC = this->robot->robotMovement->ruleActionForBallGetter();
        if (!std::isnan(tmpMC.motion.translation))
        {
            send(tmpMC);
            cout << "Intercept: RuleAction: " << tmpMC.motion.translation << endl;
        }
        else
        {
            send(mc);
            cout << "Intercept: Normal: " << mc.motion.translation << endl;
        }

//        if (this->wm->ball->haveBallDribble(false))
//        {
//            this->setSuccess(true);
//        }
        if (this->wm->ball->haveBall())
        {
            cout << "success itnercept" << endl;
            this->setSuccess(true);
        }
        /*PROTECTED REGION END*/
    }
    void Intercept::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1458757170147) ENABLED START*/ //Add additional options here
        lastDistErr = 0;
        distIntErr = 0;

        lastRotErr = 0;
        rotIntErr = 0;
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1458757170147) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
