#include "Plans/Standards/Own/FreeKick/OwnFreeKickInOppHalf1464531946023.h"
using namespace alica;
/*PROTECTED REGION ID(eph1464531946023) ENABLED START*/ //Add additional using directives here
#include "engine/model/Plan.h"
#include "engine/Assignment.h"
#include "engine/collections/StateCollection.h"
#include "BallXIntervall.h"
#include <MSLWorldModel.h>
#include <MSLFootballField.h>
#include <Game.h>
#include <RawSensorData.h>
#include <Ball.h>
#include <Rules.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:OwnFreeKickInOppHalf

    //Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) :  

    /* 
     * Available Vars:
     */
    bool RunTimeCondition1467206311808::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1467206311808) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/
    }

    /* generated comment
     
     Task: ExecuteStandard  -> EntryPoint-ID: 1464531946025

     Task: ReceiveStandard  -> EntryPoint-ID: 1464532126334

     Task: StandInsideOppPenalty  -> EntryPoint-ID: 1464532128302

     Task: StandCloseToOppPenalty  -> EntryPoint-ID: 1464532130252

     */
    shared_ptr<UtilityFunction> UtilityFunction1464531946023::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1464531946023) ENABLED START*/

        vector<long> entryPoints;

        entryPoints.push_back(1464531946025); // ExecuteStandard
        entryPoints.push_back(1464532126334); // ReceiveStandard
        entryPoints.push_back(1464532128302); // StandInsideOppPenalty
        entryPoints.push_back(1464532130252); // StandCloseToOppPenalty

//        double angle = 75 * M_PI / 180; // nice angle to shoot on the goal

//        double x = ((msl::MSLWorldModel::get()->field->getFieldWidth() / 2.0) / atan(angle)) - 2300;
        BallXIntervall* us = new BallXIntervall(
                4.0,
                "OwnFreeKickInOppHalf",
                2,
                entryPoints,
                0.0,
                msl::MSLWorldModel::get()->field->getFieldLength() / 2
                        - 0.75 * msl::MSLWorldModel::get()->field->getPenaltyAreaLength(),
                2300.0);
        list<USummand*> utilSummands;
        utilSummands.push_back(us);
        shared_ptr < UtilityFunction > function = make_shared < UtilityFunction
                > ("OwnFreeKickInOppHalfTest", utilSummands, 0.1, 0.2, plan);
        return function;

        /*PROTECTED REGION END*/
    }

    //State: PositionExecutor in Plan: OwnFreeKickInOppHalf

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : (child success && start) || (start && timeSinceStart > emergencyExecute) 
     *
     * Plans in State: 				
     *   - Plan - (Name): StandardAlignToPointExecutor, (PlanID): 1435155363994 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 				
     *   - Plan - (Name): StandardActuateDefault, (PlanID): 1435766278023 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1464531946025)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1464532126334)
     *   - StandInsideOppPenalty (1464532449309) (Entrypoint: 1464532128302)
     *   - StandCloseToOppPenalty (1464864263733) (Entrypoint: 1464532130252)
     *
     * States:
     *   - PositionExecutor (1464535161175)
     *   - PositionReceiver (1464535169536)
     *   - GrabBall (1464535201681)
     *   - Pass (1464535219397)
     *   - Receive (1464535253598)
     *   - Shoot (1464535263395)
     *   - PositionInsideOppPenalty (1464535682818)
     *   - PositionCloseToOppPenalty (1464535706293)
     *   - Success (1464785222776)
     *   - Wait/MoveOutOfWay (1464785237103)
     *
     * Vars:
     */
    bool TransitionCondition1464778511333::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1464778510115) ENABLED START*/
        return (rp->anyChildrenStatus(PlanStatus::Success) && wm->game->checkSituation(msl::Situation::Start))
                || (wm->game->checkSituation(msl::Situation::Start)
                        && (this->isTimeOut(this->timeUntilEmergencyExecute, wm->game->getTimeSinceStart(), rp)));
        /*PROTECTED REGION END*/

    }

    //State: PositionReceiver in Plan: OwnFreeKickInOppHalf

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : aligned && executor in wait 
     *
     * Plans in State: 				
     *   - Plan - (Name): PositionReceiverFreeKickOppHalfDefault, (PlanID): 1464780824372 				
     *   - Plan - (Name): ShovelSelectHighKick, (PlanID): 1435156811453 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1464531946025)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1464532126334)
     *   - StandInsideOppPenalty (1464532449309) (Entrypoint: 1464532128302)
     *   - StandCloseToOppPenalty (1464864263733) (Entrypoint: 1464532130252)
     *
     * States:
     *   - PositionExecutor (1464535161175)
     *   - PositionReceiver (1464535169536)
     *   - GrabBall (1464535201681)
     *   - Pass (1464535219397)
     *   - Receive (1464535253598)
     *   - Shoot (1464535263395)
     *   - PositionInsideOppPenalty (1464535682818)
     *   - PositionCloseToOppPenalty (1464535706293)
     *   - Success (1464785222776)
     *   - Wait/MoveOutOfWay (1464785237103)
     *
     * Vars:
     */
    bool TransitionCondition1464778515331::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1464778513652) ENABLED START*/
