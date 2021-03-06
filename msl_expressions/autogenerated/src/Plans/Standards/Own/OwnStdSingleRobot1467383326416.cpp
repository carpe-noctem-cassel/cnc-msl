#include "Plans/Standards/Own/OwnStdSingleRobot1467383326416.h"
using namespace alica;
/*PROTECTED REGION ID(eph1467383326416) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:OwnStdSingleRobot

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1467384083267

     */
    shared_ptr<UtilityFunction> UtilityFunction1467383326416::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1467383326416) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Position in Plan: OwnStdSingleRobot

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation start 
     *
     * Plans in State: 				
     *   - Plan - (Name): StdAlignSingleRobotDefault, (PlanID): 1467385818398 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1467384083267)
     *
     * States:
     *   - Position (1467384083266)
     *   - GetBall (1467384130052)
     *   - Kick (1467384133137)
     *   - NewSuccessState (1467384222671)
     *
     * Vars:
     */
    bool TransitionCondition1467384214949::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1467384202351) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

    //State: GetBall in Plan: OwnStdSingleRobot

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : haveball 
     *
     * Plans in State: 				
     *   - Plan - (Name): StandardAlignAndGrabDefault, (PlanID): 1467436134025 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1467384083267)
     *
     * States:
     *   - Position (1467384083266)
     *   - GetBall (1467384130052)
     *   - Kick (1467384133137)
     *   - NewSuccessState (1467384222671)
     *
     * Vars:
     */
    bool TransitionCondition1467384216416::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1467384215357) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

    //State: Kick in Plan: OwnStdSingleRobot

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : kicked 
     *
     * Plans in State: 				
     *   - Plan - (Name): SingleRobotKickIntoOppHalfDefault, (PlanID): 1467436318706 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1467384083267)
     *
     * States:
     *   - Position (1467384083266)
     *   - GetBall (1467384130052)
     *   - Kick (1467384133137)
     *   - NewSuccessState (1467384222671)
     *
     * Vars:
     */
    bool TransitionCondition1467384969800::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1467384963126) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

//State: NewSuccessState in Plan: OwnStdSingleRobot

}
