#include <iostream>
#include "UtilityFunctionCreator.h"

#include  "Plans/GameStrategy/Other/DropBallPositioning1455537014534.h"

#include  "Plans/Standards/Own/OwnStdSingleRobot1467383326416.h"

#include  "Plans/TestPlans/DribbleTestMOS/DriveStraightViewZigZag1518628181064.h"

#include  "Plans/Calibration/TestRotation1492620432380.h"

#include  "Plans/Attack/AttackPlay1434045709191.h"

#include  "Plans/TestPlans/DribbleControlTest/TestDribbleControlMaster1479905043165.h"

#include  "Plans/TestPlans/DribbleTestMOS/InitialForwardBackward1519032290449.h"

#include  "Plans/TestPlans/MotorControlTest/TestMotorControlMaster1482163489121.h"

#include  "Plans/Standards/Own/Penalty/AfterGame/PenaltyMaster1466973051873.h"

#include  "Plans/GameStrategy/Other/Parking1426695119330.h"

#include  "Plans/GenericStandards/GenericOppStandards1432132075122.h"

#include  "Plans/DribbleCalibration/DribbleCalibration1469108805289.h"

#include  "Plans/Standards/Own/Corner/CornerPosBounceShot1459361999064.h"

#include  "Plans/Attack/TestPlans/TestDriveToMiddle1457434329037.h"

#include  "Plans/Attack/TestPlans/DuelTestMaster1454506180437.h"

#include  "Plans/Standards/Opponent/Penalty/OppInGamePenalty1466968232004.h"

#include  "Plans/Calibration/RotationCalibrationStopWrapper1491404851815.h"

#include  "Plans/Attack/Duel1450178655416.h"

#include  "Plans/CarpetCalibrator1435159127771.h"

#include  "Plans/WM161413992564408.h"

#include  "Plans/Attack/TestPlans/RobotMovementTestPlan1462969665131.h"

#include  "Plans/TestPlans/GoalieMotionTuning/DriveToPost1464189637940.h"

#include  "Plans/GameStrategy/Other/DropBallExecution1455537039421.h"

#include  "Plans/Calibration/MotionCalibration1442919721161.h"

#include  "Plans/TestPlans/DribbleTestMOS/CircleSeeForwards1520679916966.h"

#include  "Plans/Attack/StandardAttack1434046634656.h"

#include  "Plans/Standards/Own/Penalty/InGame/OwnInGamePenalty1466936775181.h"

#include  "Plans/Standards/Opponent/FreeKick/OppFreeKick1445411471122.h"

#include  "Plans/Attack/TestPlans/PassPlan1441106995954.h"

#include  "Plans/TestPlans/DribbleTestMOS/DriveToOppsiteSite1521280800018.h"

#include  "Plans/GameStrategy/Other/SimpleDropBall1426696586622.h"

#include  "Plans/TestPlans/DribbleTestMOS/TestDribbleMOS1518622787399.h"

#include  "Plans/Standards/Own/Corner/CornerBounceShot1459361887233.h"

#include  "Plans/Defence/ReleaseOwnHalf1458033644590.h"

#include  "Plans/Standards/Own/GoalKick/GoalKick1469521732930.h"

#include  "Plans/TestPlans/DribbleControlTest/TestDribbleAroundTheBall1498663554104.h"

#include  "Plans/Penalty/OwnPenalty1431525185678.h"

#include  "Plans/GameStrategy/Other/DroppedBall1426694906399.h"

#include  "Plans/Calibration/RotationCalibration1467396347588.h"

#include  "Plans/Attack/PassPlay1436268896671.h"

#include  "Plans/GameStrategy/Other/WanderPlan1458553921358.h"

#include  "Plans/GameStrategy/Gameplay/DefendPlay1457173681216.h"

#include  "Plans/TestPlans/TestCalculationPlan1478709817405.h"

#include  "Plans/TestPlans/MotorControlTest/PointToPoint1489068076224.h"

#include  "Plans/TwoHoledWall/TwoHoledWallAlign1496753106611.h"

#include  "Plans/TestPlans/DribbleControlTest/TestDribble1498664114905.h"

#include  "Plans/Standards/Own/Corner/CornerExecBounceShot1459362028865.h"

#include  "Plans/Robotcheck/Robotcheck1456756058055.h"

#include  "Plans/Goalie/Test/GoalieDefault1447254438614.h"

#include  "Plans/Attack/Dribble1434049476066.h"

#include  "Plans/TestPlans/DribbleTestMOS/DriveAndTurnToOppositeSite1521283132783.h"

#include  "Plans/Attack/TestPlans/TestCheckGoalKick1449076138236.h"

#include  "Plans/Standards/Own/ThrowIn/ThrowInNearGoal1461237603689.h"

#include  "Plans/GenericStandards/GenericExecute1431522123418.h"

#include  "Plans/Standards/Own/Penalty/AfterGame/AfterGamePenalty1466934340668.h"

