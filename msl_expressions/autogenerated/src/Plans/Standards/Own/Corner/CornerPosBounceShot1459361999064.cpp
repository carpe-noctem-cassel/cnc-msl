#include "Plans/Standards/Own/Corner/CornerPosBounceShot1459361999064.h"
using namespace alica;
/*PROTECTED REGION ID(eph1459361999064) ENABLED START*/ //Add additional using directives here
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:CornerPosBounceShot

    /* generated comment
     
     Task: StandardExecuter  -> EntryPoint-ID: 1459362020730

     Task: StandardReceiver  -> EntryPoint-ID: 1459362605142

     Task: Defend  -> EntryPoint-ID: 1459362606949

     */
    shared_ptr<UtilityFunction> UtilityFunction1459361999064::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1459361999064) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

//State: AlignPasser in Plan: CornerPosBounceShot

//State: AlignWall in Plan: CornerPosBounceShot

//State: DefenderWall in Plan: CornerPosBounceShot

}
