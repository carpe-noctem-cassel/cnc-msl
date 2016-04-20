#include "Plans/Penalty/OwnPenalty1431525185678.h"
using namespace alica;
/*PROTECTED REGION ID(eph1431525185678) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:OwnPenalty

    /* generated comment
     
     Task: ExecuteStandard  -> EntryPoint-ID: 1431525245110

     Task: DefaultTask  -> EntryPoint-ID: 1431526909013

     */
    shared_ptr<UtilityFunction> UtilityFunction1431525185678::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1431525185678) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: DriveToMiddle in Plan: OwnPenalty

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any child success 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToPenaltyStartDefault, (PlanID): 1459609537461 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1431525245110)
     *   - DefaultTask (1225112227903) (Entrypoint: 1431526909013)
     *
     * States:
     *   - DriveToMiddle (1431525245109)
     *   - GrabBall (1431526626723)
     *   - AlignAndShoot (1431526769660)
     *   - Stop (1431526917231)
     *   - Success (1432744233327)
     *   - WaitForStart (1433338496106)
     *
     * Vars:
     */
    bool TransitionCondition1433338526794::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1433338525417) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: GrabBall in Plan: OwnPenalty

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment :  
     *
     * Plans in State: 				
     *   - Plan - (Name): InterceptCarefullyDefault, (PlanID): 1427703234654 				
     *   - Plan - (Name): DribbleControlNoBall, (PlanID): 1450175539163 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1431525245110)
     *   - DefaultTask (1225112227903) (Entrypoint: 1431526909013)
     *
     * States:
     *   - DriveToMiddle (1431525245109)
     *   - GrabBall (1431526626723)
     *   - AlignAndShoot (1431526769660)
     *   - Stop (1431526917231)
     *   - Success (1432744233327)
     *   - WaitForStart (1433338496106)
     *
     * Vars:
     */
    bool TransitionCondition1431526792158::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1431526790723) ENABLED START*/
//        cout << "have ball " << wm->ball.haveBall() << endl;
        return wm->ball.haveBall();
        /*PROTECTED REGION END*/

    }

    //State: AlignAndShoot in Plan: OwnPenalty

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : anyChildSuccess 
     *
     * Plans in State: 				
     *   - Plan - (Name): PenaltyAlignAndShootDefault, (PlanID): 1431531542052 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1431525245110)
     *   - DefaultTask (1225112227903) (Entrypoint: 1431526909013)
     *
     * States:
     *   - DriveToMiddle (1431525245109)
     *   - GrabBall (1431526626723)
     *   - AlignAndShoot (1431526769660)
     *   - Stop (1431526917231)
     *   - Success (1432744233327)
     *   - WaitForStart (1433338496106)
     *
     * Vars:
     */
    bool TransitionCondition1432744250382::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1432744248119) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : not have ball 
     *
     * Plans in State: 				
     *   - Plan - (Name): PenaltyAlignAndShootDefault, (PlanID): 1431531542052 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1431525245110)
     *   - DefaultTask (1225112227903) (Entrypoint: 1431526909013)
     *
     * States:
     *   - DriveToMiddle (1431525245109)
     *   - GrabBall (1431526626723)
     *   - AlignAndShoot (1431526769660)
     *   - Stop (1431526917231)
     *   - Success (1432744233327)
     *   - WaitForStart (1433338496106)
     *
     * Vars:
     */
    bool TransitionCondition1433337666610::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1433337664670) ENABLED START*/
        return !wm->ball.haveBall();
        /*PROTECTED REGION END*/

    }

    //State: Stop in Plan: OwnPenalty

    //State: Success in Plan: OwnPenalty

    //State: WaitForStart in Plan: OwnPenalty

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : start signal received 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 				
     *   - Plan - (Name): ShovelSelectLowKick, (PlanID): 1435156714286 
     *
     * Tasks: 
     *   - ExecuteStandard (1439997010902) (Entrypoint: 1431525245110)
     *   - DefaultTask (1225112227903) (Entrypoint: 1431526909013)
     *
     * States:
     *   - DriveToMiddle (1431525245109)
     *   - GrabBall (1431526626723)
     *   - AlignAndShoot (1431526769660)
     *   - Stop (1431526917231)
     *   - Success (1432744233327)
     *   - WaitForStart (1433338496106)
     *
     * Vars:
     */
    bool TransitionCondition1433338530469::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1433338528647) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::Start);
        /*PROTECTED REGION END*/

    }

}
