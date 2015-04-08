#include "Plans/WM161413992564408.h"
using namespace alica;
/*PROTECTED REGION ID(eph1413992564408) ENABLED START*/ //Add additional using directives here
//#include "Plans/Behaviours/DribbleToPoint.h"
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:WM16

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1413992564410

     */
    shared_ptr<UtilityFunction> UtilityFunction1413992564408::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1413992564408) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Stop in Plan: WM16

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == start 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426691976695::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426691974126) ENABLED START*/
        return wm->game.checkSituation(Situation::Start);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == Own(KickOff || FreeKick || GoalKick || Throwin || Corner || Penality) 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426691979272::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426691976989) ENABLED START*/
        return (wm->game.checkSituation(Situation::OwnCorner) || wm->game.checkSituation(Situation::OwnFreekick) ||
        		wm->game.checkSituation(Situation::OwnGoalkick) || wm->game.checkSituation(Situation::OwnKickoff)  ||
				wm->game.checkSituation(Situation::OwnThrowin) || wm->game.checkSituation(Situation::OwnPenalty));
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == Opp(KickOff || FreeKick || GoalKick || Throwin || Corner || Penality) 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426691980585::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426691979458) ENABLED START*/
    	return (wm->game.checkSituation(Situation::OppCorner) || wm->game.checkSituation(Situation::OppFreekick) ||
    	        		wm->game.checkSituation(Situation::OppGoalkick) || wm->game.checkSituation(Situation::OppKickoff)  ||
    					wm->game.checkSituation(Situation::OppThrowin) || wm->game.checkSituation(Situation::OppPenalty));
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == joystick 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426692078983::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426692077573) ENABLED START*/
        return wm->game.checkSituation(Situation::Joystick);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == parking 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426692165988::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426692164404) ENABLED START*/
        return wm->game.checkSituation(Situation::Parking);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == dropBall 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426692246279::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426692244795) ENABLED START*/
        return wm->game.checkSituation(Situation::DroppedBall);
        /*PROTECTED REGION END*/

    }

    //State: Gameplay in Plan: WM16

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation != start 
     *
     * Plans in State: 				
     *   - Plan - (Name): Gameplay, (PlanID): 1426694853089 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426692326693::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426692324690) ENABLED START*/
        return !(wm->game.checkSituation(Situation::Start));
        /*PROTECTED REGION END*/

    }

    //State: OpponentStandard in Plan: WM16

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : anyChildSuccess || moreThen10SecondsInStart 
     *
     * Plans in State: 				
     *   - Plan - (Name): OppStandards, (PlanID): 1426694865227 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426692309848::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426692308143) ENABLED START*/

    	//more than 10 sec in start
    	return rp->anyChildrenStatus(PlanStatus::Success) || this->isTimeOut(10000000000, wm->game.getTimeSinceStart(), rp);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): OppStandards, (PlanID): 1426694865227 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426692330833::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426692328789) ENABLED START*/
        return wm->game.checkSituation(Situation::Stop);
        /*PROTECTED REGION END*/

    }

    //State: OwnStandard in Plan: WM16

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : anyChildSuccess ||  moreThen10SecondsInStart 
     *
     * Plans in State: 				
     *   - Plan - (Name): OwnStandards, (PlanID): 1426694875113 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426692307991::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426692306144) ENABLED START*/

        return rp->anyChildrenStatus(PlanStatus::Success) ||  this->isTimeOut(10000000000, wm->game.getTimeSinceStart(), rp);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): OwnStandards, (PlanID): 1426694875113 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426692328653::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426692326813) ENABLED START*/
        return wm->game.checkSituation(Situation::Stop);
        /*PROTECTED REGION END*/

    }

    //State: Joystick in Plan: WM16

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == !joystick 
     *
     * Plans in State: 				
     *   - Plan - (Name): Joystick, (PlanID): 1426695479346 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426692324569::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426692322651) ENABLED START*/
        return !(wm->game.checkSituation(Situation::Joystick));
        /*PROTECTED REGION END*/

    }

    //State: Parking in Plan: WM16

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation != parken  
     *
     * Plans in State: 				
     *   - Plan - (Name): Parking, (PlanID): 1426695119330 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426692332679::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426692331032) ENABLED START*/
        return !(wm->game.checkSituation(Situation::Parking));
        /*PROTECTED REGION END*/

    }

    //State: DroppedBall in Plan: WM16

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation  != DropBall && situation !=start 
     *
     * Plans in State: 				
     *   - Plan - (Name): DroppedBall, (PlanID): 1426694906399 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426692322491::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426692315498) ENABLED START*/
        return (!wm->game.checkSituation(Situation::DroppedBall) && !wm->game.checkSituation(Situation::Start));
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : anyChildSuccess || moreThen10SecondsInStart 
     *
     * Plans in State: 				
     *   - Plan - (Name): DroppedBall, (PlanID): 1426694906399 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Stop (1413992564409)
     *   - Gameplay (1426691835473)
     *   - OpponentStandard (1426691842031)
     *   - OwnStandard (1426691966433)
     *   - Joystick (1426692070119)
     *   - Parking (1426692157956)
     *   - DroppedBall (1426692210342)
     *
     * Vars:
     */
    bool TransitionCondition1426692655810::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1426692653093) ENABLED START*/

    	//more than 10 sec in start
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

}
