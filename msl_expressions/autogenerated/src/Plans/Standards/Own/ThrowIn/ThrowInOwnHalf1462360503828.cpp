#include "Plans/Standards/Own/ThrowIn/ThrowInOwnHalf1462360503828.h"
using namespace alica;
/*PROTECTED REGION ID(eph1462360503828) ENABLED START*/ //Add additional using directives here
#include "BallXIntervall.h"
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:ThrowInOwnHalf

    //Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) :  

    /* 
     * Available Vars:
     */
    bool RunTimeCondition1462361418213::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1462361418213) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/
    }

    /* generated comment
     
     Task: ExecuteStandard  -> EntryPoint-ID: 1462360503830

     Task: ReceiveStandard  -> EntryPoint-ID: 1462360607517

     Task: AlternativeReceive  -> EntryPoint-ID: 1462360610006

     Task: Block  -> EntryPoint-ID: 1462360612527

     */
    shared_ptr<UtilityFunction> UtilityFunction1462360503828::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1462360503828) ENABLED START*/

        vector<long> entryPoints;

        entryPoints.push_back(1462360503830); // ExecuteStandard
        entryPoints.push_back(1462360607517); // ReceiveStandard
        entryPoints.push_back(1462360612527); // Block
        entryPoints.push_back(1462360610006); // AlternitveReceive

        double angle = 55 * M_PI / 180; // nice angle to shoot on the goal
        BallXIntervall* us = new BallXIntervall(2.0, "ThrowInOwnHalf", 3, entryPoints,
                                                -(msl::MSLWorldModel::get()->field->getFieldLength() / 2), 2500.0,
                                                1000.0);
        list<USummand*> utilSummands;
        utilSummands.push_back(us);
        shared_ptr < UtilityFunction > function = make_shared < UtilityFunction
                > ("ThrowInNearGoalTest", utilSummands, 0.1, 0.2, plan);
        return function;

        /*PROTECTED REGION END*/
    }

    //State: Align in Plan: ThrowInOwnHalf

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : aligned exec 
     *
     * Plans in State: 				
     *   - Plan - (Name): StandardActuateDefault, (PlanID): 1435766278023 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1462360503830)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1462360607517)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1462360610006)
     *   - Block (1461237765109) (Entrypoint: 1462360612527)
     *
     * States:
     *   - Align (1462360503829)
     *   - GrabBall (1462360912906)
     *   - Pass (1462360919387)
     *   - Wait (1462360928236)
     *   - AlignReceive (1462361351034)
     *   - Align (1462361358155)
     *   - Block (1462361373364)
     *   - ReceiveAlternative (1462363134771)
     *   - Success (1462363320340)
     *   - Receive (1462368095616)
     *   - Successalternative (1462368161988)
     *
     * Vars:
     */
    bool TransitionCondition1462360958757::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1462360957397) ENABLED START*/
        return (rp->anyChildrenStatus(PlanStatus::Success) && wm->game->checkSituation(msl::Situation::Start))
                || (wm->game->checkSituation(msl::Situation::Start)
                        && wm->getTime() - wm->game->getTimeSinceStart() > 8000000000);
        /*PROTECTED REGION END*/

    }

    //State: GrabBall in Plan: ThrowInOwnHalf

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
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1462360503830)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1462360607517)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1462360610006)
     *   - Block (1461237765109) (Entrypoint: 1462360612527)
     *
     * States:
     *   - Align (1462360503829)
     *   - GrabBall (1462360912906)
     *   - Pass (1462360919387)
     *   - Wait (1462360928236)
     *   - AlignReceive (1462361351034)
     *   - Align (1462361358155)
     *   - Block (1462361373364)
     *   - ReceiveAlternative (1462363134771)
     *   - Success (1462363320340)
     *   - Receive (1462368095616)
     *   - Successalternative (1462368161988)
     *
     * Vars:
     */
    bool TransitionCondition1462360959862::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1462360958905) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: Pass in Plan: ThrowInOwnHalf

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : executed 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 				
     *   - Plan - (Name): ThrowInPassDefault, (PlanID): 1462363309950 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1462360503830)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1462360607517)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1462360610006)
     *   - Block (1461237765109) (Entrypoint: 1462360612527)
     *
     * States:
     *   - Align (1462360503829)
     *   - GrabBall (1462360912906)
     *   - Pass (1462360919387)
     *   - Wait (1462360928236)
     *   - AlignReceive (1462361351034)
     *   - Align (1462361358155)
     *   - Block (1462361373364)
     *   - ReceiveAlternative (1462363134771)
     *   - Success (1462363320340)
     *   - Receive (1462368095616)
     *   - Successalternative (1462368161988)
     *
     * Vars:
     */
    bool TransitionCondition1462360961688::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1462360960031) ENABLED START*/
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
     *   - Plan - (Name): ThrowInPassDefault, (PlanID): 1462363309950 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1462360503830)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1462360607517)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1462360610006)
     *   - Block (1461237765109) (Entrypoint: 1462360612527)
     *
     * States:
     *   - Align (1462360503829)
     *   - GrabBall (1462360912906)
     *   - Pass (1462360919387)
     *   - Wait (1462360928236)
     *   - AlignReceive (1462361351034)
     *   - Align (1462361358155)
     *   - Block (1462361373364)
     *   - ReceiveAlternative (1462363134771)
     *   - Success (1462363320340)
     *   - Receive (1462368095616)
     *   - Successalternative (1462368161988)
     *
     * Vars:
     */
    bool TransitionCondition1462369227764::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1462369226508) ENABLED START*/
        return !wm->ball->haveBall();
        /*PROTECTED REGION END*/

    }

    //State: Wait in Plan: ThrowInOwnHalf

    //State: AlignReceive in Plan: ThrowInOwnHalf

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : pm for own id 
     *
     * Plans in State: 				
     *   - Plan - (Name): ReceiveInOppHalfDefault, (PlanID): 1462370388995 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1462360503830)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1462360607517)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1462360610006)
     *   - Block (1461237765109) (Entrypoint: 1462360612527)
     *
     * States:
     *   - Align (1462360503829)
     *   - GrabBall (1462360912906)
     *   - Pass (1462360919387)
     *   - Wait (1462360928236)
     *   - AlignReceive (1462361351034)
     *   - Align (1462361358155)
     *   - Block (1462361373364)
     *   - ReceiveAlternative (1462363134771)
     *   - Success (1462363320340)
     *   - Receive (1462368095616)
     *   - Successalternative (1462368161988)
     *
     * Vars:
     */
    bool TransitionCondition1462368267324::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1462368266008) ENABLED START*/
        auto pm = wm->whiteBoard->getPassMsg();
        if (pm != nullptr && pm->senderID != wm->getOwnId() && pm->receiverID == wm->getOwnId())
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: Align in Plan: ThrowInOwnHalf

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : pm for own id alternative 
     *
     * Plans in State: 				
     *   - Plan - (Name): PositionAlternativeReceiverDefault, (PlanID): 1462978671719 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1462360503830)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1462360607517)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1462360610006)
     *   - Block (1461237765109) (Entrypoint: 1462360612527)
     *
     * States:
     *   - Align (1462360503829)
     *   - GrabBall (1462360912906)
     *   - Pass (1462360919387)
     *   - Wait (1462360928236)
     *   - AlignReceive (1462361351034)
     *   - Align (1462361358155)
     *   - Block (1462361373364)
     *   - ReceiveAlternative (1462363134771)
     *   - Success (1462363320340)
     *   - Receive (1462368095616)
     *   - Successalternative (1462368161988)
     *
     * Vars:
     */
    bool TransitionCondition1462368269701::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1462368267461) ENABLED START*/
        auto pm = wm->whiteBoard->getPassMsg();
        if (pm != nullptr && pm->senderID != wm->getOwnId() && pm->receiverID == wm->getOwnId())
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: Block in Plan: ThrowInOwnHalf

    //State: ReceiveAlternative in Plan: ThrowInOwnHalf

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : pass received from alternative 
     *
     * Plans in State: 				
     *   - Plan - (Name): InterceptCarefullyDefault, (PlanID): 1427703234654 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1462360503830)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1462360607517)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1462360610006)
     *   - Block (1461237765109) (Entrypoint: 1462360612527)
     *
     * States:
     *   - Align (1462360503829)
     *   - GrabBall (1462360912906)
     *   - Pass (1462360919387)
     *   - Wait (1462360928236)
     *   - AlignReceive (1462361351034)
     *   - Align (1462361358155)
     *   - Block (1462361373364)
     *   - ReceiveAlternative (1462363134771)
     *   - Success (1462363320340)
     *   - Receive (1462368095616)
     *   - Successalternative (1462368161988)
     *
     * Vars:
     */
    bool TransitionCondition1462368203054::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1462368201420) ENABLED START*/
        return this->isTimeOut(750000000, rp->getStateStartTime(), rp);
        /*PROTECTED REGION END*/

    }

    //State: Success in Plan: ThrowInOwnHalf

    //State: Receive in Plan: ThrowInOwnHalf

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
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1462360503830)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1462360607517)
     *   - AlternativeReceive (1462360858945) (Entrypoint: 1462360610006)
     *   - Block (1461237765109) (Entrypoint: 1462360612527)
     *
     * States:
     *   - Align (1462360503829)
     *   - GrabBall (1462360912906)
     *   - Pass (1462360919387)
     *   - Wait (1462360928236)
     *   - AlignReceive (1462361351034)
     *   - Align (1462361358155)
     *   - Block (1462361373364)
     *   - ReceiveAlternative (1462363134771)
     *   - Success (1462363320340)
     *   - Receive (1462368095616)
     *   - Successalternative (1462368161988)
     *
     * Vars:
     */
    bool TransitionCondition1462368132067::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1462368130262) ENABLED START*/
        return this->isTimeOut(750000000, rp->getStateStartTime(), rp);
        /*PROTECTED REGION END*/

    }

//State: Successalternative in Plan: ThrowInOwnHalf

}
