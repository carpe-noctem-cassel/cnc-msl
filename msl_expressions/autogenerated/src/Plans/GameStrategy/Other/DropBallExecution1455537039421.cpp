#include "Plans/GameStrategy/Other/DropBallExecution1455537039421.h"
using namespace alica;
/*PROTECTED REGION ID(eph1455537039421) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:DropBallExecution

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1455537039423

     */
    shared_ptr<UtilityFunction> UtilityFunction1455537039421::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1455537039421) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: DoSomethingCool in Plan: DropBallExecution

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : true 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1455537039423)
     *
     * States:
     *   - DoSomethingCool (1455537039422)
     *   - NewSuccessState (1455537179349)
     *
     * Vars:
     */
    bool TransitionCondition1455537184881::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1455537182943) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/

    }

//State: NewSuccessState in Plan: DropBallExecution

}