//        return rp->anyChildrenStatus(PlanStatus::Success)
//                && rp->getAssignment()->getRobotStateMapping()->getRobotsInState(1464785237103).size() > 0;
        return rp->getAssignment()->getRobotStateMapping()->getRobotsInState(1464785237103).size() > 0;
        /*PROTECTED REGION END*/

    }

    //State: GrabBall in Plan: OwnFreeKickInOppHalf

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : haveBall 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 				
     *   - Plan - (Name): StandardActuateDefault, (PlanID): 1435766278023 				
     *   - Plan - (Name): StandardAlignAndGrabOFKIOH, (PlanID): 1466861369486 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1464531946025)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1464532126334)
     *   - StandInsideOppPenalty (1464532449309) (Entrypoint: 1464532128302)
     *   - StandCloseToOppPenalty (1464864263733) (Entrypoint: 1464532130252)
     *
     * States:
     *   - PositionExecutor (1464535161175)
     *   - PositionReceiver (1464535169536)
     *   - GrabBall (1464535201681)
     *   - Pass (1464535219397)
     *   - Receive (1464535253598)
     *   - Shoot (1464535263395)
     *   - PositionInsideOppPenalty (1464535682818)
     *   - PositionCloseToOppPenalty (1464535706293)
     *   - Success (1464785222776)
     *   - Wait/MoveOutOfWay (1464785237103)
     *
     * Vars:
     */
    bool TransitionCondition1464778513499::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1464778511430) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);;
        /*PROTECTED REGION END*/

    }

    //State: Pass in Plan: OwnFreeKickInOppHalf

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : lostBall 
     *
     * Plans in State: 				
     *   - Plan - (Name): StandardPassDefault, (PlanID): 1435760175843 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1464531946025)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1464532126334)
     *   - StandInsideOppPenalty (1464532449309) (Entrypoint: 1464532128302)
     *   - StandCloseToOppPenalty (1464864263733) (Entrypoint: 1464532130252)
     *
     * States:
     *   - PositionExecutor (1464535161175)
     *   - PositionReceiver (1464535169536)
     *   - GrabBall (1464535201681)
     *   - Pass (1464535219397)
     *   - Receive (1464535253598)
     *   - Shoot (1464535263395)
     *   - PositionInsideOppPenalty (1464535682818)
     *   - PositionCloseToOppPenalty (1464535706293)
     *   - Success (1464785222776)
     *   - Wait/MoveOutOfWay (1464785237103)
     *
     * Vars:
     */
    bool TransitionCondition1464783506322::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1464783504464) ENABLED START*/
        return !wm->ball->haveBall();
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : pass success 
     *
     * Plans in State: 				
     *   - Plan - (Name): StandardPassDefault, (PlanID): 1435760175843 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1464531946025)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1464532126334)
     *   - StandInsideOppPenalty (1464532449309) (Entrypoint: 1464532128302)
     *   - StandCloseToOppPenalty (1464864263733) (Entrypoint: 1464532130252)
     *
     * States:
     *   - PositionExecutor (1464535161175)
     *   - PositionReceiver (1464535169536)
     *   - GrabBall (1464535201681)
     *   - Pass (1464535219397)
     *   - Receive (1464535253598)
     *   - Shoot (1464535263395)
     *   - PositionInsideOppPenalty (1464535682818)
     *   - PositionCloseToOppPenalty (1464535706293)
     *   - Success (1464785222776)
     *   - Wait/MoveOutOfWay (1464785237103)
     *
     * Vars:
     */
    bool TransitionCondition1464785252648::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1464785250936) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: Receive in Plan: OwnFreeKickInOppHalf

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : received pass 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShovelSelectHighKick, (PlanID): 1435156811453 				
     *   - Plan - (Name): InterceptDefault, (PlanID): 1458757193843 				
     *   - Plan - (Name): StandardActuateDefault, (PlanID): 1435766278023 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1464531946025)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1464532126334)
     *   - StandInsideOppPenalty (1464532449309) (Entrypoint: 1464532128302)
     *   - StandCloseToOppPenalty (1464864263733) (Entrypoint: 1464532130252)
     *
     * States:
     *   - PositionExecutor (1464535161175)
     *   - PositionReceiver (1464535169536)
     *   - GrabBall (1464535201681)
     *   - Pass (1464535219397)
     *   - Receive (1464535253598)
     *   - Shoot (1464535263395)
     *   - PositionInsideOppPenalty (1464535682818)
     *   - PositionCloseToOppPenalty (1464535706293)
     *   - Success (1464785222776)
     *   - Wait/MoveOutOfWay (1464785237103)
     *
     * Vars:
     */
    bool TransitionCondition1464778516153::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1464778515443) ENABLED START*/
        return wm->ball->haveBall()
                || this->isTimeOut(this->rules->getStandbyTime() * 0.75, rp->getStateStartTime(), rp);
        /*PROTECTED REGION END*/

    }

    //State: Shoot in Plan: OwnFreeKickInOppHalf

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : shot successfully 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShovelSelectHighKick, (PlanID): 1435156811453 				
     *   - Plan - (Name): AlignFreeGoalSpaceDefault, (PlanID): 1467039882734 				
     *   - Plan - (Name): CheckGoalKickIgnoreGoalie, (PlanID): 1467265292648 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1464531946025)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1464532126334)
     *   - StandInsideOppPenalty (1464532449309) (Entrypoint: 1464532128302)
     *   - StandCloseToOppPenalty (1464864263733) (Entrypoint: 1464532130252)
     *
     * States:
     *   - PositionExecutor (1464535161175)
     *   - PositionReceiver (1464535169536)
     *   - GrabBall (1464535201681)
     *   - Pass (1464535219397)
     *   - Receive (1464535253598)
     *   - Shoot (1464535263395)
     *   - PositionInsideOppPenalty (1464535682818)
     *   - PositionCloseToOppPenalty (1464535706293)
     *   - Success (1464785222776)
     *   - Wait/MoveOutOfWay (1464785237103)
     *
     * Vars:
     */
    bool TransitionCondition1464785280406::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1464785278735) ENABLED START*/
        return this->isTimeOut(this->rules->getStandbyTime() * 0.75, rp->getStateStartTime(), rp)
                || *wm->ball->getOppBallPossession();
        /*PROTECTED REGION END*/

    }

//State: PositionInsideOppPenalty in Plan: OwnFreeKickInOppHalf

//State: PositionCloseToOppPenalty in Plan: OwnFreeKickInOppHalf

//State: Success in Plan: OwnFreeKickInOppHalf

//State: Wait/MoveOutOfWay in Plan: OwnFreeKickInOppHalf

}