#include  "Plans/TestPlans/DribbleTestMOS/DriveZigZagViewZigZag1518623186077.h"

#include  "Plans/Standards/Own/Corner/CornerKick1462373376006.h"

#include  "Plans/Standards/Opponent/OppStandardExecution1457015277573.h"

#include  "Plans/TwoHoledWall/ShootTwoHoledWall1417620189234.h"

#include  "Plans/GenericStandards/GenericOwnStandards1430924951132.h"

#include  "Plans/TestPlans/DribbleTestMOS/DriveZigZagViewStraight1518623233217.h"

#include  "Plans/Standards/Own/KickOff/OwnKickOff1438785376159.h"

#include  "Plans/Defence/Test/TestApproachBallMaster1430324312981.h"

#include  "Plans/Standards/Own/ThrowIn/ThrowInOwnHalf1462360503828.h"

#include  "Plans/TestPlans/DribbleTestMOS/CircleCenter1518624635783.h"

#include  "Plans/Defence/MidfieldDefense1458033329973.h"

#include  "Plans/TestPlans/KickCurveTuning/KickCurveTuning1457698586746.h"

#include  "Plans/Standards/Own/PassIntoPath/PassIntoPath1457530916296.h"

#include  "Plans/Defence/MidfieldBlock1458033620834.h"

#include  "Plans/Attack/FreeZonePassing1508950989519.h"

#include  "Plans/Standards/Own/FreeKick/Test/TestFreeKickOppHalfMaster1464532006730.h"

#include  "Plans/Standards/Opponent/FreeKick/StopRobots1457015643757.h"

#include  "Plans/TestPlans/DribbleTestMOS/DribbleTestMaster1518866346673.h"

#include  "Plans/TwoHoledWall/TwoHoledWallMaster1417621468963.h"

#include  "Plans/GameStrategy/Gameplay/GamePlay1457173546734.h"

#include  "Plans/Standards/Own/FreeKick/OwnFreeKickInOppHalf1464531946023.h"

#include  "Plans/TestPlans/RobotMovement/RobotMovementTest1473862711641.h"

#include  "Plans/Attack/TestPlans/TestPassPointMaster1441106724156.h"

#include  "Plans/Standards/Own/FreeKick/FreekickOwnHalf1464779892293.h"

