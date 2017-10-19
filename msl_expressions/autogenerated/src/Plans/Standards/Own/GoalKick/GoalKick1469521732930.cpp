#include "Plans/Standards/Own/GoalKick/GoalKick1469521732930.h"
using namespace alica;
/*PROTECTED REGION ID(eph1469521732930) ENABLED START*/ //Add additional using directives here
#include "BallXIntervall.h"
#include <MSLWorldModel.h>
#include <MSLFootballField.h>
#include <Game.h>
#include <Ball.h>
#include <WhiteBoard.h>
#include <Rules.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:GoalKick

    //Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) :  

    /* 
     * Available Vars:
     */
    bool RunTimeCondition1469522753378::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469522753378) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/
    }

    /* generated comment
     
     Task: ExecuteStandard  -> EntryPoint-ID: 1469521732932

     Task: ReceiveStandard  -> EntryPoint-ID: 1469522042827

     Task: AlternativeReceive  -> EntryPoint-ID: 1469522045842

     Task: Block  -> EntryPoint-ID: 1469522047745

     */
    shared_ptr<UtilityFunction> UtilityFunction1469521732930::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1469521732930) ENABLED START*/
        vector<long> entryPoints;

        entryPoints.push_back(1469521732932); // ExecuteStandard
        entryPoints.push_back(1469522042827); // ReceiveStandard
        entryPoints.push_back(1469522045842); // Block
        entryPoints.push_back(1469522047745); // AlternitveReceive

        double angle = 55 * M_PI / 180; // nice angle to shoot on the goal
        BallXIntervall* us = new BallXIntervall(3.0, "FreekickOwnHalf", 3, entryPoints,
                                                -(msl::MSLWorldModel::get()->field->getFieldLength() / 2), 4800.0,
                                                1000.0);
        list<USummand*> utilSummands;
        utilSummands.push_back(us);
        shared_ptr < UtilityFunction > function = make_shared < UtilityFunction
                > ("FreeKickNearGoalTest", utilSummands, 0.1, 0.2, plan);
        return function;

        /*PROTECTED REGION END*/
    }

    //State: AlignExec in Plan: GoalKick

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : (child success && start) || (start && timeSinceStart > timeUntilEmergencyExecute) 
     *
     * Plans in State: 				
     *   - Plan - (Name): StandardActuateDefault, (PlanID): 1435766278023 				
     *   - Plan - (Name): StandardAlignAndGrab2ReceiversTIOH, (PlanID): 1462368748899 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1469521732932)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1469522042827)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1469522045842)
     *   - Block (1461237765109) (Entrypoint: 1469522047745)
     *
     * States:
     *   - AlignExec (1469521732931)
     *   - Block (1469522259560)
     *   - GrabBall (1469522367640)
     *   - Pass (1469522370067)
     *   - Stop (1469522371971)
     *   - AlignRec (1469522490708)
     *   - Receive (1469522492956)
     *   - AlignRecAlternative (1469522494669)
     *   - ReceiveAlternative (1469522496824)
     *   - Success (1469522586732)
     *   - SuccessAlternative (1469522588381)
     *
     * Vars:
     */
    bool TransitionCondition1469522459250::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469522458021) ENABLED START*/
        return (rp->anyChildrenStatus(PlanStatus::Success) && wm->game->checkSituation(msl::Situation::Start))
                || (wm->game->checkSituation(msl::Situation::Start)
                        && (this->isTimeOut(this->timeUntilEmergencyExecute, wm->game->getTimeSinceStart(), rp)));
        /*PROTECTED REGION END*/

    }

    //State: Block in Plan: GoalKick

    //State: GrabBall in Plan: GoalKick

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : haveball 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 				
     *   - Plan - (Name): StandardActuateDefault, (PlanID): 1435766278023 				
     *   - Plan - (Name): StandardAlignAndGrab2ReceiversTIOH, (PlanID): 1462368748899 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1469521732932)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1469522042827)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1469522045842)
     *   - Block (1461237765109) (Entrypoint: 1469522047745)
     *
     * States:
     *   - AlignExec (1469521732931)
     *   - Block (1469522259560)
     *   - GrabBall (1469522367640)
     *   - Pass (1469522370067)
     *   - Stop (1469522371971)
     *   - AlignRec (1469522490708)
     *   - Receive (1469522492956)
     *   - AlignRecAlternative (1469522494669)
     *   - ReceiveAlternative (1469522496824)
     *   - Success (1469522586732)
     *   - SuccessAlternative (1469522588381)
     *
     * Vars:
     */
    bool TransitionCondition1469522460345::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469522459411) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: Pass in Plan: GoalKick

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : executed 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1469521732932)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1469522042827)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1469522045842)
     *   - Block (1461237765109) (Entrypoint: 1469522047745)
     *
     * States:
     *   - AlignExec (1469521732931)
     *   - Block (1469522259560)
     *   - GrabBall (1469522367640)
     *   - Pass (1469522370067)
     *   - Stop (1469522371971)
     *   - AlignRec (1469522490708)
     *   - Receive (1469522492956)
     *   - AlignRecAlternative (1469522494669)
     *   - ReceiveAlternative (1469522496824)
     *   - Success (1469522586732)
     *   - SuccessAlternative (1469522588381)
     *
     * Vars:
     */
    bool TransitionCondition1469522461332::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469522460547) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : lostball 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1469521732932)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1469522042827)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1469522045842)
     *   - Block (1461237765109) (Entrypoint: 1469522047745)
     *
     * States:
     *   - AlignExec (1469521732931)
     *   - Block (1469522259560)
     *   - GrabBall (1469522367640)
     *   - Pass (1469522370067)
     *   - Stop (1469522371971)
     *   - AlignRec (1469522490708)
     *   - Receive (1469522492956)
     *   - AlignRecAlternative (1469522494669)
     *   - ReceiveAlternative (1469522496824)
     *   - Success (1469522586732)
     *   - SuccessAlternative (1469522588381)
     *
     * Vars:
     */
    bool TransitionCondition1469522463041::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469522461468) ENABLED START*/
        return !wm->ball->haveBall();
        /*PROTECTED REGION END*/

    }

    //State: Stop in Plan: GoalKick

    //State: AlignRec in Plan: GoalKick

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : pm for own id 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShovelSelectHighKick, (PlanID): 1435156811453 				
     *   - Plan - (Name): ReceiveInOppHalfDefault, (PlanID): 1462370388995 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1469521732932)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1469522042827)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1469522045842)
     *   - Block (1461237765109) (Entrypoint: 1469522047745)
     *
     * States:
     *   - AlignExec (1469521732931)
     *   - Block (1469522259560)
     *   - GrabBall (1469522367640)
     *   - Pass (1469522370067)
     *   - Stop (1469522371971)
     *   - AlignRec (1469522490708)
     *   - Receive (1469522492956)
     *   - AlignRecAlternative (1469522494669)
     *   - ReceiveAlternative (1469522496824)
     *   - Success (1469522586732)
     *   - SuccessAlternative (1469522588381)
     *
     * Vars:
     */
    bool TransitionCondition1469522685256::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469522683853) ENABLED START*/
        auto pm = wm->whiteBoard->getPassMsgBuffer().getLastValidContent();
        if (pm && pm->senderID != wm->getOwnId() && pm->receiverID == wm->getOwnId())
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: Receive in Plan: GoalKick

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : pass received  
     *
     * Plans in State: 				
     *   - Plan - (Name): InterceptCarefullyDefault, (PlanID): 1427703234654 				
     *   - Plan - (Name): ShovelSelectHighKick, (PlanID): 1435156811453 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1469521732932)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1469522042827)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1469522045842)
     *   - Block (1461237765109) (Entrypoint: 1469522047745)
     *
     * States:
     *   - AlignExec (1469521732931)
     *   - Block (1469522259560)
     *   - GrabBall (1469522367640)
     *   - Pass (1469522370067)
     *   - Stop (1469522371971)
     *   - AlignRec (1469522490708)
     *   - Receive (1469522492956)
     *   - AlignRecAlternative (1469522494669)
     *   - ReceiveAlternative (1469522496824)
     *   - Success (1469522586732)
     *   - SuccessAlternative (1469522588381)
     *
     * Vars:
     */
    bool TransitionCondition1469522686688::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469522685570) ENABLED START*/
        return this->isTimeOut(this->rules->getStandbyTime() * 0.75, rp->getStateStartTime(), rp)
                || wm->ball->haveBall();
        /*PROTECTED REGION END*/

    }

    //State: AlignRecAlternative in Plan: GoalKick

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : pm for own id alternative 
     *
     * Plans in State: 				
     *   - Plan - (Name): PositionAlternativeReceiverDefault, (PlanID): 1462978671719 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1469521732932)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1469522042827)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1469522045842)
     *   - Block (1461237765109) (Entrypoint: 1469522047745)
     *
     * States:
     *   - AlignExec (1469521732931)
     *   - Block (1469522259560)
     *   - GrabBall (1469522367640)
     *   - Pass (1469522370067)
     *   - Stop (1469522371971)
     *   - AlignRec (1469522490708)
     *   - Receive (1469522492956)
     *   - AlignRecAlternative (1469522494669)
     *   - ReceiveAlternative (1469522496824)
     *   - Success (1469522586732)
     *   - SuccessAlternative (1469522588381)
     *
     * Vars:
     */
    bool TransitionCondition1469522692577::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469522690355) ENABLED START*/
        auto pm = wm->whiteBoard->getPassMsgBuffer().getLastValidContent();
        if (pm && pm->senderID != wm->getOwnId() && pm->receiverID == wm->getOwnId())
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: ReceiveAlternative in Plan: GoalKick

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : pass received from alternative 
     *
     * Plans in State: 				
     *   - Plan - (Name): InterceptCarefullyDefault, (PlanID): 1427703234654 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1469521732932)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1469522042827)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1469522045842)
     *   - Block (1461237765109) (Entrypoint: 1469522047745)
     *
     * States:
     *   - AlignExec (1469521732931)
     *   - Block (1469522259560)
     *   - GrabBall (1469522367640)
     *   - Pass (1469522370067)
     *   - Stop (1469522371971)
     *   - AlignRec (1469522490708)
     *   - Receive (1469522492956)
     *   - AlignRecAlternative (1469522494669)
     *   - ReceiveAlternative (1469522496824)
     *   - Success (1469522586732)
     *   - SuccessAlternative (1469522588381)
     *
     * Vars:
     */
    bool TransitionCondition1469522690037::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469522688609) ENABLED START*/
        return this->isTimeOut(this->rules->getStandbyTime() * 0.75, rp->getStateStartTime(), rp)
                || wm->ball->haveBall();
        /*PROTECTED REGION END*/

    }

//State: Success in Plan: GoalKick

//State: SuccessAlternative in Plan: GoalKick

}
