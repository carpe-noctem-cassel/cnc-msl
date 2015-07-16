#include "Plans/Attack/TestPlans/DribbleToPointPlan1436960829485.h"
using namespace alica;
/*PROTECTED REGION ID(eph1436960829485) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
	//Plan:DribbleToPointPlan

	/* generated comment

	 Task: DefaultTask  -> EntryPoint-ID: 1436960854733

	 */
	shared_ptr<UtilityFunction> UtilityFunction1436960829485::getUtilityFunction(Plan* plan)
	{
		/*PROTECTED REGION ID(1436960829485) ENABLED START*/

		shared_ptr<UtilityFunction> defaultFunction = make_shared<DefaultUtilityFunction>(plan);
		return defaultFunction;

		/*PROTECTED REGION END*/
	}

	//State: DriveToOwnPenaltySpot in Plan: DribbleToPointPlan

	/*
	 *
	 * Transition:
	 *   - Name: MISSING_NAME, ConditionString: , Comment : any child success
	 *
	 * Plans in State:
	 *   - Plan - (Name): DriveToOwnPenaltySpot, (PlanID): 1436961206415
	 *
	 * Tasks:
	 *   - DefaultTask (1225112227903) (Entrypoint: 1436960854733)
	 *
	 * States:
	 *   - DriveToOwnPenaltySpot (1436960854732)
	 *   - GrabBall (1436960880333)
	 *   - DribbleToOppPenaltySpot (1436960962060)
	 *
	 * Vars:
	 */
	bool TransitionCondition1436960984355::evaluate(shared_ptr<RunningPlan> rp)
	{
		/*PROTECTED REGION ID(1436960982644) ENABLED START*/
		return rp->anyChildrenStatus(PlanStatus::Success);
		/*PROTECTED REGION END*/

	}

	//State: GrabBall in Plan: DribbleToPointPlan

	/*
	 *
	 * Transition:
	 *   - Name: MISSING_NAME, ConditionString: , Comment : haveball
	 *
	 * Plans in State:
	 *   - Plan - (Name): InterceptCarefullyDefault, (PlanID): 1427703234654
	 *
	 * Tasks:
	 *   - DefaultTask (1225112227903) (Entrypoint: 1436960854733)
	 *
	 * States:
	 *   - DriveToOwnPenaltySpot (1436960854732)
	 *   - GrabBall (1436960880333)
	 *   - DribbleToOppPenaltySpot (1436960962060)
	 *
	 * Vars:
	 */
	bool TransitionCondition1436960986275::evaluate(shared_ptr<RunningPlan> rp)
	{
		/*PROTECTED REGION ID(1436960984714) ENABLED START*/
		return wm->ball.haveBall();
		/*PROTECTED REGION END*/

	}

	//State: DribbleToOppPenaltySpot in Plan: DribbleToPointPlan

	/*
	 *
	 * Transition:
	 *   - Name: MISSING_NAME, ConditionString: , Comment : lostBall
	 *
	 * Plans in State:
	 *   - Plan - (Name): DribbleToPointDefault, (PlanID): 1414752423981
	 *
	 * Tasks:
	 *   - DefaultTask (1225112227903) (Entrypoint: 1436960854733)
	 *
	 * States:
	 *   - DriveToOwnPenaltySpot (1436960854732)
	 *   - GrabBall (1436960880333)
	 *   - DribbleToOppPenaltySpot (1436960962060)
	 *
	 * Vars:
	 */
	bool TransitionCondition1436960988225::evaluate(shared_ptr<RunningPlan> rp)
	{
		/*PROTECTED REGION ID(1436960986557) ENABLED START*/
		return !wm->ball.haveBall();
		/*PROTECTED REGION END*/

	}

}