#include "Plans/Robotcheck/Robotcheck1456756058055.h"
using namespace alica;
/*PROTECTED REGION ID(eph1456756058055) ENABLED START*/ //Add additional using directives here
#include <MSLWorldModel.h>
#include <Game.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:Robotcheck

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1456756058057

     */
    shared_ptr<UtilityFunction> UtilityFunction1456756058055::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1456756058055) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: RobotCheck in Plan: Robotcheck

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): RobotTestDefault, (PlanID): 1456756164754 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1456756058057)
     *
     * States:
     *   - RobotCheck (1456756058056)
     *   - Stop (1456841196692)
     *   - NewSuccessState (1456841265112)
     *
     * Vars:
     */
    bool TransitionCondition1456841244750::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1456841242506) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Stop);
    	/*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Success 
     *
     * Plans in State: 				
     *   - Plan - (Name): RobotTestDefault, (PlanID): 1456756164754 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1456756058057)
     *
     * States:
     *   - RobotCheck (1456756058056)
     *   - Stop (1456841196692)
     *   - NewSuccessState (1456841265112)
     *
     * Vars:
     */
    bool TransitionCondition1456841276132::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1456841274321) ENABLED START*/
    	return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: Stop in Plan: Robotcheck

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Start 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1456756058057)
     *
     * States:
     *   - RobotCheck (1456756058056)
     *   - Stop (1456841196692)
     *   - NewSuccessState (1456841265112)
     *
     * Vars:
     */
    bool TransitionCondition1456841218640::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1456841216933) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Start);
        /*PROTECTED REGION END*/

    }

//State: NewSuccessState in Plan: Robotcheck

}
