#include "Plans/GameStrategy/Gameplay/GamePlay1457173546734.h"
using namespace alica;
/*PROTECTED REGION ID(eph1457173546734) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:GamePlay

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1457173565463

     Task: Keeper  -> EntryPoint-ID: 1457173833589

     */
    shared_ptr<UtilityFunction> UtilityFunction1457173546734::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1457173546734) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Defend in Plan: GamePlay

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : GameState == (Attack || Melee)  
     *
     * Plans in State: 				
     *   - Plan - (Name): DefendPlay, (PlanID): 1457173681216 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1457173565463)
     *   - Keeper (1221754402444) (Entrypoint: 1457173833589)
     *
     * States:
     *   - Defend (1457173565462)
     *   - Attack (1457173576569)
     *   - DefendGoal (1457173842758)
     *
     * Vars:
     */
    bool TransitionCondition1457173604049::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1457173602825) ENABLED START*/
        auto gs = wm->game.getGameState();
        return gs == msl::GameState::OwnBallPossession || gs == msl::GameState::Duel;
        /*PROTECTED REGION END*/

    }

    //State: Attack in Plan: GamePlay

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : GameState == (Defend)  
     *
     * Plans in State: 				
     *   - Plan - (Name): GamePlayAttackType, (PlanID): 1457173624653 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1457173565463)
     *   - Keeper (1221754402444) (Entrypoint: 1457173833589)
     *
     * States:
     *   - Defend (1457173565462)
     *   - Attack (1457173576569)
     *   - DefendGoal (1457173842758)
     *
     * Vars:
     */
    bool TransitionCondition1457173606067::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1457173604378) ENABLED START*/
        auto gs = wm->game.getGameState();
        return gs == msl::GameState::OppBallPossession;
        /*PROTECTED REGION END*/

    }

//State: DefendGoal in Plan: GamePlay

}
