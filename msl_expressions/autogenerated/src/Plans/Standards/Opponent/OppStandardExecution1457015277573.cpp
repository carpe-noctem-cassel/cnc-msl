#include "Plans/Standards/Opponent/OppStandardExecution1457015277573.h"
using namespace alica;
/*PROTECTED REGION ID(eph1457015277573) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:OppStandardExecution

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1457015277576

     */
    shared_ptr<UtilityFunction> UtilityFunction1457015277573::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1457015277573) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Position in Plan: OppStandardExecution

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Situation==Start 
     *
     * Plans in State: 				
     *   - Plan - (Name): OppStandardPositionType, (PlanID): 1457015361187 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1457015277576)
     *
     * States:
     *   - Position (1457015277575)
     *   - WatchBall (1457015292860)
     *   - NewSuccessState (1457015318562)
     *
     * Vars:
     */
    bool TransitionCondition1457015310255::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1457015308829) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::Start);
        /*PROTECTED REGION END*/

    }

    //State: WatchBall in Plan: OppStandardExecution

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : WatchBallMessage || 10Secs since start 
     *
     * Plans in State: 				
     *   - Plan - (Name): OppStandardWatchBallType, (PlanID): 1457015489608 				
     *   - Plan - (Name): TeamWatchBallDefault, (PlanID): 1457015565562 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1457015277576)
     *
     * States:
     *   - Position (1457015277575)
     *   - WatchBall (1457015292860)
     *   - NewSuccessState (1457015318562)
     *
     * Vars:
     */
    bool TransitionCondition1457015479684::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1457015478636) ENABLED START*/
        cout << "InState145" << endl;
        return rp->anyChildrenStatus(PlanStatus::Success) || wm->whiteBoard.getWatchBallMsg() != nullptr;
        /*PROTECTED REGION END*/

    }

//State: NewSuccessState in Plan: OppStandardExecution

}
