#include "Plans/Standards/Own/PassIntoPath/PassIntoPath1457530916296.h"
using namespace alica;
/*PROTECTED REGION ID(eph1457530916296) ENABLED START*/ //Add additional using directives here
#include "engine/Assignment.h"
#include "engine/collections/StateCollection.h"
#include <MSLWorldModel.h>
#include <WhiteBoard.h>
#include <Game.h>
#include <Ball.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:PassIntoPath

    //Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) :  

    /* 
     * Available Vars:
     *	- passGoalX (1457531196542)
     *	- passGoalY (1457531200123)
     */
    bool RunTimeCondition1457531039142::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1457531039142) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/
    }

    /* generated comment
     
     Task: ExecuteStandard  -> EntryPoint-ID: 1457530916298

     Task: ReceiveStandard  -> EntryPoint-ID: 1457530953060

     Task: Block  -> EntryPoint-ID: 1457531047960

     */
    shared_ptr<UtilityFunction> UtilityFunction1457530916296::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1457530916296) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Align in Plan: PassIntoPath

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Situation==Start 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 				
     *   - Plan - (Name): StandardAlignToPassPosDefault, (PlanID): 1457532300654 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1457530916298)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1457530953060)
     *   - Block (1461237765109) (Entrypoint: 1457531047960)
     *
     * States:
     *   - Align (1457530916297)
     *   - Align (1457531111752)
     *   - Block (1457531122593)
     *   - GrabBall (1457531267822)
     *   - PassKick (1457531281152)
     *   - SpatialDefend (1457531293259)
     *   - ReceiveAtTarget (1457531324804)
     *   - NewSuccessState (1457531345727)
     *
     * Vars:
     */
    bool TransitionCondition1457531305067::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1457531303657) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Start);
        /*PROTECTED REGION END*/

    }

    //State: Align in Plan: PassIntoPath

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Passee in SpatialDefend state || PassMsg Received 
     *
     * Plans in State: 				
     *   - Plan - (Name): ReceivePassIntoPathGenericDefault, (PlanID): 1457531594373 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1457530916298)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1457530953060)
     *   - Block (1461237765109) (Entrypoint: 1457531047960)
     *
     * States:
     *   - Align (1457530916297)
     *   - Align (1457531111752)
     *   - Block (1457531122593)
     *   - GrabBall (1457531267822)
     *   - PassKick (1457531281152)
     *   - SpatialDefend (1457531293259)
     *   - ReceiveAtTarget (1457531324804)
     *   - NewSuccessState (1457531345727)
     *
     * Vars:
     */
    bool TransitionCondition1457531342108::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1457531340791) ENABLED START*/
        auto pm = wm->whiteBoard->getPassMsg();
        if ((pm != nullptr && pm->senderID > 0)
                || rp->getAssignment()->getRobotStateMapping()->getRobotsInState(1457531293259).size() > 0)
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: Block in Plan: PassIntoPath

    //State: GrabBall in Plan: PassIntoPath

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Aligned or 9s 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 				
     *   - Plan - (Name): StandardAlignToGenericDefault, (PlanID): 1457531639350 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1457530916298)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1457530953060)
     *   - Block (1461237765109) (Entrypoint: 1457531047960)
     *
     * States:
     *   - Align (1457530916297)
     *   - Align (1457531111752)
     *   - Block (1457531122593)
     *   - GrabBall (1457531267822)
     *   - PassKick (1457531281152)
     *   - SpatialDefend (1457531293259)
     *   - ReceiveAtTarget (1457531324804)
     *   - NewSuccessState (1457531345727)
     *
     * Vars:
     */
    bool TransitionCondition1457531315717::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1457531307265) ENABLED START*/
        return this->isTimeOut(90000000000, wm->game->getTimeSinceStart(), rp);
        /*PROTECTED REGION END*/

    }

    //State: PassKick in Plan: PassIntoPath

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Subplan Successful (Kicked) 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 				
     *   - Plan - (Name): PassKickIntoPathDefault, (PlanID): 1457531685581 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1457530916298)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1457530953060)
     *   - Block (1461237765109) (Entrypoint: 1457531047960)
     *
     * States:
     *   - Align (1457530916297)
     *   - Align (1457531111752)
     *   - Block (1457531122593)
     *   - GrabBall (1457531267822)
     *   - PassKick (1457531281152)
     *   - SpatialDefend (1457531293259)
     *   - ReceiveAtTarget (1457531324804)
     *   - NewSuccessState (1457531345727)
     *
     * Vars:
     */
    bool TransitionCondition1457531317223::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1457531315807) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: SpatialDefend in Plan: PassIntoPath

    //State: ReceiveAtTarget in Plan: PassIntoPath

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : 10s after start || Ball GetBall is near Goal || to far away from origin 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1457530916298)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1457530953060)
     *   - Block (1461237765109) (Entrypoint: 1457531047960)
     *
     * States:
     *   - Align (1457530916297)
     *   - Align (1457531111752)
     *   - Block (1457531122593)
     *   - GrabBall (1457531267822)
     *   - PassKick (1457531281152)
     *   - SpatialDefend (1457531293259)
     *   - ReceiveAtTarget (1457531324804)
     *   - NewSuccessState (1457531345727)
     *
     * Vars:
     */
    bool TransitionCondition1457531352472::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1457531350730) ENABLED START*/
        auto alloBall = wm->ball->getAlloBallPosition();
        auto egoBall = wm->ball->getEgoBallPosition();
        if (alloBall == nullptr)
            return true;

        auto pm = wm->whiteBoard->getPassMsg();
        bool ballMovedToFar = false;
        if (pm != nullptr && pm->senderID > 0)
        {
            auto origin = make_shared < geometry::CNPoint2D > (pm->origin.x, pm->origin.y);
            ballMovedToFar = (origin - alloBall)->length() > 1000;
        }
        if (egoBall != nullptr)
        {
            if (egoBall->length() < 1700)
                return true;
        }

        double ballangle = egoBall->angleTo();
        double part = 0.6;
        return ((ballangle > M_PI * part) || (ballangle < -M_PI * part) || ballMovedToFar);
        //return this->isTimeOut(95000000000, wm->game.getTimeSinceStart(), rp);
        /*PROTECTED REGION END*/

    }

//State: NewSuccessState in Plan: PassIntoPath

}
