#include "Plans/GenericStandards/GenericDefend1432133473779.h"
using namespace alica;
/*PROTECTED REGION ID(eph1432133473779) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:GenericDefend

    /* generated comment
     
     Task: Defend  -> EntryPoint-ID: 1432209644156

     Task: Blocker  -> EntryPoint-ID: 1432209646142

     */
    shared_ptr<UtilityFunction> UtilityFunction1432133473779::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1432133473779) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Block in Plan: GenericDefend

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment :  
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - Defend (1225115406909) (Entrypoint: 1432209644156)
     *   - Blocker (1432209050494) (Entrypoint: 1432209646142)
     *
     * States:
     *   - Block (1432133473780)
     *   - Defend (1432134414694)
     *   - Success (1432134598332)
     *
     * Vars:
     */
    bool TransitionCondition1432134618673::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1432134616763) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

    //State: Defend in Plan: GenericDefend

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : GetBall 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - Defend (1225115406909) (Entrypoint: 1432209644156)
     *   - Blocker (1432209050494) (Entrypoint: 1432209646142)
     *
     * States:
     *   - Block (1432133473780)
     *   - Defend (1432134414694)
     *   - Success (1432134598332)
     *
     * Vars:
     */
    bool TransitionCondition1432134616532::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1432134614588) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

//State: Success in Plan: GenericDefend

}