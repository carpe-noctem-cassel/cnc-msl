#include "Plans/Goalie/Test/GoalieDefault1447254438614.h"
using namespace alica;
/*PROTECTED REGION ID(eph1447254438614) ENABLED START*/ //Add additional using directives here
#include "robotmovement/RobotMovement.h"
#include <cmath>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:GoalieDefault

    /* generated comment
     
     Task: Keeper  -> EntryPoint-ID: 1447254438616

     */
    shared_ptr<UtilityFunction> UtilityFunction1447254438614::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1447254438614) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: DriveToGoal in Plan: GoalieDefault

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Goalie position calibrated succesfully 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToGoalDefault, (PlanID): 1447863442558 
     *
     * Tasks: 
     *   - Keeper (1221754402444) (Entrypoint: 1447254438616)
     *
     * States:
     *   - DriveToGoal (1447254438615)
     *   - WatchBall (1447255061404)
     *   - DriveToBall (1447256447585)
     *   - Pass (1447256481745)
     *
     * Vars:
     */
    bool TransitionCondition1447255447830::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1447255446546) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: WatchBall in Plan: GoalieDefault

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Ball may have been blocked and is now resting inside of goal area 
     *
     * Plans in State: 				
     *   - Plan - (Name): BlockBallDefault, (PlanID): 1447863463711 				
     *   - Plan - (Name): WatchBallDefault, (PlanID): 1447863472667 
     *
     * Tasks: 
     *   - Keeper (1221754402444) (Entrypoint: 1447254438616)
     *
     * States:
     *   - DriveToGoal (1447254438615)
     *   - WatchBall (1447255061404)
     *   - DriveToBall (1447256447585)
     *   - Pass (1447256481745)
     *
     * Vars:
     */
    bool TransitionCondition1447259463769::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1447259462162) ENABLED START*/

    	double ballX = wm->ball.getAlloBallPosition()->x;
    	double ballY = wm->ball.getEgoBallPosition()->y;
    	shared_ptr<geometry::CNPosition> me = wm->rawSensorData.getOwnPositionVision();
    	std::shared_ptr<geometry::CNVelocity2D> ballV = wm->ball.getEgoBallVelocity();

    	std::shared_ptr<geometry::CNPoint2D> uLGoalArea = MSLFootballField::posULOwnGoalArea();
    	double uLX = uLGoalArea->x;
    	double uLY = uLGoalArea->y;
    	int output = (ballV->x == 0 && ballV->y == 0) && ballX < uLX && (ballY < uLY && ballY > -uLY);
    	// TODO: ball velocity seems to be wrong.... BUG?
    	//cout << "######" << endl;
    	//cout << "ballVZ: " << ballV->z << " ballVY: " << ballV->y << " ballVX: " << ballV->x << endl;
    	//cout << "######" << endl;

    	return  output;
        /*PROTECTED REGION END*/

    }

    //State: DriveToBall in Plan: GoalieDefault

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Ball is reached and in front of the kickplate 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToBallDefault, (PlanID): 1447863503279 
     *
     * Tasks: 
     *   - Keeper (1221754402444) (Entrypoint: 1447254438616)
     *
     * States:
     *   - DriveToGoal (1447254438615)
     *   - WatchBall (1447255061404)
     *   - DriveToBall (1447256447585)
     *   - Pass (1447256481745)
     *
     * Vars:
     */
    bool TransitionCondition1447256488686::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1447256487026) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

    //State: Pass in Plan: GoalieDefault

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Ball has been played 
     *
     * Plans in State: 				
     *   - Plan - (Name): KickToDirectionDefault, (PlanID): 1447863487000 
     *
     * Tasks: 
     *   - Keeper (1221754402444) (Entrypoint: 1447254438616)
     *
     * States:
     *   - DriveToGoal (1447254438615)
     *   - WatchBall (1447255061404)
     *   - DriveToBall (1447256447585)
     *   - Pass (1447256481745)
     *
     * Vars:
     */
    bool TransitionCondition1447256495415::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1447256488872) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

}
