#include "Plans/Attack/AttackPlay1434045709191.h"
using namespace alica;
/*PROTECTED REGION ID(eph1434045709191) ENABLED START*/ //Add additional using directives here
#include "PriorityList.h"
#include "DistBallRobot.h"
#include "engine/model/Plan.h"
#include "GameState.h"
#include <MSLWorldModel.h>
#include <Game.h>
#include <Ball.h>
#include <WhiteBoard.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:AttackPlay

    //Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) : true 

    /* 
     * Available Vars:
     *	- TargetX (1457002241973)
     *	- TargetY (1457002247256)
     */
    bool RunTimeCondition1434112519736::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434112519736) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/
    }

    /* generated comment
     
     Task: Attack  -> EntryPoint-ID: 1434045709194

     Task: Block  -> EntryPoint-ID: 1434045719840

     Task: Defend  -> EntryPoint-ID: 1434045723977

     Task: ReceivePassInGame  -> EntryPoint-ID: 1434112675755

     */
    shared_ptr<UtilityFunction> UtilityFunction1434045709191::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1434045709191) ENABLED START*/
        vector<long> entryPointsPr;
        entryPointsPr.push_back(1434045709194); // attacker
        entryPointsPr.push_back(1434112675755); // InGamePassReceiver
        entryPointsPr.push_back(1434045719840); // AttackSupport
        entryPointsPr.push_back(1434045723977); // Defend
        PriorityList* us = new PriorityList(0.15, "OtherPlan", 2, entryPointsPr);

        vector<long> entryPointsAt;
        entryPointsAt.push_back(1434045709194); // attacker
        msl::DistBallRobot* dbr = new msl::DistBallRobot(2.5, "DistBallRobot", 1, entryPointsAt);

        list<USummand*> utilSummands;
        utilSummands.push_back(dbr);
        utilSummands.push_back(us);
        shared_ptr < UtilityFunction > function = make_shared < UtilityFunction
                > ("PrioAndDBR", utilSummands, 0.01, 0.0, plan);
        return function;
        /*PROTECTED REGION END*/
    }

    //State: Attack in Plan: AttackPlay

    //State: MidFieldDefense in Plan: AttackPlay

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : PassMsg received for OwnID 
     *
     * Plans in State: 				
     *   - Plan - (Name): MidfieldDefense, (PlanID): 1458033329973 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434045709194)
     *   - Block (1461237765109) (Entrypoint: 1434045719840)
     *   - Defend (1225115406909) (Entrypoint: 1434045723977)
     *   - ReceivePassInGame (1307185798142) (Entrypoint: 1434112675755)
     *
     * States:
     *   - Attack (1434045709193)
     *   - MidFieldDefense (1434045868018)
     *   - Defend (1434045870617)
     *   - Release (1434112762535)
     *   - ApproachPass (1436536084172)
     *   - InterceptPass (1436536085953)
     *   - InterceptPass (1436536121614)
     *   - ApproachPass (1436536123918)
     *
     * Vars:
     */
    bool TransitionCondition1436536099859::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1436536098621) ENABLED START*/
        auto pm = wm->whiteBoard->getPassMsg();
        if (pm != nullptr && !equal(pm->senderID.id.begin(), pm->senderID.id.end(), wm->getOwnId()->toByteVector().begin()) &&
        		equal(pm->receiverID.id.begin(), pm->receiverID.id.end(), wm->getOwnId()->toByteVector().begin()))
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: Defend in Plan: AttackPlay

    //State: Release in Plan: AttackPlay

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : PassMsg received for OwnID 
     *
     * Plans in State: 				
     *   - Plan - (Name): MoveToPointDynamicDefault, (PlanID): 1456997097907 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434045709194)
     *   - Block (1461237765109) (Entrypoint: 1434045719840)
     *   - Defend (1225115406909) (Entrypoint: 1434045723977)
     *   - ReceivePassInGame (1307185798142) (Entrypoint: 1434112675755)
     *
     * States:
     *   - Attack (1434045709193)
     *   - MidFieldDefense (1434045868018)
     *   - Defend (1434045870617)
     *   - Release (1434112762535)
     *   - ApproachPass (1436536084172)
     *   - InterceptPass (1436536085953)
     *   - InterceptPass (1436536121614)
     *   - ApproachPass (1436536123918)
     *
     * Vars:
     */
    bool TransitionCondition1436536150520::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1436536148908) ENABLED START*/
        auto pm = wm->whiteBoard->getPassMsg();
        if (pm != nullptr && !equal(pm->senderID.id.begin(), pm->senderID.id.end(), wm->getOwnId()->toByteVector().begin()) &&
        		equal(pm->receiverID.id.begin(), pm->receiverID.id.end(), wm->getOwnId()->toByteVector().begin()))
        {
            return true;
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: ApproachPass in Plan: AttackPlay

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : ApproachPass2InterceptPass: rawballconf > x 
     *
     * Plans in State: 				
     *   - Plan - (Name): CatchPassDefault, (PlanID): 1440754543898 				
     *   - Plan - (Name): DribbleControlNoBall, (PlanID): 1450175539163 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434045709194)
     *   - Block (1461237765109) (Entrypoint: 1434045719840)
     *   - Defend (1225115406909) (Entrypoint: 1434045723977)
     *   - ReceivePassInGame (1307185798142) (Entrypoint: 1434112675755)
     *
     * States:
     *   - Attack (1434045709193)
     *   - MidFieldDefense (1434045868018)
     *   - Defend (1434045870617)
     *   - Release (1434112762535)
     *   - ApproachPass (1436536084172)
     *   - InterceptPass (1436536085953)
     *   - InterceptPass (1436536121614)
     *   - ApproachPass (1436536123918)
     *
     * Vars:
     */
    bool TransitionCondition1436536101707::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1436536100248) ENABLED START*/
        double rawBallConf = wm->ball->getBallConfidenceVision();
        shared_ptr < geometry::CNPoint2D > rawBall = wm->ball->getVisionBallPosition();
        bool rawBallChecked = rawBall != nullptr && rawBallConf > 0.4;
        if (wm->ball->getEgoBallPosition() == nullptr)
        {
            return rawBallChecked;
        }
        else
        {
            return rawBallChecked && wm->ball->getEgoBallPosition()->length() < 3000.0;
        }
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : PassMsg == null && GameState==Attack 
     *
     * Plans in State: 				
     *   - Plan - (Name): CatchPassDefault, (PlanID): 1440754543898 				
     *   - Plan - (Name): DribbleControlNoBall, (PlanID): 1450175539163 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434045709194)
     *   - Block (1461237765109) (Entrypoint: 1434045719840)
     *   - Defend (1225115406909) (Entrypoint: 1434045723977)
     *   - ReceivePassInGame (1307185798142) (Entrypoint: 1434112675755)
     *
     * States:
     *   - Attack (1434045709193)
     *   - MidFieldDefense (1434045868018)
     *   - Defend (1434045870617)
     *   - Release (1434112762535)
     *   - ApproachPass (1436536084172)
     *   - InterceptPass (1436536085953)
     *   - InterceptPass (1436536121614)
     *   - ApproachPass (1436536123918)
     *
     * Vars:
     */
    bool TransitionCondition1436536104021::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1436536103266) ENABLED START*/
        return wm->whiteBoard->getPassMsg() == nullptr && wm->game->getGameState() == msl::GameState::OwnBallPossession;
        /*PROTECTED REGION END*/

    }

    //State: InterceptPass in Plan: AttackPlay

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : InterceptPass2ApproachPass: PassMsg == null && GameState==Attack 
     *
     * Plans in State: 				
     *   - Plan - (Name): InterceptCarefullyDefault, (PlanID): 1427703234654 				
     *   - Plan - (Name): DribbleControlNoBall, (PlanID): 1450175539163 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434045709194)
     *   - Block (1461237765109) (Entrypoint: 1434045719840)
     *   - Defend (1225115406909) (Entrypoint: 1434045723977)
     *   - ReceivePassInGame (1307185798142) (Entrypoint: 1434112675755)
     *
     * States:
     *   - Attack (1434045709193)
     *   - MidFieldDefense (1434045868018)
     *   - Defend (1434045870617)
     *   - Release (1434112762535)
     *   - ApproachPass (1436536084172)
     *   - InterceptPass (1436536085953)
     *   - InterceptPass (1436536121614)
     *   - ApproachPass (1436536123918)
     *
     * Vars:
     */
    bool TransitionCondition1436536103010::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1436536101847) ENABLED START*/
        return wm->whiteBoard->getPassMsg() == nullptr && wm->game->getGameState() == msl::GameState::OwnBallPossession;
        /*PROTECTED REGION END*/

    }

    //State: InterceptPass in Plan: AttackPlay

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : InterceptPass2ApproachPass: PassMsg == null && GameState==Attack 
     *
     * Plans in State: 				
     *   - Plan - (Name): InterceptCarefullyDefault, (PlanID): 1427703234654 				
     *   - Plan - (Name): DribbleControlNoBall, (PlanID): 1450175539163 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434045709194)
     *   - Block (1461237765109) (Entrypoint: 1434045719840)
     *   - Defend (1225115406909) (Entrypoint: 1434045723977)
     *   - ReceivePassInGame (1307185798142) (Entrypoint: 1434112675755)
     *
     * States:
     *   - Attack (1434045709193)
     *   - MidFieldDefense (1434045868018)
     *   - Defend (1434045870617)
     *   - Release (1434112762535)
     *   - ApproachPass (1436536084172)
     *   - InterceptPass (1436536085953)
     *   - InterceptPass (1436536121614)
     *   - ApproachPass (1436536123918)
     *
     * Vars:
     */
    bool TransitionCondition1436536152571::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1436536151770) ENABLED START*/
        return wm->whiteBoard->getPassMsg() == nullptr && wm->game->getGameState() == msl::GameState::OwnBallPossession;;
        /*PROTECTED REGION END*/

    }

    //State: ApproachPass in Plan: AttackPlay

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : ApproachPass2InterceptPass: rawballconf > x 
     *
     * Plans in State: 				
     *   - Plan - (Name): CatchPassDefault, (PlanID): 1440754543898 				
     *   - Plan - (Name): DribbleControlNoBall, (PlanID): 1450175539163 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434045709194)
     *   - Block (1461237765109) (Entrypoint: 1434045719840)
     *   - Defend (1225115406909) (Entrypoint: 1434045723977)
     *   - ReceivePassInGame (1307185798142) (Entrypoint: 1434112675755)
     *
     * States:
     *   - Attack (1434045709193)
     *   - MidFieldDefense (1434045868018)
     *   - Defend (1434045870617)
     *   - Release (1434112762535)
     *   - ApproachPass (1436536084172)
     *   - InterceptPass (1436536085953)
     *   - InterceptPass (1436536121614)
     *   - ApproachPass (1436536123918)
     *
     * Vars:
     */
    bool TransitionCondition1436536151584::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1436536150744) ENABLED START*/
        double rawBallConf = wm->ball->getBallConfidenceVision();
        shared_ptr < geometry::CNPoint2D > rawBall = wm->ball->getVisionBallPosition();
        return rawBall != nullptr && rawBallConf > 0.4;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : PassMsg == null && GameState==Attack 
     *
     * Plans in State: 				
     *   - Plan - (Name): CatchPassDefault, (PlanID): 1440754543898 				
     *   - Plan - (Name): DribbleControlNoBall, (PlanID): 1450175539163 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434045709194)
     *   - Block (1461237765109) (Entrypoint: 1434045719840)
     *   - Defend (1225115406909) (Entrypoint: 1434045723977)
     *   - ReceivePassInGame (1307185798142) (Entrypoint: 1434112675755)
     *
     * States:
     *   - Attack (1434045709193)
     *   - MidFieldDefense (1434045868018)
     *   - Defend (1434045870617)
     *   - Release (1434112762535)
     *   - ApproachPass (1436536084172)
     *   - InterceptPass (1436536085953)
     *   - InterceptPass (1436536121614)
     *   - ApproachPass (1436536123918)
     *
     * Vars:
     */
    bool TransitionCondition1436536161660::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1436536160346) ENABLED START*/
        return wm->whiteBoard->getPassMsg() == nullptr && wm->game->getGameState() == msl::GameState::OwnBallPossession;
        /*PROTECTED REGION END*/

    }

}
