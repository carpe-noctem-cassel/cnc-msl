#include "Plans/GameStrategy/Other/DroppedBall1426694906399.h"
using namespace alica;
/*PROTECTED REGION ID(eph1426694906399) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:DroppedBall

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1426694906401

     */
    shared_ptr<UtilityFunction> UtilityFunction1426694906399::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1426694906399) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: DropBallType in Plan: DroppedBall

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : anychildsuccess 
     *
     * Plans in State: 				
     *   - Plan - (Name): DropBallType, (PlanID): 1426696396136 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1426694906401)
     *
     * States:
     *   - DropBallType (1426694906400)
     *   - NewSuccessState (1426696458333)
     *
     * Vars:
     */
    bool TransitionCondition1426696478377::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426696476530) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

//State: NewSuccessState in Plan: DroppedBall

}
