#include "Plans/GenericStandards/GenericOwnStandards1430924951132.h"
using namespace alica;
/*PROTECTED REGION ID(eph1430924951132) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:GenericOwnStandards

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1430925626532

     Task: Keeper  -> EntryPoint-ID: 1431523920444

     */
    shared_ptr<UtilityFunction> UtilityFunction1430924951132::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1430924951132) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Dummy in Plan: GenericOwnStandards

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation = own throw in 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1430925918456::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1430925917001) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::OwnThrowin);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation = own kick off 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1430925919738::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1430925918585) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::OwnKickoff);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation = own goal kick 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1430925921267::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1430925919866) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::OwnGoalkick);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation = own penalty kick 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1430925922740::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1430925921331) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::OwnPenalty);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation = own free kick 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1430925924055::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1430925922843) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::OwnFreekick);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation = own corner kick 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1430925925549::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1430925924151) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::OwnCorner);
        /*PROTECTED REGION END*/

    }

    //State: OwnThrowIn in Plan: GenericOwnStandards

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any child success 
     *
     * Plans in State: 				
     *   - Plan - (Name): GenericExecute, (PlanID): 1431522123418 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1430925962659::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1430925960854) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : EgoBallPosition==nullptr; 
     *
     * Plans in State: 				
     *   - Plan - (Name): GenericExecute, (PlanID): 1431522123418 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1458555223252::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1458555221149) ENABLED START*/
        return wm->ball.getEgoBallPosition() == nullptr;
        /*PROTECTED REGION END*/

    }

    //State: OwnKickOff in Plan: GenericOwnStandards

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any child success | any child failed 
     *
     * Plans in State: 				
     *   - Plan - (Name): OwnKickOff, (PlanID): 1438785270887 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1430925965501::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1430925962882) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : EgoBallPosition==nullptr; 
     *
     * Plans in State: 				
     *   - Plan - (Name): OwnKickOff, (PlanID): 1438785270887 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1458555220837::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1458555218949) ENABLED START*/
        return wm->ball.getEgoBallPosition() == nullptr;
        /*PROTECTED REGION END*/

    }

    //State: OwnGoalKick in Plan: GenericOwnStandards

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any child success 
     *
     * Plans in State: 				
     *   - Plan - (Name): GenericExecute, (PlanID): 1431522123418 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1430925967520::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1430925965662) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : EgoBall=nullptr 
     *
     * Plans in State: 				
     *   - Plan - (Name): GenericExecute, (PlanID): 1431522123418 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1458555218469::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1458555214716) ENABLED START*/
        return wm->ball.getEgoBallPosition() == nullptr;
        /*PROTECTED REGION END*/

    }

    //State: OwnFreeKick in Plan: GenericOwnStandards

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any child success 
     *
     * Plans in State: 				
     *   - Plan - (Name): GenericExecute, (PlanID): 1431522123418 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1430925972838::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1430925971330) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : EgoBallPosition==nullptr; 
     *
     * Plans in State: 				
     *   - Plan - (Name): GenericExecute, (PlanID): 1431522123418 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1458555207377::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1458555205351) ENABLED START*/
        return wm->ball.getEgoBallPosition() == nullptr;
        /*PROTECTED REGION END*/

    }

    //State: OwnCornerKick in Plan: GenericOwnStandards

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any child success 
     *
     * Plans in State: 				
     *   - Plan - (Name): GenericExecute, (PlanID): 1431522123418 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1430925975558::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1430925973111) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : EgoBallPosition==nullptr; 
     *
     * Plans in State: 				
     *   - Plan - (Name): GenericExecute, (PlanID): 1431522123418 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1458555210443::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1458555207649) ENABLED START*/
        return wm->ball.getEgoBallPosition() == nullptr;
        /*PROTECTED REGION END*/

    }

    //State: OwnPenaltyKick in Plan: GenericOwnStandards

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any child success 
     *
     * Plans in State: 				
     *   - Plan - (Name): OwnPenalty, (PlanID): 1431525185678 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1430925970967::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1430925967608) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: Success in Plan: GenericOwnStandards

    //State: KeepGoal in Plan: GenericOwnStandards

    //State: Wander in Plan: GenericOwnStandards

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : EgoBallPosition!=nullptr && Situation=OwnCorner; 
     *
     * Plans in State: 				
     *   - Plan - (Name): WanderPlan, (PlanID): 1458553921358 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1458555791025::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1458555788972) ENABLED START*/
        return wm->ball.getEgoBallPosition() != nullptr && wm->game.checkSituation(msl::Situation::OwnCorner);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : EgoBallPosition!=nullptr && Situation=OwnFreeKick; 
     *
     * Plans in State: 				
     *   - Plan - (Name): WanderPlan, (PlanID): 1458553921358 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1458555821886::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1458555819730) ENABLED START*/
        return wm->ball.getEgoBallPosition() != nullptr && wm->game.checkSituation(msl::Situation::OwnFreekick);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : EgoBallPosition!=nullptr && Situation=OwnGoalK; 
     *
     * Plans in State: 				
     *   - Plan - (Name): WanderPlan, (PlanID): 1458553921358 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1458555856023::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1458555853125) ENABLED START*/
        return wm->ball.getEgoBallPosition() != nullptr && wm->game.checkSituation(msl::Situation::OwnGoalkick);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : EgoBallPosition!=nullptr && Situation=OwnThrowin; 
     *
     * Plans in State: 				
     *   - Plan - (Name): WanderPlan, (PlanID): 1458553921358 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1458555881015::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1458555879137) ENABLED START*/
        return wm->ball.getEgoBallPosition() != nullptr && wm->game.checkSituation(msl::Situation::OwnThrowin);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : EgoBallPosition!=nullptr && Situation=OwnKickOff; 
     *
     * Plans in State: 				
     *   - Plan - (Name): WanderPlan, (PlanID): 1458553921358 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1430925626532)
     *   - Keeper (1221754402444) (Entrypoint: 1431523920444)
     *
     * States:
     *   - Dummy (1430924951133)
     *   - OwnThrowIn (1430925718512)
     *   - OwnKickOff (1430925736746)
     *   - OwnGoalKick (1430925743739)
     *   - OwnFreeKick (1430925751875)
     *   - OwnCornerKick (1430925759928)
     *   - OwnPenaltyKick (1430925774870)
     *   - Success (1430925945981)
     *   - KeepGoal (1431523938514)
     *   - Wander (1458555183582)
     *
     * Vars:
     */
    bool TransitionCondition1458555898277::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1458555896457) ENABLED START*/
        return wm->ball.getEgoBallPosition() != nullptr && wm->game.checkSituation(msl::Situation::OwnKickoff);
        /*PROTECTED REGION END*/

    }

}
