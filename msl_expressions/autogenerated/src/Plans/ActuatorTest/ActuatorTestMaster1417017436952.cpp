#include "Plans/ActuatorTest/ActuatorTestMaster1417017436952.h"
using namespace alica;
/*PROTECTED REGION ID(eph1417017436952) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:ActuatorTestMaster

    /* generated comment
     
     Task: DefaultTask  -> EntryPoint-ID: 1417017436954

     */
    shared_ptr<UtilityFunction> UtilityFunction1417017436952::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1417017436952) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Stop in Plan: ActuatorTestMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation start 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1417017436954)
     *
     * States:
     *   - Stop (1417017436953)
     *   - DriveForwardAndActuate (1417017460581)
     *   - Joystick (1435321198760)
     *
     * Vars:
     */
    bool TransitionCondition1417017585255::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1417017583911) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::Start);

        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situtaion == joystick 
     *
     * Plans in State: 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1417017436954)
     *
     * States:
     *   - Stop (1417017436953)
     *   - DriveForwardAndActuate (1417017460581)
     *   - Joystick (1435321198760)
     *
     * Vars:
     */
    bool TransitionCondition1435321214610::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1435321213211) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::Joystick);
        /*PROTECTED REGION END*/

    }

    //State: DriveForwardAndActuate in Plan: ActuatorTestMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situation stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): ActuateDefault, (PlanID): 1417017552846 				
     *   - Plan - (Name): DriveForwardDefault, (PlanID): 1417017580650 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1417017436954)
     *
     * States:
     *   - Stop (1417017436953)
     *   - DriveForwardAndActuate (1417017460581)
     *   - Joystick (1435321198760)
     *
     * Vars:
     */
    bool TransitionCondition1427721261678::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1427721259649) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::Stop);
        /*PROTECTED REGION END*/

    }

    //State: Joystick in Plan: ActuatorTestMaster

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : situatio == stop 
     *
     * Plans in State: 				
     *   - Plan - (Name): Joystick, (PlanID): 1426695479346 
     *
     * Tasks: 
     *   - DefaultTask (1225112227903) (Entrypoint: 1417017436954)
     *
     * States:
     *   - Stop (1417017436953)
     *   - DriveForwardAndActuate (1417017460581)
     *   - Joystick (1435321198760)
     *
     * Vars:
     */
    bool TransitionCondition1435321221937::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1435321220268) ENABLED START*/
        return wm->game.checkSituation(msl::Situation::Stop);
        /*PROTECTED REGION END*/

    }

}
