using namespace std;
#include "Plans/Attack/Wander.h"

/*PROTECTED REGION ID(inccpp1434716215423) ENABLED START*/ //Add additional includes here
#include "MSLFootballField.h"
#include "robotmovement/RobotMovement.h"
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1434716215423) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    Wander::Wander() :
            DomainBehaviour("Wander")
    {
        /*PROTECTED REGION ID(con1434716215423) ENABLED START*/ //Add additional options here
        msl::MSLFootballField* field = msl::MSLFootballField::getInstance();
        fieldLength = field->FieldLength;
        fieldWidth = field->FieldWidth;
        distToCorner = 2500;
        distToOutLine = 4000;
        firstTargetSet = false;
        EPSILON_RADIUS = 300.0;
        SLOW_DOWN_DISTANCE = 1200.0;
        maxTranslation = 4000.0;
        translation = 0.0;
        currentTargetPoint = make_shared < geometry::CNPoint2D > (0, 0);
        //default targetpoints
        targetPoints.resize(5);
        targetPoints[0] = make_shared < geometry::CNPoint2D
                > (-(fieldLength / 2 - distToCorner), fieldWidth / 2 - distToCorner);
        targetPoints[1] = make_shared < geometry::CNPoint2D
                > (-(fieldLength / 2 - distToCorner), -(fieldWidth / 2 - distToCorner));
        targetPoints[2] = make_shared < geometry::CNPoint2D > (0.0, 0.0);
        targetPoints[3] = make_shared < geometry::CNPoint2D
                > (fieldLength / 2 - distToCorner, fieldWidth / 2 - distToCorner);
        targetPoints[4] = make_shared < geometry::CNPoint2D
                > (fieldLength / 2 - distToCorner, -(fieldWidth / 2 - distToCorner));

        //drive into both opps corners
        targetPointsOwnCorner.resize(2);
        targetPointsOwnCorner[0] = make_shared < geometry::CNPoint2D
                > (fieldLength / 2 - distToCorner, fieldWidth / 2 - distToCorner);
        targetPointsOwnCorner[1] = make_shared < geometry::CNPoint2D
                > (fieldLength / 2 - distToCorner, -(fieldWidth / 2 - distToCorner));

        //drive into both own corners
        targetPointsOppCorner.resize(2);
        targetPointsOppCorner[0] = make_shared < geometry::CNPoint2D
                > (-(fieldLength / 2 - distToCorner), fieldWidth / 2 - distToCorner);
        targetPointsOppCorner[1] = make_shared < geometry::CNPoint2D
                > (-(fieldLength / 2 - distToCorner), -(fieldWidth / 2 - distToCorner));

        //drive to both own penaltyarea corners
        targetPointsOwnGoalKick.resize(2);
        targetPointsOwnGoalKick[0] = make_shared < geometry::CNPoint2D
                > (-(fieldLength / 2 - field->GoalInnerAreaWidth), field->GoalInnerAreaLength / 2);
        targetPointsOwnGoalKick[1] = make_shared < geometry::CNPoint2D
                > (-(fieldLength / 2 - field->GoalInnerAreaWidth), -field->GoalInnerAreaLength / 2);

        //drive to both opp penaltyarea corners
        targetPointsOppGoalKick.resize(2);
        targetPointsOppGoalKick[0] = make_shared < geometry::CNPoint2D
                > (fieldLength / 2 - field->GoalInnerAreaWidth, field->GoalInnerAreaLength / 2);
        targetPointsOppGoalKick[1] = make_shared < geometry::CNPoint2D
                > (fieldLength / 2 - field->GoalInnerAreaWidth, -field->GoalInnerAreaLength / 2);

        //points on side lines (distToOutline away)
        targetPointsThrowIn.resize(6);
        //left
        targetPointsThrowIn[0] = make_shared < geometry::CNPoint2D > (fieldLength / 4, fieldWidth / 2 - distToOutLine);
        targetPointsThrowIn[1] = make_shared < geometry::CNPoint2D > (0.0, fieldWidth / 2 - distToOutLine);
        targetPointsThrowIn[2] = make_shared < geometry::CNPoint2D > (-fieldLength / 4, fieldWidth / 2 - distToOutLine);
        //right
        targetPointsThrowIn[3] = make_shared < geometry::CNPoint2D
                > (fieldLength / 4, -(fieldWidth / 2 - distToOutLine));
        targetPointsThrowIn[4] = make_shared < geometry::CNPoint2D > (0.0, -(fieldWidth / 2 - distToOutLine));
        targetPointsThrowIn[5] = make_shared < geometry::CNPoint2D
                > (-fieldLength / 4, -(fieldWidth / 2 - distToOutLine));
        /*PROTECTED REGION END*/
    }
    Wander::~Wander()
    {
        /*PROTECTED REGION ID(dcon1434716215423) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void Wander::run(void* msg)
    {
        /*PROTECTED REGION ID(run1434716215423) ENABLED START*/ //Add additional options here
        shared_ptr < geometry::CNPosition > ownPosition = wm->rawSensorData.getOwnPositionVision();
        msl::Situation situation = wm->game.getCurrentSituation();
        if (!firstTargetSet)
        {
            setFirstTargetPoint(situation);
            firstTargetSet = true;
        }
        shared_ptr < geometry::CNPoint2D > currentEgoTarget = currentTargetPoint->alloToEgo(*ownPosition);

        if (currentEgoTarget->length() < EPSILON_RADIUS)
        {
            if (situation == msl::Situation::OwnCorner)
            {
                currentTargetPoint = targetPointsOwnCorner[rand() % 2];
            }
            else if (situation == msl::Situation::OppCorner)
            {
                currentTargetPoint = targetPointsOppCorner[rand() % 2];
            }
            else if (situation == msl::Situation::OwnGoalkick)
            {
                currentTargetPoint = targetPointsOwnGoalKick[rand() % 2];
            }
            else if (situation == msl::Situation::OppGoalkick)
            {
                currentTargetPoint = targetPointsOppGoalKick[rand() % 2];
            }

            else if (situation == msl::Situation::OwnThrowin || situation == msl::Situation::OppThrowin)
            {
                currentTargetPoint = targetPointsThrowIn[rand() % 7];
            }
            else
            {
                currentTargetPoint = targetPoints[rand() % 6];
            }
        }

        shared_ptr < geometry::CNPoint2D > targetPoint = currentTargetPoint->alloToEgo(*ownPosition);

        double targetDistance = targetPoint->length();

        translation = maxTranslation;

        if (targetDistance < SLOW_DOWN_DISTANCE)
        {
            translation = targetDistance;
        }

        MotionControl mc = msl::RobotMovement::moveToPointCarefully(targetPoint, targetPoint, 0);
        send(mc);

        /*PROTECTED REGION END*/
    }
    void Wander::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1434716215423) ENABLED START*/ //Add additional options here
        firstTargetSet = false;
        /*PROTECTED REGION END*/
    }
    /*PROTECTED REGION ID(methods1434716215423) ENABLED START*/ //Add additional methods here
    void Wander::setFirstTargetPoint(msl::Situation situation)
    {
        if (situation == msl::Situation::OwnCorner)
        {
            currentTargetPoint = targetPointsOwnCorner[rand() % 2];
        }
        else if (situation == msl::Situation::OppCorner)
        {
            currentTargetPoint = targetPointsOppCorner[rand() % 2];
        }
        else if (situation == msl::Situation::OwnGoalkick)
        {
            currentTargetPoint = targetPointsOwnGoalKick[rand() % 2];
        }
        else if (situation == msl::Situation::OppGoalkick)
        {
            currentTargetPoint = targetPointsOppGoalKick[rand() % 2];
        }

        else if (situation == msl::Situation::OwnThrowin || situation == msl::Situation::OppThrowin)
        {
            currentTargetPoint = targetPointsThrowIn[rand() % 7];
        }
        else
        {
            currentTargetPoint = targetPoints[rand() % 6];
        }
    }
/*PROTECTED REGION END*/
} /* namespace alica */
