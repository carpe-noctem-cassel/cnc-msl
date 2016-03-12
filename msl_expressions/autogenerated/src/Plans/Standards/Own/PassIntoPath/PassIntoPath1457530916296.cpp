#include "Plans/Standards/Own/PassIntoPath/PassIntoPath1457530916296.h"
using namespace alica;
/*PROTECTED REGION ID(eph1457530916296) ENABLED START*/ //Add additional using directives here
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

     Task: StandardReceiver  -> EntryPoint-ID: 1457530953060

     Task: Blocker  -> EntryPoint-ID: 1457531047960

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
     *   - StandardReceiver (1238601842183) (Entrypoint: 1457530953060)
     *   - Blocker (1432209050494) (Entrypoint: 1457531047960)
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
        return false;
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
     *   - StandardReceiver (1238601842183) (Entrypoint: 1457530953060)
     *   - Blocker (1432209050494) (Entrypoint: 1457531047960)
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
     *   - StandardReceiver (1238601842183) (Entrypoint: 1457530953060)
     *   - Blocker (1432209050494) (Entrypoint: 1457531047960)
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
        return false;
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
     *   - StandardReceiver (1238601842183) (Entrypoint: 1457530953060)
     *   - Blocker (1432209050494) (Entrypoint: 1457531047960)
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
        return false;
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
     *   - StandardReceiver (1238601842183) (Entrypoint: 1457530953060)
     *   - Blocker (1432209050494) (Entrypoint: 1457531047960)
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
        return false;
        /*PROTECTED REGION END*/

    }

//State: NewSuccessState in Plan: PassIntoPath

}