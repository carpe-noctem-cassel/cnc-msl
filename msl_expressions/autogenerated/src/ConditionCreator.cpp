#include "ConditionCreator.h"

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

using namespace alicaAutogenerated;
namespace alica
{

    ConditionCreator::ConditionCreator()
    {
    }
    ConditionCreator::~ConditionCreator()
    {
    }

    shared_ptr<BasicCondition> ConditionCreator::createConditions(long conditionConfId)
    {
        switch (conditionConfId)
        {

            case 1467384214949:

                return make_shared<TransitionCondition1467384214949>();

                break;

            case 1467384216416:

                return make_shared<TransitionCondition1467384216416>();

                break;

            case 1467384969800:

                return make_shared<TransitionCondition1467384969800>();

                break;

            case 1492620542706:

                return make_shared<TransitionCondition1492620542706>();

                break;

            case 1434112519736:

                return make_shared<RunTimeCondition1434112519736>();

                break;

            case 1436536099859:

                return make_shared<TransitionCondition1436536099859>();

                break;

            case 1436536101707:

                return make_shared<TransitionCondition1436536101707>();

                break;

            case 1436536103010:

                return make_shared<TransitionCondition1436536103010>();

                break;

            case 1436536104021:

                return make_shared<TransitionCondition1436536104021>();

                break;

            case 1436536150520:

                return make_shared<TransitionCondition1436536150520>();

                break;

            case 1436536151584:

                return make_shared<TransitionCondition1436536151584>();

                break;

            case 1436536152571:

                return make_shared<TransitionCondition1436536152571>();

                break;

            case 1436536161660:

                return make_shared<TransitionCondition1436536161660>();

                break;

            case 1479905164080:

                return make_shared<TransitionCondition1479905164080>();

                break;

            case 1479905468245:

                return make_shared<TransitionCondition1479905468245>();

                break;

            case 1519033636553:

                return make_shared<TransitionCondition1519033636553>();

                break;

            case 1519033637686:

                return make_shared<TransitionCondition1519033637686>();

                break;

            case 1519033638861:

                return make_shared<TransitionCondition1519033638861>();

                break;

            case 1519033798908:

                return make_shared<TransitionCondition1519033798908>();

                break;

            case 1519033800013:

                return make_shared<TransitionCondition1519033800013>();

                break;

            case 1519033800793:

                return make_shared<TransitionCondition1519033800793>();

                break;

            case 1519033801788:

                return make_shared<TransitionCondition1519033801788>();

                break;

            case 1519033802879:

                return make_shared<TransitionCondition1519033802879>();

                break;

            case 1519033803756:

                return make_shared<TransitionCondition1519033803756>();

                break;

            case 1519033804822:

                return make_shared<TransitionCondition1519033804822>();

                break;

            case 1519033806168:

                return make_shared<TransitionCondition1519033806168>();

                break;

            case 1519033807440:

                return make_shared<TransitionCondition1519033807440>();

                break;

            case 1519033808463:

                return make_shared<TransitionCondition1519033808463>();

                break;

            case 1519033809424:

                return make_shared<TransitionCondition1519033809424>();

                break;

            case 1519033810484:

                return make_shared<TransitionCondition1519033810484>();

                break;

            case 1519033811584:

                return make_shared<TransitionCondition1519033811584>();

                break;

            case 1519033812683:

                return make_shared<TransitionCondition1519033812683>();

                break;

            case 1519033813705:

                return make_shared<TransitionCondition1519033813705>();

                break;

            case 1519033814809:

                return make_shared<TransitionCondition1519033814809>();

                break;

            case 1519033816018:

                return make_shared<TransitionCondition1519033816018>();

                break;

            case 1519033817036:

                return make_shared<TransitionCondition1519033817036>();

                break;

            case 1519033817980:

                return make_shared<TransitionCondition1519033817980>();

                break;

            case 1519033819335:

                return make_shared<TransitionCondition1519033819335>();

                break;

            case 1519033820671:

                return make_shared<TransitionCondition1519033820671>();

                break;

            case 1482163828612:

                return make_shared<TransitionCondition1482163828612>();

                break;

            case 1482163831043:

                return make_shared<TransitionCondition1482163831043>();

                break;

            case 1466973077506:

                return make_shared<TransitionCondition1466973077506>();

                break;

            case 1466973078342:

                return make_shared<TransitionCondition1466973078342>();

                break;

            case 1429111678112:

                return make_shared<TransitionCondition1429111678112>();

                break;

            case 1432132367859:

                return make_shared<TransitionCondition1432132367859>();

                break;

            case 1432132369717:

                return make_shared<TransitionCondition1432132369717>();

                break;

            case 1432132371055:

                return make_shared<TransitionCondition1432132371055>();

                break;

            case 1432132372365:

                return make_shared<TransitionCondition1432132372365>();

                break;

            case 1432132373471:

                return make_shared<TransitionCondition1432132373471>();

                break;

            case 1432132374502:

                return make_shared<TransitionCondition1432132374502>();

                break;

            case 1432132432036:

                return make_shared<TransitionCondition1432132432036>();

                break;

            case 1432132434051:

                return make_shared<TransitionCondition1432132434051>();

                break;

            case 1432132436308:

                return make_shared<TransitionCondition1432132436308>();

                break;

            case 1432132438181:

                return make_shared<TransitionCondition1432132438181>();

                break;

            case 1432132441034:

                return make_shared<TransitionCondition1432132441034>();

                break;

            case 1432132442910:

                return make_shared<TransitionCondition1432132442910>();

                break;

            case 1469109050023:

                return make_shared<TransitionCondition1469109050023>();

                break;

            case 1469109063861:

                return make_shared<TransitionCondition1469109063861>();

                break;

            case 1469109068711:

                return make_shared<TransitionCondition1469109068711>();

                break;

            case 1469109263885:

                return make_shared<TransitionCondition1469109263885>();

                break;

            case 1469109265377:

                return make_shared<TransitionCondition1469109265377>();

                break;

            case 1469109279649:

                return make_shared<TransitionCondition1469109279649>();

                break;

            case 1469109281934:

                return make_shared<TransitionCondition1469109281934>();

                break;

            case 1469284199355:

                return make_shared<TransitionCondition1469284199355>();

                break;

            case 1469284201761:

                return make_shared<TransitionCondition1469284201761>();

                break;

            case 1485356814622:

                return make_shared<TransitionCondition1485356814622>();

                break;

            case 1485356818666:

                return make_shared<TransitionCondition1485356818666>();

                break;

            case 1485356846217:

                return make_shared<TransitionCondition1485356846217>();

                break;

            case 1457434475372:

                return make_shared<TransitionCondition1457434475372>();

                break;

            case 1457434476549:

                return make_shared<TransitionCondition1457434476549>();

                break;

            case 1454506224420:

                return make_shared<TransitionCondition1454506224420>();

                break;

            case 1458125293553:

                return make_shared<TransitionCondition1458125293553>();

                break;

            case 1458125320118:

                return make_shared<TransitionCondition1458125320118>();

                break;

            case 1458135843050:

                return make_shared<TransitionCondition1458135843050>();

                break;

            case 1466975666362:

                return make_shared<RunTimeCondition1466975666362>();

                break;

            case 1491404930441:

                return make_shared<RunTimeCondition1491404930441>();

                break;

            case 1458131561310:

                return make_shared<TransitionCondition1458131561310>();

                break;

            case 1435159171807:

                return make_shared<TransitionCondition1435159171807>();

                break;

            case 1435159188113:

                return make_shared<TransitionCondition1435159188113>();

                break;

            case 1436979720241:

                return make_shared<TransitionCondition1436979720241>();

                break;

            case 1436979742914:

                return make_shared<TransitionCondition1436979742914>();

                break;

            case 1426691976695:

                return make_shared<TransitionCondition1426691976695>();

                break;

            case 1426691979272:

                return make_shared<TransitionCondition1426691979272>();

                break;

            case 1426691980585:

                return make_shared<TransitionCondition1426691980585>();

                break;

            case 1426692078983:

                return make_shared<TransitionCondition1426692078983>();

                break;

            case 1426692165988:

                return make_shared<TransitionCondition1426692165988>();

                break;

            case 1426692246279:

                return make_shared<TransitionCondition1426692246279>();

                break;

            case 1426692307991:

                return make_shared<TransitionCondition1426692307991>();

                break;

            case 1426692309848:

                return make_shared<TransitionCondition1426692309848>();

                break;

            case 1426692322491:

                return make_shared<TransitionCondition1426692322491>();

                break;

            case 1426692324569:

                return make_shared<TransitionCondition1426692324569>();

                break;

            case 1426692326693:

                return make_shared<TransitionCondition1426692326693>();

                break;

            case 1426692328653:

                return make_shared<TransitionCondition1426692328653>();

                break;

            case 1426692330833:

                return make_shared<TransitionCondition1426692330833>();

                break;

            case 1426692332679:

                return make_shared<TransitionCondition1426692332679>();

                break;

            case 1426692655810:

                return make_shared<TransitionCondition1426692655810>();

                break;

            case 1462969760665:

                return make_shared<TransitionCondition1462969760665>();

                break;

            case 1462969788458:

                return make_shared<TransitionCondition1462969788458>();

                break;

            case 1464189727040:

                return make_shared<TransitionCondition1464189727040>();

                break;

            case 1464189738685:

                return make_shared<TransitionCondition1464189738685>();

                break;

            case 1464979938671:

                return make_shared<TransitionCondition1464979938671>();

                break;

            case 1455537184881:

                return make_shared<TransitionCondition1455537184881>();

                break;

            case 1442919804925:

                return make_shared<TransitionCondition1442919804925>();

                break;

            case 1442921109582:

                return make_shared<TransitionCondition1442921109582>();

                break;

            case 1443003809289:

                return make_shared<TransitionCondition1443003809289>();

                break;

            case 1443003847207:

                return make_shared<TransitionCondition1443003847207>();

                break;

            case 1443522265673:

                return make_shared<TransitionCondition1443522265673>();

                break;

            case 1464350170265:

                return make_shared<TransitionCondition1464350170265>();

                break;

            case 1464350172193:

                return make_shared<TransitionCondition1464350172193>();

                break;

            case 1474288537568:

                return make_shared<TransitionCondition1474288537568>();

                break;

            case 1474288540200:

                return make_shared<TransitionCondition1474288540200>();

                break;

            case 1520682661242:

                return make_shared<TransitionCondition1520682661242>();

                break;

            case 1520682664300:

                return make_shared<TransitionCondition1520682664300>();

                break;

            case 1520682666211:

                return make_shared<TransitionCondition1520682666211>();

                break;

            case 1520682667668:

                return make_shared<TransitionCondition1520682667668>();

                break;

            case 1520682669615:

                return make_shared<TransitionCondition1520682669615>();

                break;

            case 1520682671176:

                return make_shared<TransitionCondition1520682671176>();

                break;

            case 1520682672669:

                return make_shared<TransitionCondition1520682672669>();

                break;

            case 1520682674019:

                return make_shared<TransitionCondition1520682674019>();

                break;

            case 1520682675912:

                return make_shared<TransitionCondition1520682675912>();

                break;

            case 1520682677336:

                return make_shared<TransitionCondition1520682677336>();

                break;

            case 1520682678705:

                return make_shared<TransitionCondition1520682678705>();

                break;

            case 1520682680343:

                return make_shared<TransitionCondition1520682680343>();

                break;

            case 1520682683152:

                return make_shared<TransitionCondition1520682683152>();

                break;

            case 1434048722207:

                return make_shared<TransitionCondition1434048722207>();

                break;

            case 1434048723635:

                return make_shared<TransitionCondition1434048723635>();

                break;

            case 1434048731181:

                return make_shared<TransitionCondition1434048731181>();

                break;

            case 1434048737070:

                return make_shared<TransitionCondition1434048737070>();

                break;

            case 1434716048353:

                return make_shared<TransitionCondition1434716048353>();

                break;

            case 1434716049299:

                return make_shared<TransitionCondition1434716049299>();

                break;

            case 1434716050319:

                return make_shared<TransitionCondition1434716050319>();

                break;

            case 1450175866027:

                return make_shared<TransitionCondition1450175866027>();

                break;

            case 1450175867019:

                return make_shared<TransitionCondition1450175867019>();

                break;

            case 1450175926118:

                return make_shared<TransitionCondition1450175926118>();

                break;

            case 1450175931490:

                return make_shared<TransitionCondition1450175931490>();

                break;

            case 1457687428316:

                return make_shared<TransitionCondition1457687428316>();

                break;

            case 1466936849620:

                return make_shared<TransitionCondition1466936849620>();

                break;

            case 1466936850439:

                return make_shared<TransitionCondition1466936850439>();

                break;

            case 1466936851265:

                return make_shared<TransitionCondition1466936851265>();

                break;

            case 1466936852075:

                return make_shared<TransitionCondition1466936852075>();

                break;

            case 1466936862234:

                return make_shared<TransitionCondition1466936862234>();

                break;

            case 1445442215438:

                return make_shared<RunTimeCondition1445442215438>();

                break;

            case 1447875675479:

                return make_shared<TransitionCondition1447875675479>();

                break;

            case 1454663210272:

                return make_shared<TransitionCondition1454663210272>();

                break;

            case 1454663213143:

                return make_shared<TransitionCondition1454663213143>();

                break;

            case 1441107213887:

                return make_shared<TransitionCondition1441107213887>();

                break;

            case 1441107217606:

                return make_shared<TransitionCondition1441107217606>();

                break;

            case 1521280931730:

                return make_shared<TransitionCondition1521280931730>();

                break;

            case 1521280987477:

                return make_shared<TransitionCondition1521280987477>();

                break;

            case 1521280994181:

                return make_shared<TransitionCondition1521280994181>();

                break;

            case 1521281060067:

                return make_shared<TransitionCondition1521281060067>();

                break;

            case 1426696641527:

                return make_shared<TransitionCondition1426696641527>();

                break;

            case 1426696642635:

                return make_shared<TransitionCondition1426696642635>();

                break;

            case 1458562142910:

                return make_shared<TransitionCondition1458562142910>();

                break;

            case 1458562144595:

                return make_shared<TransitionCondition1458562144595>();

                break;

            case 1458562147436:

                return make_shared<TransitionCondition1458562147436>();

                break;

            case 1518622828944:

                return make_shared<TransitionCondition1518622828944>();

                break;

            case 1518622830640:

                return make_shared<TransitionCondition1518622830640>();

                break;

            case 1518622834399:

                return make_shared<TransitionCondition1518622834399>();

                break;

            case 1518622835957:

                return make_shared<TransitionCondition1518622835957>();

                break;

            case 1518622837786:

                return make_shared<TransitionCondition1518622837786>();

                break;

            case 1518622839323:

                return make_shared<TransitionCondition1518622839323>();

                break;

            case 1518622846035:

                return make_shared<TransitionCondition1518622846035>();

                break;

            case 1518622847338:

                return make_shared<TransitionCondition1518622847338>();

                break;

            case 1518623968811:

                return make_shared<TransitionCondition1518623968811>();

                break;

            case 1518623970678:

                return make_shared<TransitionCondition1518623970678>();

                break;

            case 1459361912141:

                return make_shared<TransitionCondition1459361912141>();

                break;

            case 1459361914252:

                return make_shared<TransitionCondition1459361914252>();

                break;

            case 1459361916700:

                return make_shared<TransitionCondition1459361916700>();

                break;

            case 1458033759784:

                return make_shared<RunTimeCondition1458033759784>();

                break;

            case 1469522753378:

                return make_shared<RunTimeCondition1469522753378>();

                break;

            case 1469522459250:

                return make_shared<TransitionCondition1469522459250>();

                break;

            case 1469522460345:

                return make_shared<TransitionCondition1469522460345>();

                break;

            case 1469522461332:

                return make_shared<TransitionCondition1469522461332>();

                break;

            case 1469522463041:

                return make_shared<TransitionCondition1469522463041>();

                break;

            case 1469522685256:

                return make_shared<TransitionCondition1469522685256>();

                break;

            case 1469522686688:

                return make_shared<TransitionCondition1469522686688>();

                break;

            case 1469522690037:

                return make_shared<TransitionCondition1469522690037>();

                break;

            case 1469522692577:

                return make_shared<TransitionCondition1469522692577>();

                break;

            case 1498664087062:

                return make_shared<TransitionCondition1498664087062>();

                break;

            case 1498664100103:

                return make_shared<TransitionCondition1498664100103>();

                break;

            case 1431526792158:

                return make_shared<TransitionCondition1431526792158>();

                break;

            case 1432744250382:

                return make_shared<TransitionCondition1432744250382>();

                break;

            case 1433337666610:

                return make_shared<TransitionCondition1433337666610>();

                break;

            case 1433338526794:

                return make_shared<TransitionCondition1433338526794>();

                break;

            case 1433338530469:

                return make_shared<TransitionCondition1433338530469>();

                break;

            case 1426696478377:

                return make_shared<TransitionCondition1426696478377>();

                break;

            case 1467396619848:

                return make_shared<TransitionCondition1467396619848>();

                break;

            case 1470227880114:

                return make_shared<TransitionCondition1470227880114>();

                break;

            case 1470237805501:

                return make_shared<TransitionCondition1470237805501>();

                break;

            case 1480520550306:

                return make_shared<TransitionCondition1480520550306>();

                break;

            case 1436268944209:

                return make_shared<TransitionCondition1436268944209>();

                break;

            case 1436268945305:

                return make_shared<TransitionCondition1436268945305>();

                break;

            case 1457173948942:

                return make_shared<RunTimeCondition1457173948942>();

                break;

            case 1478711356604:

                return make_shared<TransitionCondition1478711356604>();

                break;

            case 1489068108429:

                return make_shared<TransitionCondition1489068108429>();

                break;

            case 1489068110424:

                return make_shared<TransitionCondition1489068110424>();

                break;

            case 1496753238482:

                return make_shared<TransitionCondition1496753238482>();

                break;

            case 1496753474941:

                return make_shared<TransitionCondition1496753474941>();

                break;

            case 1498664182584:

                return make_shared<TransitionCondition1498664182584>();

                break;

            case 1498664190906:

                return make_shared<TransitionCondition1498664190906>();

                break;

            case 1459365392367:

                return make_shared<TransitionCondition1459365392367>();

                break;

            case 1459365394125:

                return make_shared<TransitionCondition1459365394125>();

                break;

            case 1459365401307:

                return make_shared<TransitionCondition1459365401307>();

                break;

            case 1459365407637:

                return make_shared<TransitionCondition1459365407637>();

                break;

            case 1459365410684:

                return make_shared<TransitionCondition1459365410684>();

                break;

            case 1459365411722:

                return make_shared<TransitionCondition1459365411722>();

                break;

            case 1459365412597:

                return make_shared<TransitionCondition1459365412597>();

                break;

            case 1459365413923:

                return make_shared<TransitionCondition1459365413923>();

                break;

            case 1456841218640:

                return make_shared<TransitionCondition1456841218640>();

                break;

            case 1456841244750:

                return make_shared<TransitionCondition1456841244750>();

                break;

            case 1456841276132:

                return make_shared<TransitionCondition1456841276132>();

                break;

            case 1447255447830:

                return make_shared<TransitionCondition1447255447830>();

                break;

            case 1434116267322:

                return make_shared<RunTimeCondition1434116267322>();

                break;

            case 1434050620829:

                return make_shared<TransitionCondition1434050620829>();

                break;

            case 1434050638814:

                return make_shared<TransitionCondition1434050638814>();

                break;

            case 1434050643664:

                return make_shared<TransitionCondition1434050643664>();

                break;

            case 1434050649090:

                return make_shared<TransitionCondition1434050649090>();

                break;

            case 1434050650300:

                return make_shared<TransitionCondition1434050650300>();

                break;

            case 1434050655008:

                return make_shared<TransitionCondition1434050655008>();

                break;

            case 1434050656151:

                return make_shared<TransitionCondition1434050656151>();

                break;

            case 1434050674307:

                return make_shared<TransitionCondition1434050674307>();

                break;

            case 1434050677358:

                return make_shared<TransitionCondition1434050677358>();

                break;

            case 1434050685640:

                return make_shared<TransitionCondition1434050685640>();

                break;

            case 1434050690800:

                return make_shared<TransitionCondition1434050690800>();

                break;

            case 1521283236610:

                return make_shared<TransitionCondition1521283236610>();

                break;

            case 1521283237926:

                return make_shared<TransitionCondition1521283237926>();

                break;

            case 1521283239559:

                return make_shared<TransitionCondition1521283239559>();

                break;

            case 1521283249550:

                return make_shared<TransitionCondition1521283249550>();

                break;

            case 1449076203800:

                return make_shared<TransitionCondition1449076203800>();

                break;

            case 1449076205925:

                return make_shared<TransitionCondition1449076205925>();

                break;

            case 1461574228077:

                return make_shared<RunTimeCondition1461574228077>();

                break;

            case 1461237677283:

                return make_shared<TransitionCondition1461237677283>();

                break;

            case 1461237854702:

                return make_shared<TransitionCondition1461237854702>();

                break;

            case 1461572770571:

                return make_shared<TransitionCondition1461572770571>();

                break;

            case 1461584286706:

                return make_shared<TransitionCondition1461584286706>();

                break;

            case 1461584441559:

                return make_shared<TransitionCondition1461584441559>();

                break;

            case 1523091132512:

                return make_shared<TransitionCondition1523091132512>();

                break;

            case 1457955744730:

                return make_shared<RunTimeCondition1457955744730>();

                break;

            case 1467224612376:

                return make_shared<PreCondition1467224612376>();

                break;

            case 1431522783626:

                return make_shared<TransitionCondition1431522783626>();

                break;

            case 1431522922124:

                return make_shared<TransitionCondition1431522922124>();

                break;

            case 1431523013533:

                return make_shared<TransitionCondition1431523013533>();

                break;

            case 1431524871023:

                return make_shared<TransitionCondition1431524871023>();

                break;

            case 1433949707598:

                return make_shared<TransitionCondition1433949707598>();

                break;

            case 1435761870069:

                return make_shared<TransitionCondition1435761870069>();

                break;

            case 1466934424435:

                return make_shared<TransitionCondition1466934424435>();

                break;

            case 1466934425215:

                return make_shared<TransitionCondition1466934425215>();

                break;

            case 1466934426230:

                return make_shared<TransitionCondition1466934426230>();

                break;

            case 1466934427236:

                return make_shared<TransitionCondition1466934427236>();

                break;

            case 1466934488578:

                return make_shared<TransitionCondition1466934488578>();

                break;

            case 1466973020291:

                return make_shared<TransitionCondition1466973020291>();

                break;

            case 1518625926563:

                return make_shared<TransitionCondition1518625926563>();

                break;

            case 1518625927967:

                return make_shared<TransitionCondition1518625927967>();

                break;

            case 1518625929607:

                return make_shared<TransitionCondition1518625929607>();

                break;

            case 1518625931710:

                return make_shared<TransitionCondition1518625931710>();

                break;

            case 1518625933379:

                return make_shared<TransitionCondition1518625933379>();

                break;

            case 1518625934916:

                return make_shared<TransitionCondition1518625934916>();

                break;

            case 1518625936267:

                return make_shared<TransitionCondition1518625936267>();

                break;

            case 1518625938386:

                return make_shared<TransitionCondition1518625938386>();

                break;

            case 1518625939622:

                return make_shared<TransitionCondition1518625939622>();

                break;

            case 1518625941030:

                return make_shared<TransitionCondition1518625941030>();

                break;

            case 1518625942849:

                return make_shared<TransitionCondition1518625942849>();

                break;

            case 1518625944363:

                return make_shared<TransitionCondition1518625944363>();

                break;

            case 1518625947022:

                return make_shared<TransitionCondition1518625947022>();

                break;

            case 1518625962322:

                return make_shared<TransitionCondition1518625962322>();

                break;

            case 1518625964162:

                return make_shared<TransitionCondition1518625964162>();

                break;

            case 1518625965631:

                return make_shared<TransitionCondition1518625965631>();

                break;

            case 1518625978714:

                return make_shared<TransitionCondition1518625978714>();

                break;

            case 1518625979903:

                return make_shared<TransitionCondition1518625979903>();

                break;

            case 1518625985243:

                return make_shared<TransitionCondition1518625985243>();

                break;

            case 1518625986946:

                return make_shared<TransitionCondition1518625986946>();

                break;

            case 1518625988962:

                return make_shared<TransitionCondition1518625988962>();

                break;

            case 1518625990399:

                return make_shared<TransitionCondition1518625990399>();

                break;

            case 1518625992739:

                return make_shared<TransitionCondition1518625992739>();

                break;

            case 1518625993923:

                return make_shared<TransitionCondition1518625993923>();

                break;

            case 1518869293795:

                return make_shared<TransitionCondition1518869293795>();

                break;

            case 1464793807994:

                return make_shared<RunTimeCondition1464793807994>();

                break;

            case 1464784053079:

                return make_shared<TransitionCondition1464784053079>();

                break;

            case 1464787990119:

                return make_shared<TransitionCondition1464787990119>();

                break;

            case 1464788000901:

                return make_shared<TransitionCondition1464788000901>();

                break;

            case 1464788060652:

                return make_shared<TransitionCondition1464788060652>();

                break;

            case 1464792277148:

                return make_shared<TransitionCondition1464792277148>();

                break;

            case 1464796139312:

                return make_shared<TransitionCondition1464796139312>();

                break;

            case 1457015310255:

                return make_shared<TransitionCondition1457015310255>();

                break;

            case 1457015479684:

                return make_shared<TransitionCondition1457015479684>();

                break;

            case 1458555989600:

                return make_shared<TransitionCondition1458555989600>();

                break;

            case 1458555991152:

                return make_shared<TransitionCondition1458555991152>();

                break;

            case 1458555993122:

                return make_shared<TransitionCondition1458555993122>();

                break;

            case 1458555994351:

                return make_shared<TransitionCondition1458555994351>();

                break;

            case 1417620269159:

                return make_shared<TransitionCondition1417620269159>();

                break;

            case 1417620286821:

                return make_shared<TransitionCondition1417620286821>();

                break;

            case 1417620329181:

                return make_shared<TransitionCondition1417620329181>();

                break;

            case 1430925918456:

                return make_shared<TransitionCondition1430925918456>();

                break;

            case 1430925919738:

                return make_shared<TransitionCondition1430925919738>();

                break;

            case 1430925921267:

                return make_shared<TransitionCondition1430925921267>();

                break;

            case 1430925922740:

                return make_shared<TransitionCondition1430925922740>();

                break;

            case 1430925924055:

                return make_shared<TransitionCondition1430925924055>();

                break;

            case 1430925925549:

                return make_shared<TransitionCondition1430925925549>();

                break;

            case 1430925962659:

                return make_shared<TransitionCondition1430925962659>();

                break;

            case 1430925965501:

                return make_shared<TransitionCondition1430925965501>();

                break;

            case 1430925967520:

                return make_shared<TransitionCondition1430925967520>();

                break;

            case 1430925970967:

                return make_shared<TransitionCondition1430925970967>();

                break;

            case 1430925972838:

                return make_shared<TransitionCondition1430925972838>();

                break;

            case 1430925975558:

                return make_shared<TransitionCondition1430925975558>();

                break;

            case 1458555207377:

                return make_shared<TransitionCondition1458555207377>();

                break;

            case 1458555210443:

                return make_shared<TransitionCondition1458555210443>();

                break;

            case 1458555218469:

                return make_shared<TransitionCondition1458555218469>();

                break;

            case 1458555220837:

                return make_shared<TransitionCondition1458555220837>();

                break;

            case 1458555223252:

                return make_shared<TransitionCondition1458555223252>();

                break;

            case 1458555791025:

                return make_shared<TransitionCondition1458555791025>();

                break;

            case 1458555821886:

                return make_shared<TransitionCondition1458555821886>();

                break;

            case 1458555856023:

                return make_shared<TransitionCondition1458555856023>();

                break;

            case 1458555881015:

                return make_shared<TransitionCondition1458555881015>();

                break;

            case 1458555898277:

                return make_shared<TransitionCondition1458555898277>();

                break;

            case 1518862114467:

                return make_shared<TransitionCondition1518862114467>();

                break;

            case 1518862115739:

                return make_shared<TransitionCondition1518862115739>();

                break;

            case 1518862116884:

                return make_shared<TransitionCondition1518862116884>();

                break;

            case 1518862118075:

                return make_shared<TransitionCondition1518862118075>();

                break;

            case 1518862119588:

                return make_shared<TransitionCondition1518862119588>();

                break;

            case 1518862121592:

                return make_shared<TransitionCondition1518862121592>();

                break;

            case 1518862123708:

                return make_shared<TransitionCondition1518862123708>();

                break;

            case 1518862126807:

                return make_shared<TransitionCondition1518862126807>();

                break;

            case 1518862129037:

                return make_shared<TransitionCondition1518862129037>();

                break;

            case 1518862130944:

                return make_shared<TransitionCondition1518862130944>();

                break;

            case 1518862132763:

                return make_shared<TransitionCondition1518862132763>();

                break;

            case 1518862135489:

                return make_shared<TransitionCondition1518862135489>();

                break;

            case 1518862140627:

                return make_shared<TransitionCondition1518862140627>();

                break;

            case 1518862142552:

                return make_shared<TransitionCondition1518862142552>();

                break;

            case 1518862143987:

                return make_shared<TransitionCondition1518862143987>();

                break;

            case 1518862148362:

                return make_shared<TransitionCondition1518862148362>();

                break;

            case 1518862151625:

                return make_shared<TransitionCondition1518862151625>();

                break;

            case 1518862153164:

                return make_shared<TransitionCondition1518862153164>();

                break;

            case 1518862154788:

                return make_shared<TransitionCondition1518862154788>();

                break;

            case 1518862156091:

                return make_shared<TransitionCondition1518862156091>();

                break;

            case 1518862157639:

                return make_shared<TransitionCondition1518862157639>();

                break;

            case 1518862159584:

                return make_shared<TransitionCondition1518862159584>();

                break;

            case 1518862162949:

                return make_shared<TransitionCondition1518862162949>();

                break;

            case 1518862164476:

                return make_shared<TransitionCondition1518862164476>();

                break;

            case 1518869323662:

                return make_shared<TransitionCondition1518869323662>();

                break;

            case 1469455112199:

                return make_shared<RunTimeCondition1469455112199>();

                break;

            case 1440675385644:

                return make_shared<TransitionCondition1440675385644>();

                break;

            case 1440772443709:

                return make_shared<TransitionCondition1440772443709>();

                break;

            case 1440772549250:

                return make_shared<TransitionCondition1440772549250>();

                break;

            case 1440772553737:

                return make_shared<TransitionCondition1440772553737>();

                break;

            case 1440772876913:

                return make_shared<TransitionCondition1440772876913>();

                break;

            case 1441811702176:

                return make_shared<TransitionCondition1441811702176>();

                break;

            case 1430324477939:

                return make_shared<TransitionCondition1430324477939>();

                break;

            case 1431012032315:

                return make_shared<TransitionCondition1431012032315>();

                break;

            case 1431528626141:

                return make_shared<TransitionCondition1431528626141>();

                break;

            case 1431528765720:

                return make_shared<TransitionCondition1431528765720>();

                break;

            case 1431528885384:

                return make_shared<TransitionCondition1431528885384>();

                break;

            case 1431528887593:

                return make_shared<TransitionCondition1431528887593>();

                break;

            case 1431528896437:

                return make_shared<TransitionCondition1431528896437>();

                break;

            case 1431528902161:

                return make_shared<TransitionCondition1431528902161>();

                break;

            case 1431529012684:

                return make_shared<TransitionCondition1431529012684>();

                break;

            case 1431529014647:

                return make_shared<TransitionCondition1431529014647>();

                break;

            case 1462361418213:

                return make_shared<RunTimeCondition1462361418213>();

                break;

            case 1462360958757:

                return make_shared<TransitionCondition1462360958757>();

                break;

            case 1462360959862:

                return make_shared<TransitionCondition1462360959862>();

                break;

            case 1462360961688:

                return make_shared<TransitionCondition1462360961688>();

                break;

            case 1462368132067:

                return make_shared<TransitionCondition1462368132067>();

                break;

            case 1462368203054:

                return make_shared<TransitionCondition1462368203054>();

                break;

            case 1462368267324:

                return make_shared<TransitionCondition1462368267324>();

                break;

            case 1462368269701:

                return make_shared<TransitionCondition1462368269701>();

                break;

            case 1462369227764:

                return make_shared<TransitionCondition1462369227764>();

                break;

            case 1518624922421:

                return make_shared<TransitionCondition1518624922421>();

                break;

            case 1518624923528:

                return make_shared<TransitionCondition1518624923528>();

                break;

            case 1518624924742:

                return make_shared<TransitionCondition1518624924742>();

                break;

            case 1518624925908:

                return make_shared<TransitionCondition1518624925908>();

                break;

            case 1518624927095:

                return make_shared<TransitionCondition1518624927095>();

                break;

            case 1518624928426:

                return make_shared<TransitionCondition1518624928426>();

                break;

            case 1518624929829:

                return make_shared<TransitionCondition1518624929829>();

                break;

            case 1518624930978:

                return make_shared<TransitionCondition1518624930978>();

                break;

            case 1518624932238:

                return make_shared<TransitionCondition1518624932238>();

                break;

            case 1518624933146:

                return make_shared<TransitionCondition1518624933146>();

                break;

            case 1518624934271:

                return make_shared<TransitionCondition1518624934271>();

                break;

            case 1518624935190:

                return make_shared<TransitionCondition1518624935190>();

                break;

            case 1518624970684:

                return make_shared<TransitionCondition1518624970684>();

                break;

            case 1458033411271:

                return make_shared<TransitionCondition1458033411271>();

                break;

            case 1458033412464:

                return make_shared<TransitionCondition1458033412464>();

                break;

            case 1458033413418:

                return make_shared<TransitionCondition1458033413418>();

                break;

            case 1457698634601:

                return make_shared<TransitionCondition1457698634601>();

                break;

            case 1457698635818:

                return make_shared<TransitionCondition1457698635818>();

                break;

            case 1457531039142:

                return make_shared<RunTimeCondition1457531039142>();

                break;

            case 1457531305067:

                return make_shared<TransitionCondition1457531305067>();

                break;

            case 1457531315717:

                return make_shared<TransitionCondition1457531315717>();

                break;

            case 1457531317223:

                return make_shared<TransitionCondition1457531317223>();

                break;

            case 1457531342108:

                return make_shared<TransitionCondition1457531342108>();

                break;

            case 1457531352472:

                return make_shared<TransitionCondition1457531352472>();

                break;

            case 1458033723845:

                return make_shared<RunTimeCondition1458033723845>();

                break;

            case 1458033705136:

                return make_shared<TransitionCondition1458033705136>();

                break;

            case 1508951693560:

                return make_shared<RunTimeCondition1508951693560>();

                break;

            case 1518866390521:

                return make_shared<TransitionCondition1518866390521>();

                break;

            case 1518866391883:

                return make_shared<TransitionCondition1518866391883>();

                break;

            case 1422464821945:

                return make_shared<TransitionCondition1422464821945>();

                break;

            case 1422464875980:

                return make_shared<TransitionCondition1422464875980>();

                break;

            case 1496753329486:

                return make_shared<TransitionCondition1496753329486>();

                break;

            case 1496753330441:

                return make_shared<TransitionCondition1496753330441>();

                break;

            case 1457173604049:

                return make_shared<TransitionCondition1457173604049>();

                break;

            case 1457173606067:

                return make_shared<TransitionCondition1457173606067>();

                break;

            case 1467206311808:

                return make_shared<RunTimeCondition1467206311808>();

                break;

            case 1464778511333:

                return make_shared<TransitionCondition1464778511333>();

                break;

            case 1464778513499:

                return make_shared<TransitionCondition1464778513499>();

                break;

            case 1464778515331:

                return make_shared<TransitionCondition1464778515331>();

                break;

            case 1464778516153:

                return make_shared<TransitionCondition1464778516153>();

                break;

            case 1464783506322:

                return make_shared<TransitionCondition1464783506322>();

                break;

            case 1464785252648:

                return make_shared<TransitionCondition1464785252648>();

                break;

            case 1464785280406:

                return make_shared<TransitionCondition1464785280406>();

                break;

            case 1519832908120:

                return make_shared<TransitionCondition1519832908120>();

                break;

            case 1473862897803:

                return make_shared<TransitionCondition1473862897803>();

                break;

            case 1473865278666:

                return make_shared<TransitionCondition1473865278666>();

                break;

            case 1441106955179:

                return make_shared<TransitionCondition1441106955179>();

                break;

            case 1441106956349:

                return make_shared<TransitionCondition1441106956349>();

                break;

            case 1464780785574:

                return make_shared<RunTimeCondition1464780785574>();

                break;

            case 1464781041779:

                return make_shared<TransitionCondition1464781041779>();

                break;

            case 1464781044511:

                return make_shared<TransitionCondition1464781044511>();

                break;

            case 1464781045433:

                return make_shared<TransitionCondition1464781045433>();

                break;

            case 1464781329800:

                return make_shared<TransitionCondition1464781329800>();

                break;

            case 1464781427853:

                return make_shared<TransitionCondition1464781427853>();

                break;

            case 1464781495801:

                return make_shared<TransitionCondition1464781495801>();

                break;

            case 1464781583659:

                return make_shared<TransitionCondition1464781583659>();

                break;

            case 1464781589367:

                return make_shared<TransitionCondition1464781589367>();

                break;

            default:
                cerr << "ConditionCreator: Unknown condition id requested: " << conditionConfId << endl;
                throw new exception();
                break;
        }
    }
}
