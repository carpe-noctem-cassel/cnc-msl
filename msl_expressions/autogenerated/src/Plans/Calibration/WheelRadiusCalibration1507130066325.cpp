#include "Plans/Calibration/WheelRadiusCalibration1507130066325.h"
using namespace alica;
/*PROTECTED REGION ID(eph1507130066325) ENABLED START*/ //Add additional using directives here
#include <MSLWorldModel.h>
#include <Game.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:WheelRadiusCalibration

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1507130066327

     */
    shared_ptr<UtilityFunction> UtilityFunction1507130066325::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1507130066325) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Start in Plan: WheelRadiusCalibration

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : start signal -> success 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1507130066327)
     *
     * States:
     *   - Start (1507130066326)
     *   - Drive (1507130150009)
     *   - MeasureAndConfigure (1507130223303)
     *   - Finished (1507130989734)
     *   - RestartMotion (1507131359921)
     *
     * Vars:
     */
    bool TransitionCondition1507130219773::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1507130218746) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Start);
        /*PROTECTED REGION END*/

    }

    //State: Drive in Plan: WheelRadiusCalibration

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : AfterDriving -> success 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveForwardDefault, (PlanID): 1507131285711 				
     *   - Plan - (Name): MeasureDistanceDefault, (PlanID): 1508940977696 				
     *   - Plan - (Name): CountDownDefault, (PlanID): 1508941007133 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1507130066327)
     *
     * States:
     *   - Start (1507130066326)
     *   - Drive (1507130150009)
     *   - MeasureAndConfigure (1507130223303)
     *   - Finished (1507130989734)
     *   - RestartMotion (1507131359921)
     *
     * Vars:
     */
    bool TransitionCondition1507131120023::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1507131118429) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: MeasureAndConfigure in Plan: WheelRadiusCalibration

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : results are okay -> success 
     *
     * Plans in State: 				
     *   - Plan - (Name): MeasureAndConfigureDefault, (PlanID): 1507131484850 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1507130066327)
     *
     * States:
     *   - Start (1507130066326)
     *   - Drive (1507130150009)
     *   - MeasureAndConfigure (1507130223303)
     *   - Finished (1507130989734)
     *   - RestartMotion (1507131359921)
     *
     * Vars:
     */
    bool TransitionCondition1507131122842::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1507131121008) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : results are not good enough -> failure 
     *
     * Plans in State: 				
     *   - Plan - (Name): MeasureAndConfigureDefault, (PlanID): 1507131484850 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1507130066327)
     *
     * States:
     *   - Start (1507130066326)
     *   - Drive (1507130150009)
     *   - MeasureAndConfigure (1507130223303)
     *   - Finished (1507130989734)
     *   - RestartMotion (1507131359921)
     *
     * Vars:
     */
    bool TransitionCondition1507131367115::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1507131365490) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Failed);
        /*PROTECTED REGION END*/

    }

    //State: Finished in Plan: WheelRadiusCalibration

    //State: RestartMotion in Plan: WheelRadiusCalibration

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : INSTANT SUCCESS!!! 
     *
     * Plans in State: 				
     *   - Plan - (Name): RestartMotionDefault, (PlanID): 1472657588489 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1507130066327)
     *
     * States:
     *   - Start (1507130066326)
     *   - Drive (1507130150009)
     *   - MeasureAndConfigure (1507130223303)
     *   - Finished (1507130989734)
     *   - RestartMotion (1507131359921)
     *
     * Vars:
     */
    bool TransitionCondition1507131368562::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1507131367548) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

}
