#include <iostream>
#include "UtilityFunctionCreator.h"

#include  "Plans/GameStrategy/Other/Parking1426695119330.h"

#include  "Plans/Attack/Dribble1434049476066.h"

#include  "Plans/GenericStandards/GenericOppStandards1432132075122.h"

#include  "Plans/Example/ExamplePlan1433938652021.h"

#include  "Plans/GenericStandards/GenericExecute1431522123418.h"

#include  "Plans/Attack/StandardAttack1434046634656.h"

#include  "Plans/Attack/TestPlans/DribbleToPointPlan1436960829485.h"

#include  "Plans/Attack/AttackPlay1434045709191.h"

#include  "Plans/Attack/RunFree1434115664325.h"

#include  "Plans/Attack/TestPlans/TestPassPointMaster1441106724156.h"

#include  "Plans/WM161413992564408.h"

#include  "Plans/TwoHoledWall/TwoHoledWallMaster1417621468963.h"

#include  "Plans/Attack/TestPlans/PassPlan1441106995954.h"

#include  "Plans/Attack/TestPlans/TestAttackPlan1436960675873.h"

#include  "Plans/Attack/AttackSupportPlan1434046705214.h"

#include  "Plans/Attack/TestPlans/TestDribblePlan1437902404050.h"

#include  "Plans/GameStrategy/Gameplay/Gameplay1426694853089.h"

#include  "Plans/GameStrategy/Other/SimpleDropBall1426696586622.h"

#include  "Plans/Standards/Opponent/FreeKick/OppFreeKick1445411471122.h"

#include  "Plans/Defence/Test/TestApproachBallMaster1430324312981.h"

#include  "Plans/Standards/Own/KickOff/OwnKickOff1438785376159.h"

#include  "Plans/ActuatorTest/ActuatorTestMaster1417017436952.h"

#include  "Plans/GameStrategy/Other/DroppedBall1426694906399.h"

#include  "Plans/Attack/PassPlay1436268896671.h"

#include  "Plans/TwoHoledWall/ShootTwoHoledWall1417620189234.h"

#include  "Plans/Attack/StandardKickOff1438777024734.h"

#include  "Plans/GenericStandards/GenericDefend1432133473779.h"

#include  "Plans/Penalty/OwnPenalty1431525185678.h"

#include  "Plans/Attack/Tackle1434116965565.h"

#include  "Plans/GenericStandards/GenericOwnStandards1430924951132.h"

#include  "Plans/GenericStandards/DummyMasterPlan1432139066765.h"

#include  "Plans/CarpetCalibrator1435159127771.h"

#include  "Plans/Attack/TestPlans/AttackOppGoalPlan1437902649389.h"

#include  "Plans/Defence/MidFieldDefense1441108604411.h"

using namespace std;
using namespace alicaAutogenerated;
namespace alica
{

    UtilityFunctionCreator::~UtilityFunctionCreator()
    {
    }

    UtilityFunctionCreator::UtilityFunctionCreator()
    {
    }

    shared_ptr<BasicUtilityFunction> UtilityFunctionCreator::createUtility(long utilityfunctionConfId)
    {
        switch (utilityfunctionConfId)
        {

            case 1426695119330:
                return make_shared<UtilityFunction1426695119330>();
                break;

            case 1434049476066:
                return make_shared<UtilityFunction1434049476066>();
                break;

            case 1432132075122:
                return make_shared<UtilityFunction1432132075122>();
                break;

            case 1433938652021:
                return make_shared<UtilityFunction1433938652021>();
                break;

            case 1431522123418:
                return make_shared<UtilityFunction1431522123418>();
                break;

            case 1434046634656:
                return make_shared<UtilityFunction1434046634656>();
                break;

            case 1436960829485:
                return make_shared<UtilityFunction1436960829485>();
                break;

            case 1434045709191:
                return make_shared<UtilityFunction1434045709191>();
                break;

            case 1434115664325:
                return make_shared<UtilityFunction1434115664325>();
                break;

            case 1441106724156:
                return make_shared<UtilityFunction1441106724156>();
                break;

            case 1413992564408:
                return make_shared<UtilityFunction1413992564408>();
                break;

            case 1417621468963:
                return make_shared<UtilityFunction1417621468963>();
                break;

            case 1441106995954:
                return make_shared<UtilityFunction1441106995954>();
                break;

            case 1436960675873:
                return make_shared<UtilityFunction1436960675873>();
                break;

            case 1434046705214:
                return make_shared<UtilityFunction1434046705214>();
                break;

            case 1437902404050:
                return make_shared<UtilityFunction1437902404050>();
                break;

            case 1426694853089:
                return make_shared<UtilityFunction1426694853089>();
                break;

            case 1426696586622:
                return make_shared<UtilityFunction1426696586622>();
                break;

            case 1445411471122:
                return make_shared<UtilityFunction1445411471122>();
                break;

            case 1430324312981:
                return make_shared<UtilityFunction1430324312981>();
                break;

            case 1438785376159:
                return make_shared<UtilityFunction1438785376159>();
                break;

            case 1417017436952:
                return make_shared<UtilityFunction1417017436952>();
                break;

            case 1426694906399:
                return make_shared<UtilityFunction1426694906399>();
                break;

            case 1436268896671:
                return make_shared<UtilityFunction1436268896671>();
                break;

            case 1417620189234:
                return make_shared<UtilityFunction1417620189234>();
                break;

            case 1438777024734:
                return make_shared<UtilityFunction1438777024734>();
                break;

            case 1432133473779:
                return make_shared<UtilityFunction1432133473779>();
                break;

            case 1431525185678:
                return make_shared<UtilityFunction1431525185678>();
                break;

            case 1434116965565:
                return make_shared<UtilityFunction1434116965565>();
                break;

            case 1430924951132:
                return make_shared<UtilityFunction1430924951132>();
                break;

            case 1432139066765:
                return make_shared<UtilityFunction1432139066765>();
                break;

            case 1435159127771:
                return make_shared<UtilityFunction1435159127771>();
                break;

            case 1437902649389:
                return make_shared<UtilityFunction1437902649389>();
                break;

            case 1441108604411:
                return make_shared<UtilityFunction1441108604411>();
                break;

            default:
                cerr << "UtilityFunctionCreator: Unknown utility requested: " << utilityfunctionConfId << endl;
                throw new exception();
                break;
        }
    }

}
