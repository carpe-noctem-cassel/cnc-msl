#include "Plans/DribbleCalibration/DribbleCalibration1469108805289.h"
using namespace alica;
/*PROTECTED REGION ID(eph1469108805289) ENABLED START*/ //Add additional using directives here
#include <MSLWorldModel.h>
#include <Game.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:DribbleCalibration

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1469108805291

     */
    shared_ptr<UtilityFunction> UtilityFunction1469108805289::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1469108805289) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Stop in Plan: DribbleCalibration

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Start 
     *
     * Plans in State: 				
     *   - Plan - (Name): StopDefault, (PlanID): 1413992626194 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1469108805291)
     *
     * States:
     *   - Stop (1469108805290)
     *   - Calibration Forward (1469108950942)
     *   - Calibaration Backward (1469108971711)
     *   - Calibration Rotation Right (1469108996737)
     *   - finished (1469109142048)
     *   - Calibration Take Ball (1469109218874)
     *   - Calibration Ball Holding (1469284166290)
     *   - Calibration Rotation Left (1485356788982)
     *
     * Vars:
     */
    bool TransitionCondition1469109263885::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469109261763) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Start);
        /*PROTECTED REGION END*/

    }

    //State: Calibration Forward in Plan: DribbleCalibration

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Calibration Forward finished 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleCalibrationForward, (PlanID): 1482339937439 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1469108805291)
     *
     * States:
     *   - Stop (1469108805290)
     *   - Calibration Forward (1469108950942)
     *   - Calibaration Backward (1469108971711)
     *   - Calibration Rotation Right (1469108996737)
     *   - finished (1469109142048)
     *   - Calibration Take Ball (1469109218874)
     *   - Calibration Ball Holding (1469284166290)
     *   - Calibration Rotation Left (1485356788982)
     *
     * Vars:
     */
    bool TransitionCondition1469109050023::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469109046400) ENABLED START*/
        return rp->anyChildrenStatus(alica::PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleCalibrationForward, (PlanID): 1482339937439 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1469108805291)
     *
     * States:
     *   - Stop (1469108805290)
     *   - Calibration Forward (1469108950942)
     *   - Calibaration Backward (1469108971711)
     *   - Calibration Rotation Right (1469108996737)
     *   - finished (1469109142048)
     *   - Calibration Take Ball (1469109218874)
     *   - Calibration Ball Holding (1469284166290)
     *   - Calibration Rotation Left (1485356788982)
     *
     * Vars:
     */
    bool TransitionCondition1469109281934::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469109279849) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Stop);
        /*PROTECTED REGION END*/

    }

    //State: Calibaration Backward in Plan: DribbleCalibration

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleCalibrationBackward, (PlanID): 1482339837722 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1469108805291)
     *
     * States:
     *   - Stop (1469108805290)
     *   - Calibration Forward (1469108950942)
     *   - Calibaration Backward (1469108971711)
     *   - Calibration Rotation Right (1469108996737)
     *   - finished (1469109142048)
     *   - Calibration Take Ball (1469109218874)
     *   - Calibration Ball Holding (1469284166290)
     *   - Calibration Rotation Left (1485356788982)
     *
     * Vars:
     */
    bool TransitionCondition1469109063861::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469109061857) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Stop);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Calibration Backward finished 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleCalibrationBackward, (PlanID): 1482339837722 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1469108805291)
     *
     * States:
     *   - Stop (1469108805290)
     *   - Calibration Forward (1469108950942)
     *   - Calibaration Backward (1469108971711)
     *   - Calibration Rotation Right (1469108996737)
     *   - finished (1469109142048)
     *   - Calibration Take Ball (1469109218874)
     *   - Calibration Ball Holding (1469284166290)
     *   - Calibration Rotation Left (1485356788982)
     *
     * Vars:
     */
    bool TransitionCondition1485356846217::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1485356843859) ENABLED START*/
        return rp->anyChildrenStatus(alica::PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: Calibration Rotation Right in Plan: DribbleCalibration

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 				
     *   - Plan - (Name): DribbleCalibrationRotateRight, (PlanID): 1485355250017 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1469108805291)
     *
     * States:
     *   - Stop (1469108805290)
     *   - Calibration Forward (1469108950942)
     *   - Calibaration Backward (1469108971711)
     *   - Calibration Rotation Right (1469108996737)
     *   - finished (1469109142048)
     *   - Calibration Take Ball (1469109218874)
     *   - Calibration Ball Holding (1469284166290)
     *   - Calibration Rotation Left (1485356788982)
     *
     * Vars:
     */
    bool TransitionCondition1469109068711::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469109066452) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Stop);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Calibration Rotation Right finished 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 				
     *   - Plan - (Name): DribbleCalibrationRotateRight, (PlanID): 1485355250017 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1469108805291)
     *
     * States:
     *   - Stop (1469108805290)
     *   - Calibration Forward (1469108950942)
     *   - Calibaration Backward (1469108971711)
     *   - Calibration Rotation Right (1469108996737)
     *   - finished (1469109142048)
     *   - Calibration Take Ball (1469109218874)
     *   - Calibration Ball Holding (1469284166290)
     *   - Calibration Rotation Left (1485356788982)
     *
     * Vars:
     */
    bool TransitionCondition1485356814622::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1485356813423) ENABLED START*/
        return rp->anyChildrenStatus(alica::PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: finished in Plan: DribbleCalibration

    //State: Calibration Take Ball in Plan: DribbleCalibration

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Calibration Take Ball finished 
     *
     * Plans in State: 				
     *   - Plan - (Name): CalibrationTakeBallDefault, (PlanID): 1469109486033 				
     *   - Plan - (Name): DribbleControlNoBall, (PlanID): 1450175539163 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1469108805291)
     *
     * States:
     *   - Stop (1469108805290)
     *   - Calibration Forward (1469108950942)
     *   - Calibaration Backward (1469108971711)
     *   - Calibration Rotation Right (1469108996737)
     *   - finished (1469109142048)
     *   - Calibration Take Ball (1469109218874)
     *   - Calibration Ball Holding (1469284166290)
     *   - Calibration Rotation Left (1485356788982)
     *
     * Vars:
     */
    bool TransitionCondition1469109265377::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469109264181) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): CalibrationTakeBallDefault, (PlanID): 1469109486033 				
     *   - Plan - (Name): DribbleControlNoBall, (PlanID): 1450175539163 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1469108805291)
     *
     * States:
     *   - Stop (1469108805290)
     *   - Calibration Forward (1469108950942)
     *   - Calibaration Backward (1469108971711)
     *   - Calibration Rotation Right (1469108996737)
     *   - finished (1469109142048)
     *   - Calibration Take Ball (1469109218874)
     *   - Calibration Ball Holding (1469284166290)
     *   - Calibration Rotation Left (1485356788982)
     *
     * Vars:
     */
    bool TransitionCondition1469109279649::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469109277626) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Stop);
        /*PROTECTED REGION END*/

    }

    //State: Calibration Ball Holding in Plan: DribbleCalibration

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): CalibrationBallHoldingDefault, (PlanID): 1469284324012 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1469108805291)
     *
     * States:
     *   - Stop (1469108805290)
     *   - Calibration Forward (1469108950942)
     *   - Calibaration Backward (1469108971711)
     *   - Calibration Rotation Right (1469108996737)
     *   - finished (1469109142048)
     *   - Calibration Take Ball (1469109218874)
     *   - Calibration Ball Holding (1469284166290)
     *   - Calibration Rotation Left (1485356788982)
     *
     * Vars:
     */
    bool TransitionCondition1469284199355::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469284197329) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Stop);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Calibration Ball Holding finished 
     *
     * Plans in State: 				
     *   - Plan - (Name): CalibrationBallHoldingDefault, (PlanID): 1469284324012 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1469108805291)
     *
     * States:
     *   - Stop (1469108805290)
     *   - Calibration Forward (1469108950942)
     *   - Calibaration Backward (1469108971711)
     *   - Calibration Rotation Right (1469108996737)
     *   - finished (1469109142048)
     *   - Calibration Take Ball (1469109218874)
     *   - Calibration Ball Holding (1469284166290)
     *   - Calibration Rotation Left (1485356788982)
     *
     * Vars:
     */
    bool TransitionCondition1469284201761::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1469284199867) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: Calibration Rotation Left in Plan: DribbleCalibration

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 				
     *   - Plan - (Name): DribbleCalibrationRotateLeft, (PlanID): 1485355187631 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1469108805291)
     *
     * States:
     *   - Stop (1469108805290)
     *   - Calibration Forward (1469108950942)
     *   - Calibaration Backward (1469108971711)
     *   - Calibration Rotation Right (1469108996737)
     *   - finished (1469109142048)
     *   - Calibration Take Ball (1469109218874)
     *   - Calibration Ball Holding (1469284166290)
     *   - Calibration Rotation Left (1485356788982)
     *
     * Vars:
     */
    bool TransitionCondition1485356818666::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1485356815055) ENABLED START*/
        return wm->game->checkSituation(msl::Situation::Stop);
        /*PROTECTED REGION END*/

    }

}
