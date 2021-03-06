#include "Plans/Defence/MidfieldBlock1458033620834.h"
using namespace alica;
/*PROTECTED REGION ID(eph1458033620834) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:MidfieldBlock

    //Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) :  

    /* 
     * Available Vars:
     *	- X (1458034250626)
     *	- Y (1458034254267)
     */
    bool RunTimeCondition1458033723845::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1458033723845) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/
    }

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1458033636229

     */
    shared_ptr<UtilityFunction> UtilityFunction1458033620834::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1458033620834) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: MidfieldBlock in Plan: MidfieldBlock

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment :  
     *
     * Plans in State: 				
     *   - Plan - (Name): OneGernericInGameBlockerDefault, (PlanID): 1458034300406 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1458033636229)
     *
     * States:
     *   - MidfieldBlock (1458033636228)
     *   - BlockingFinished (1458033701713)
     *
     * Vars:
     */
    bool TransitionCondition1458033705136::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1458033704233) ENABLED START*/
        return rp->anyChildrenStatus(alica::PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

//State: BlockingFinished in Plan: MidfieldBlock

}
