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

    //State: Init in Plan: WM16

    /*
     *		
     * Transition:
     *   - Name: , ConditionString: , Comment :  
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Init (1413992564409)
     *   - Drive (1413992572149)
     *   - Dribble (1414752333556)
     *   - AlineToGoal (1415205191506)
     *   - GoalKick (1415206960125)
     *
     * Vars:
     */
    bool TransitionCondition1413992578046::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1413992575757) ENABLED START*/
        return true;
        /*PROTECTED REGION END*/

    }

    //State: Drive in Plan: WM16

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment :  
     *
     * Plans in State: 				
     *   - Plan - (Name): GetBallDefault, (PlanID): 1414840399972 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Init (1413992564409)
     *   - Drive (1413992572149)
     *   - Dribble (1414752333556)
     *   - AlineToGoal (1415205191506)
     *   - GoalKick (1415206960125)
     *
     * Vars:
     */
    bool TransitionCondition1414752354525::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1414752349075) ENABLED START*/

        return false;
        /*PROTECTED REGION END*/

    }

    //State: Dribble in Plan: WM16

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment :  
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleToPointDefault, (PlanID): 1414752423981 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Init (1413992564409)
     *   - Drive (1413992572149)
     *   - Dribble (1414752333556)
     *   - AlineToGoal (1415205191506)
     *   - GoalKick (1415206960125)
     *
     * Vars:
     */
    bool TransitionCondition1414883779788::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1414883776988) ENABLED START*/
        return !wm->haveBall();
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment :  
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleToPointDefault, (PlanID): 1414752423981 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Init (1413992564409)
     *   - Drive (1413992572149)
     *   - Dribble (1414752333556)
     *   - AlineToGoal (1415205191506)
     *   - GoalKick (1415206960125)
     *
     * Vars:
     */
    bool TransitionCondition1415205268720::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1415205265272) ENABLED START*/

        return false;

        /*PROTECTED REGION END*/

    }

    //State: AlineToGoal in Plan: WM16

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment :  
     *
     * Plans in State: 				
     *   - Plan - (Name): AlineToGoalDefault, (PlanID): 1415205285582 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Init (1413992564409)
     *   - Drive (1413992572149)
     *   - Dribble (1414752333556)
     *   - AlineToGoal (1415205191506)
     *   - GoalKick (1415206960125)
     *
     * Vars:
     */
    bool TransitionCondition1415206979578::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1415206978594) ENABLED START*/
        return false;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment :  
     *
     * Plans in State: 				
     *   - Plan - (Name): AlineToGoalDefault, (PlanID): 1415205285582 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Init (1413992564409)
     *   - Drive (1413992572149)
     *   - Dribble (1414752333556)
     *   - AlineToGoal (1415205191506)
     *   - GoalKick (1415206960125)
     *
     * Vars:
     */
    bool TransitionCondition1415207006891::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1415207005689) ENABLED START*/
        return !wm->haveBall();
        /*PROTECTED REGION END*/

    }

    //State: GoalKick in Plan: WM16

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment :  
     *
     * Plans in State: 				
     *   - Plan - (Name): GoalKickDefault, (PlanID): 1415205578139 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1413992564410)
     *
     * States:
     *   - Init (1413992564409)
     *   - Drive (1413992572149)
     *   - Dribble (1414752333556)
     *   - AlineToGoal (1415205191506)
     *   - GoalKick (1415206960125)
     *
     * Vars:
     */
    bool TransitionCondition1415207067102::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1415207059261) ENABLED START*/
        return !wm->haveBall();
        /*PROTECTED REGION END*/

    }

}
