#include "Plans/Standards/Own/Test/LongPassBasement1513176006534.h"
using namespace alica;
/*PROTECTED REGION ID(eph1513176006534) ENABLED START*/ // Add additional using directives here
#include <Ball.h>
#include <Game.h>
#include <MSLWorldModel.h>
#include <WhiteBoard.h>
#include <engine/model/Plan.h>
#include <MSLFootballField.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:LongPassBasement

    /* generated comment
     
     Task: ExecuteStandard  -> EntryPoint-ID: 1513176006536

     Task: ReceiveStandard  -> EntryPoint-ID: 1513176019047

     */
    shared_ptr<UtilityFunction> UtilityFunction1513176006534::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1513176006534) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: AlignExec in Plan: LongPassBasement

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation start 
     *
     * Plans in State: 				
     *   - Plan - (Name): StandardAlignToPointExecutor, (PlanID): 1435155363994 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1513176006536)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1513176019047)
     *
     * States:
     *   - AlignExec (1513176006535)
     *   - AlignRec (1513176035432)
     *   - GrabBall (1513176098858)
     *   - Pass (1513176103139)
     *   - Stop (1513176106132)
     *   - Success (1513176112686)
     *   - Receive (1513176169159)
     *
     * Vars:
     */
    bool TransitionCondition1513176125409::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1513176124567) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Start);
        /*PROTECTED REGION END*/

    }

    //State: AlignRec in Plan: LongPassBasement

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : pm for own id 
     *
     * Plans in State: 				
     *   - Plan - (Name): Align4PassTestDefault, (PlanID): 1513609404882 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1513176006536)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1513176019047)
     *
     * States:
     *   - AlignExec (1513176006535)
     *   - AlignRec (1513176035432)
     *   - GrabBall (1513176098858)
     *   - Pass (1513176103139)
     *   - Stop (1513176106132)
     *   - Success (1513176112686)
     *   - Receive (1513176169159)
     *
     * Vars:
     */
    bool TransitionCondition1513176175329::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1513176174538) ENABLED START*/
        return wm->whiteBoard->getPassMsg() != nullptr;
        /*PROTECTED REGION END*/

    }

    //State: GrabBall in Plan: LongPassBasement

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any child success 
     *
     * Plans in State: 				
     *   - Plan - (Name): StandardAlignAndGrabLongPass, (PlanID): 1513176284031 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1513176006536)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1513176019047)
     *
     * States:
     *   - AlignExec (1513176006535)
     *   - AlignRec (1513176035432)
     *   - GrabBall (1513176098858)
     *   - Pass (1513176103139)
     *   - Stop (1513176106132)
     *   - Success (1513176112686)
     *   - Receive (1513176169159)
     *
     * Vars:
     */
    bool TransitionCondition1513176126275::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1513176125489) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: Pass in Plan: LongPassBasement

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : passed 
     *
     * Plans in State: 				
     *   - Plan - (Name): ThrowInPassDefault, (PlanID): 1462363309950 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1513176006536)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1513176019047)
     *
     * States:
     *   - AlignExec (1513176006535)
     *   - AlignRec (1513176035432)
     *   - GrabBall (1513176098858)
     *   - Pass (1513176103139)
     *   - Stop (1513176106132)
     *   - Success (1513176112686)
     *   - Receive (1513176169159)
     *
     * Vars:
     */
    bool TransitionCondition1513176126957::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1513176126396) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : lostball 
     *
     * Plans in State: 				
     *   - Plan - (Name): ThrowInPassDefault, (PlanID): 1462363309950 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1513176006536)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1513176019047)
     *
     * States:
     *   - AlignExec (1513176006535)
     *   - AlignRec (1513176035432)
     *   - GrabBall (1513176098858)
     *   - Pass (1513176103139)
     *   - Stop (1513176106132)
     *   - Success (1513176112686)
     *   - Receive (1513176169159)
     *
     * Vars:
     */
    bool TransitionCondition1513176155095::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1513176153574) ENABLED START*/
        return !wm->ball->haveBall();
        /*PROTECTED REGION END*/

    }

    //State: Stop in Plan: LongPassBasement

    //State: Success in Plan: LongPassBasement

    //State: Receive in Plan: LongPassBasement

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : haveball or ball out of field 
     *
     * Plans in State: 				
     *   - Plan - (Name): InterceptDefault, (PlanID): 1458757193843 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1513176006536)
     *   - ReceiveStandard (1439997023446) (Entrypoint: 1513176019047)
     *
     * States:
     *   - AlignExec (1513176006535)
     *   - AlignRec (1513176035432)
     *   - GrabBall (1513176098858)
     *   - Pass (1513176103139)
     *   - Stop (1513176106132)
     *   - Success (1513176112686)
     *   - Receive (1513176169159)
     *
     * Vars:
     */
    bool TransitionCondition1513176176397::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1513176175579) ENABLED START*/
        auto ballPos = wm->ball->getAlloBallPosition();
        return wm->ball->haveBall()
                || (ballPos != nullptr
                        && (std::abs(ballPos->x) > wm->field->getFieldLength() / 2
                                || std::abs(ballPos->y) > wm->field->getFieldWidth() / 2));
        /*PROTECTED REGION END*/

    }

}