#include  "Plans/Attack/StandardKickOff1438777024734.h"

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

            case 1455537014534:
                return make_shared<UtilityFunction1455537014534>();
                break;

            case 1467383326416:
                return make_shared<UtilityFunction1467383326416>();
                break;

            case 1518628181064:
                return make_shared<UtilityFunction1518628181064>();
                break;

            case 1492620432380:
                return make_shared<UtilityFunction1492620432380>();
                break;

            case 1434045709191:
                return make_shared<UtilityFunction1434045709191>();
                break;

            case 1479905043165:
                return make_shared<UtilityFunction1479905043165>();
                break;

            case 1519032290449:
                return make_shared<UtilityFunction1519032290449>();
                break;

            case 1482163489121:
                return make_shared<UtilityFunction1482163489121>();
                break;

            case 1466973051873:
                return make_shared<UtilityFunction1466973051873>();
                break;

            case 1426695119330:
                return make_shared<UtilityFunction1426695119330>();
                break;

            case 1432132075122:
                return make_shared<UtilityFunction1432132075122>();
                break;

            case 1469108805289:
                return make_shared<UtilityFunction1469108805289>();
                break;

            case 1459361999064:
                return make_shared<UtilityFunction1459361999064>();
                break;

            case 1457434329037:
                return make_shared<UtilityFunction1457434329037>();
                break;

            case 1454506180437:
                return make_shared<UtilityFunction1454506180437>();
                break;

            case 1466968232004:
                return make_shared<UtilityFunction1466968232004>();
                break;

            case 1491404851815:
                return make_shared<UtilityFunction1491404851815>();
                break;

            case 1450178655416:
                return make_shared<UtilityFunction1450178655416>();
                break;

            case 1435159127771:
                return make_shared<UtilityFunction1435159127771>();
                break;

            case 1413992564408:
                return make_shared<UtilityFunction1413992564408>();
                break;

            case 1462969665131:
                return make_shared<UtilityFunction1462969665131>();
                break;

            case 1464189637940:
                return make_shared<UtilityFunction1464189637940>();
                break;

            case 1455537039421:
                return make_shared<UtilityFunction1455537039421>();
                break;

            case 1442919721161:
                return make_shared<UtilityFunction1442919721161>();
                break;

            case 1520679916966:
                return make_shared<UtilityFunction1520679916966>();
                break;

            case 1434046634656:
                return make_shared<UtilityFunction1434046634656>();
                break;

            case 1466936775181:
                return make_shared<UtilityFunction1466936775181>();
                break;

            case 1445411471122:
                return make_shared<UtilityFunction1445411471122>();
                break;

            case 1441106995954:
                return make_shared<UtilityFunction1441106995954>();
                break;

            case 1521280800018:
                return make_shared<UtilityFunction1521280800018>();
                break;

            case 1426696586622:
                return make_shared<UtilityFunction1426696586622>();
                break;

            case 1518622787399:
                return make_shared<UtilityFunction1518622787399>();
                break;

            case 1459361887233:
                return make_shared<UtilityFunction1459361887233>();
                break;

            case 1458033644590:
                return make_shared<UtilityFunction1458033644590>();
                break;

            case 1469521732930:
                return make_shared<UtilityFunction1469521732930>();
                break;

            case 1498663554104:
                return make_shared<UtilityFunction1498663554104>();
                break;

            case 1431525185678:
                return make_shared<UtilityFunction1431525185678>();
                break;

            case 1426694906399:
                return make_shared<UtilityFunction1426694906399>();
                break;

            case 1467396347588:
                return make_shared<UtilityFunction1467396347588>();
                break;

            case 1436268896671:
                return make_shared<UtilityFunction1436268896671>();
                break;

            case 1458553921358:
                return make_shared<UtilityFunction1458553921358>();
                break;

            case 1457173681216:
                return make_shared<UtilityFunction1457173681216>();
                break;

            case 1478709817405:
                return make_shared<UtilityFunction1478709817405>();
                break;

            case 1489068076224:
                return make_shared<UtilityFunction1489068076224>();
                break;

            case 1496753106611:
                return make_shared<UtilityFunction1496753106611>();
                break;

            case 1498664114905:
                return make_shared<UtilityFunction1498664114905>();
                break;

            case 1459362028865:
                return make_shared<UtilityFunction1459362028865>();
                break;

            case 1456756058055:
                return make_shared<UtilityFunction1456756058055>();
                break;

            case 1447254438614:
                return make_shared<UtilityFunction1447254438614>();
                break;

            case 1434049476066:
                return make_shared<UtilityFunction1434049476066>();
                break;

            case 1521283132783:
                return make_shared<UtilityFunction1521283132783>();
                break;

            case 1449076138236:
                return make_shared<UtilityFunction1449076138236>();
                break;

            case 1461237603689:
                return make_shared<UtilityFunction1461237603689>();
                break;

            case 1431522123418:
                return make_shared<UtilityFunction1431522123418>();
                break;

            case 1466934340668:
                return make_shared<UtilityFunction1466934340668>();
                break;

            case 1518623186077:
                return make_shared<UtilityFunction1518623186077>();
                break;

            case 1462373376006:
                return make_shared<UtilityFunction1462373376006>();
                break;

            case 1457015277573:
                return make_shared<UtilityFunction1457015277573>();
                break;

            case 1417620189234:
                return make_shared<UtilityFunction1417620189234>();
                break;

            case 1430924951132:
                return make_shared<UtilityFunction1430924951132>();
                break;

            case 1518623233217:
                return make_shared<UtilityFunction1518623233217>();
                break;

            case 1438785376159:
                return make_shared<UtilityFunction1438785376159>();
                break;

            case 1430324312981:
                return make_shared<UtilityFunction1430324312981>();
                break;

            case 1462360503828:
                return make_shared<UtilityFunction1462360503828>();
                break;

            case 1518624635783:
                return make_shared<UtilityFunction1518624635783>();
                break;

            case 1458033329973:
                return make_shared<UtilityFunction1458033329973>();
                break;

            case 1457698586746:
                return make_shared<UtilityFunction1457698586746>();
                break;

            case 1457530916296:
                return make_shared<UtilityFunction1457530916296>();
                break;

            case 1458033620834:
                return make_shared<UtilityFunction1458033620834>();
                break;

            case 1508950989519:
                return make_shared<UtilityFunction1508950989519>();
                break;

            case 1464532006730:
                return make_shared<UtilityFunction1464532006730>();
                break;

            case 1457015643757:
                return make_shared<UtilityFunction1457015643757>();
                break;

            case 1518866346673:
                return make_shared<UtilityFunction1518866346673>();
                break;

            case 1417621468963:
                return make_shared<UtilityFunction1417621468963>();
                break;

            case 1457173546734:
                return make_shared<UtilityFunction1457173546734>();
                break;

            case 1464531946023:
                return make_shared<UtilityFunction1464531946023>();
                break;

            case 1473862711641:
                return make_shared<UtilityFunction1473862711641>();
                break;

            case 1441106724156:
                return make_shared<UtilityFunction1441106724156>();
                break;

            case 1464779892293:
                return make_shared<UtilityFunction1464779892293>();
                break;

            case 1438777024734:
                return make_shared<UtilityFunction1438777024734>();
                break;

            default:
                cerr << "UtilityFunctionCreator: Unknown utility requested: " << utilityfunctionConfId << endl;
                throw new exception();
                break;
        }
    }

}
