#include "Plans/Attack/TestPlans/DuelTestMaster1454506180437.h"
using namespace alica;
/*PROTECTED REGION ID(eph1454506180437) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:DuelTestMaster

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1454506180439

     */
    shared_ptr<UtilityFunction> UtilityFunction1454506180437::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1454506180437) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Stop in Plan: DuelTestMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == start 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1454506180439)
     *
     * States:
     *   - Stop (1454506180438)
     *   - Duel (1454506213756)
     *
     * Vars:
     */
    bool TransitionCondition1454506224420::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454506223310) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::Start);
        /*PROTECTED REGION END*/

    }

    //State: Duel in Plan: DuelTestMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): Duel, (PlanID): 1450178655416 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1454506180439)
     *
     * States:
     *   - Stop (1454506180438)
     *   - Duel (1454506213756)
     *
     * Vars:
     */
    bool TransitionCondition1454506235490::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1454506234662) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::Stop);
        /*PROTECTED REGION END*/

    }

}