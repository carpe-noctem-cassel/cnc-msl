#include "Plans/TestPlans/DribbleTestMOS/DribbleTestMaster1518866346673.h"
using namespace alica;
/*PROTECTED REGION ID(eph1518866346673) ENABLED START*/ //Add additional using directives here
#include <MSLWorldModel.h>
#include <Game.h>
#include <Rules.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:DribbleTestMaster

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1518866346675

     */
    shared_ptr<UtilityFunction> UtilityFunction1518866346673::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1518866346673) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Stop in Plan: DribbleTestMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : start pressed 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1518866346675)
     *
     * States:
     *   - Stop (1518866346674)
     *   - Start (1518866360499)
     *
     * Vars:
     */
    bool TransitionCondition1518866390521::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1518866388604) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Start);
        /*PROTECTED REGION END*/

    }

    //State: Start in Plan: DribbleTestMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : stop pressed 
     *
     * Plans in State: 				
     *   - Plan - (Name): TestDribbleMOS, (PlanID): 1518622787399 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1518866346675)
     *
     * States:
     *   - Stop (1518866346674)
     *   - Start (1518866360499)
     *
     * Vars:
     */
    bool TransitionCondition1518866391883::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1518866390610) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Stop);
        /*PROTECTED REGION END*/

    }

}
