#include "Plans/TwoHoledWall/TwoHoledWallMaster1417621468963.h"
using namespace alica;
/*PROTECTED REGION ID(eph1417621468963) ENABLED START*/ //Add additional using directives here
#include "SigFault.h"
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:TwoHoledWallMaster

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1417621468965

     */
    shared_ptr<UtilityFunction> UtilityFunction1417621468963::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1417621468963) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Stop in Plan: TwoHoledWallMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == start 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1417621468965)
     *
     * States:
     *   - Stop (1417621468964)
     *   - DriveToOrigin (1417621580835)
     *   - Score (1417621589489)
     *   - Joysick (1422464768858)
     *
     * Vars:
     */
    bool TransitionCondition1417621600501::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1417621598841) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Start);
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
     *   - DefaultTask (1225112227903) (Entrypoint: 1417621468965)
     *
     * States:
     *   - Stop (1417621468964)
     *   - DriveToOrigin (1417621580835)
     *   - Score (1417621589489)
     *   - Joysick (1422464768858)
     *
     * Vars:
     */
    bool TransitionCondition1422464821945::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1422464819985) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Joystick);
        /*PROTECTED REGION END*/

    }

    //State: DriveToOrigin in Plan: TwoHoledWallMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : anyChildSucces 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToPointDefault, (PlanID): 1417620583364 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1417621468965)
     *
     * States:
     *   - Stop (1417621468964)
     *   - DriveToOrigin (1417621580835)
     *   - Score (1417621589489)
     *   - Joysick (1422464768858)
     *
     * Vars:
     */
    bool TransitionCondition1417621604870::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1417621602033) ENABLED START*/
        cout << "TwoHoledWallMaster: " << rp->anyChildrenStatus(PlanStatus::Success) << endl;
//    	cout << "TwoHoledWallMaster: " << segfaultdebug::get_stacktrace() << endl;
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToPointDefault, (PlanID): 1417620583364 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1417621468965)
     *
     * States:
     *   - Stop (1417621468964)
     *   - DriveToOrigin (1417621580835)
     *   - Score (1417621589489)
     *   - Joysick (1422464768858)
     *
     * Vars:
     */
    bool TransitionCondition1417621611163::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1417621607473) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Stop);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == joystick 
     *
     * Plans in State: 				
     *   - Plan - (Name): DriveToPointDefault, (PlanID): 1417620583364 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1417621468965)
     *
     * States:
     *   - Stop (1417621468964)
     *   - DriveToOrigin (1417621580835)
     *   - Score (1417621589489)
     *   - Joysick (1422464768858)
     *
     * Vars:
     */
    bool TransitionCondition1422464825529::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1422464823873) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Joystick);
        /*PROTECTED REGION END*/

    }

    //State: Score in Plan: TwoHoledWallMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : anyChildSucces || situation == stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShootTwoHoledWall, (PlanID): 1417620189234 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1417621468965)
     *
     * States:
     *   - Stop (1417621468964)
     *   - DriveToOrigin (1417621580835)
     *   - Score (1417621589489)
     *   - Joysick (1422464768858)
     *
     * Vars:
     */
    bool TransitionCondition1417621607305::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1417621605061) ENABLED START*/

        return wm->game->checkSituation(msl::Situation::Stop) || rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation == joystick 
     *
     * Plans in State: 				
     *   - Plan - (Name): ShootTwoHoledWall, (PlanID): 1417620189234 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1417621468965)
     *
     * States:
     *   - Stop (1417621468964)
     *   - DriveToOrigin (1417621580835)
     *   - Score (1417621589489)
     *   - Joysick (1422464768858)
     *
     * Vars:
     */
    bool TransitionCondition1422464818034::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1422464816725) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Joystick);
        /*PROTECTED REGION END*/

    }

    //State: Joysick in Plan: TwoHoledWallMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation != joystick 
     *
     * Plans in State: 				
     *   - Plan - (Name): JoystickDefault, (PlanID): 1421854995808 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1417621468965)
     *
     * States:
     *   - Stop (1417621468964)
     *   - DriveToOrigin (1417621580835)
     *   - Score (1417621589489)
     *   - Joysick (1422464768858)
     *
     * Vars:
     */
    bool TransitionCondition1422464875980::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1422464874668) ENABLED START*/
        return !(wm->game->checkSituation(msl::Situation::Joystick));
        /*PROTECTED REGION END*/

    }

}
