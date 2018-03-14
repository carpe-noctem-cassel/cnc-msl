#include "Plans/Attack/Dribble1434049476066.h"
using namespace alica;
/*PROTECTED REGION ID(eph1434049476066) ENABLED START*/ //Add additional using directives here
#include <MSLWorldModel.h>
#include <MSLFootballField.h>
#include <Ball.h>
#include <RawSensorData.h>
#include <Robots.h>
#include <msl_robot/kicker/Kicker.h>
#include <obstaclehandler/Obstacles.h>
#include <msl_robot/MSLRobot.h>
#include <Game.h>
/*PROTECTED REGION END*/
namespace alicaAutogenerated
{
    //Plan:Dribble

    //Check of RuntimeCondition - (Name): NewRuntimeCondition, (ConditionString): , (Comment) : haveBall 

    /* 
     * Available Vars:
     */
    bool RunTimeCondition1434116267322::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434116267322) ENABLED START*/
        return wm->ball->haveBall();
        /*PROTECTED REGION END*/
    }

    /* generated comment
     
     Task: Attack  -> EntryPoint-ID: 1434049476068

     */
    shared_ptr<UtilityFunction> UtilityFunction1434049476066::getUtilityFunction(Plan* plan)
    {
        /*PROTECTED REGION ID(1434049476066) ENABLED START*/

        shared_ptr < UtilityFunction > defaultFunction = make_shared < DefaultUtilityFunction > (plan);
        return defaultFunction;

        /*PROTECTED REGION END*/
    }

    //State: Dribble in Plan: Dribble

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Comment	may score && Goal closer than PreciseShot.MaxDistance && freeGoalVector exists && noobstacle in turn radius && Distance to goal larger than PrecideShot.MinDistance && AngleToGoal larger than 10degrees 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleEmergencyKickDefault, (PlanID): 1457706826895 				
     *   - Plan - (Name): DribbleAttackConservativeDefault, (PlanID): 1457967385543 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434049476068)
     *
     * States:
     *   - Dribble (1434049476067)
     *   - AlignToGoal (1434050474119)
     *   - AttackAgain (1434050502701)
     *   - ProtectBall (1434050522682)
     *   - TurnOneEighty (1434050541225)
     *
     * Vars:
     */
    bool TransitionCondition1434050620829::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434050619363) ENABLED START*/
        if (!wm->game->isMayScore())
        {
            return false;
        }
        shared_ptr < geometry::CNPosition > ownPos = wm->rawSensorData->getOwnPositionVision();
        if (ownPos == nullptr)
        {
            return false;
        }
        //RC-10: no goal shot from own half:
        if (ownPos->x < 0)
        {
            return false;
        }
        double distance = numeric_limits<double>::max();
        //better clustered opps?
        auto obs = wm->obstacles->getAlloObstaclePoints();
        auto ballPos = wm->ball->getEgoBallPosition();
        if (obs == nullptr || ballPos == nullptr)
        {
            return false;
        }
        double dist = 1300;
        double temp = numeric_limits<double>::max();
        auto right = wm->field->posRightOppGoalPost()->normalize() * dist;
        auto left = wm->field->posLeftOppGoalPost()->normalize() * dist;
        auto ballAllo = ballPos->egoToAllo(*ownPos);
        if (geometry::outsideTriangle(ballAllo, right, left, 450, obs))
        {
            for (int i = 0; i < obs->size(); i++)
            {
                temp = obs->at(i)->distanceTo(ballPos->egoToAllo(*ownPos));
                if (temp < distance)
                {
                    distance = temp;
                }
            }
        }

        shared_ptr < geometry::CNPoint2D > goalMid = make_shared < geometry::CNPoint2D
                > (wm->field->getFieldLength() / 2, 0);

        double goalAng = goalMid->angleToPoint(ownPos->getPoint());
        if (abs(goalAng) < 118.0 * M_PI / 180)
        {
            return false;
        }
        double goalDist = ownPos->distanceTo(goalMid);
        auto sc = supplementary::SystemConfig::getInstance();
        double preciseShotMaxDistance = (*sc)["KickHelper"]->get<double>("PreciseShot.MaxDistance", NULL);
        double preciseShotMinDistance = (*sc)["KickHelper"]->get<double>("PreciseShot.MinDistance", NULL);

        return goalDist < preciseShotMaxDistance && goalDist > preciseShotMinDistance
                && this->robot->kicker->getFreeGoalVector() != nullptr && distance > 1300;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Fail 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleEmergencyKickDefault, (PlanID): 1457706826895 				
     *   - Plan - (Name): DribbleAttackConservativeDefault, (PlanID): 1457967385543 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434049476068)
     *
     * States:
     *   - Dribble (1434049476067)
     *   - AlignToGoal (1434050474119)
     *   - AttackAgain (1434050502701)
     *   - ProtectBall (1434050522682)
     *   - TurnOneEighty (1434050541225)
     *
     * Vars:
     */
    bool TransitionCondition1434050649090::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434050647042) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Failed);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : ownPos.X > fieldLength/2 - goalAreaX - 1300 && Abs(ownPos.Y) < penaltyArea.Y 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleEmergencyKickDefault, (PlanID): 1457706826895 				
     *   - Plan - (Name): DribbleAttackConservativeDefault, (PlanID): 1457967385543 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434049476068)
     *
     * States:
     *   - Dribble (1434049476067)
     *   - AlignToGoal (1434050474119)
     *   - AttackAgain (1434050502701)
     *   - ProtectBall (1434050522682)
     *   - TurnOneEighty (1434050541225)
     *
     * Vars:
     */
    bool TransitionCondition1434050674307::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434050656332) ENABLED START*/
        shared_ptr < geometry::CNPosition > ownPos = wm->rawSensorData->getOwnPositionVision();
        if (ownPos == nullptr)
        {
            return false;
        }
//        return ownPos->x > field->FieldLength / 2.0 - 1300 - field->GoalAreaLength
//                && abs(ownPos->y) < field->PenaltyAreaWidth / 2.0;
        return wm->field->isInsideOppPenalty(ownPos->getPoint(), 200);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : ProtectBall opponent is in front of us 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleEmergencyKickDefault, (PlanID): 1457706826895 				
     *   - Plan - (Name): DribbleAttackConservativeDefault, (PlanID): 1457967385543 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434049476068)
     *
     * States:
     *   - Dribble (1434049476067)
     *   - AlignToGoal (1434050474119)
     *   - AttackAgain (1434050502701)
     *   - ProtectBall (1434050522682)
     *   - TurnOneEighty (1434050541225)
     *
     * Vars:
     */
    bool TransitionCondition1434050677358::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434050674494) ENABLED START*/
        auto opp = wm->robots->opponents.getOpponentsAlloClustered();
        if (opp == nullptr || opp->size() == 0)
        {
            return false;
        }

        for (shared_ptr<geometry::CNPoint2D> ego : *opp)
        {
            if (ego->length() < wm->robots->opponents.getOpponentProtectDistance())
            {
                double angDiff = geometry::normalizeAngle(ego->angleTo() - M_PI);

                //Console.WriteLine("angle : " + angDiff);
                if (abs(angDiff) < wm->robots->opponents.getOpponentProtectAngle())
                {
                    return true;
                }
            }
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: AlignToGoal in Plan: Dribble

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Fail || couldn't kick 
     *
     * Plans in State: 				
     *   - Plan - (Name): AlignToGoalDefault, (PlanID): 1415205285582 				
     *   - Plan - (Name): CheckGoalKickDefault, (PlanID): 1449076029919 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434049476068)
     *
     * States:
     *   - Dribble (1434049476067)
     *   - AlignToGoal (1434050474119)
     *   - AttackAgain (1434050502701)
     *   - ProtectBall (1434050522682)
     *   - TurnOneEighty (1434050541225)
     *
     * Vars:
     */
    bool TransitionCondition1434050638814::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434050630827) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Failed);
        /*PROTECTED REGION END*/

    }

    //State: AttackAgain in Plan: Dribble

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : success 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleEmergencyKickDefault, (PlanID): 1457706826895 				
     *   - Plan - (Name): DribbleToAttackPointConservativeDefault, (PlanID): 1458132905432 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434049476068)
     *
     * States:
     *   - Dribble (1434049476067)
     *   - AlignToGoal (1434050474119)
     *   - AttackAgain (1434050502701)
     *   - ProtectBall (1434050522682)
     *   - TurnOneEighty (1434050541225)
     *
     * Vars:
     */
    bool TransitionCondition1434050643664::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434050639119) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Fail 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleEmergencyKickDefault, (PlanID): 1457706826895 				
     *   - Plan - (Name): DribbleToAttackPointConservativeDefault, (PlanID): 1458132905432 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434049476068)
     *
     * States:
     *   - Dribble (1434049476067)
     *   - AlignToGoal (1434050474119)
     *   - AttackAgain (1434050502701)
     *   - ProtectBall (1434050522682)
     *   - TurnOneEighty (1434050541225)
     *
     * Vars:
     */
    bool TransitionCondition1434050656151::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434050655141) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Failed);
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : ProtectBall opponent is in front of us 
     *
     * Plans in State: 				
     *   - Plan - (Name): DribbleEmergencyKickDefault, (PlanID): 1457706826895 				
     *   - Plan - (Name): DribbleToAttackPointConservativeDefault, (PlanID): 1458132905432 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434049476068)
     *
     * States:
     *   - Dribble (1434049476067)
     *   - AlignToGoal (1434050474119)
     *   - AttackAgain (1434050502701)
     *   - ProtectBall (1434050522682)
     *   - TurnOneEighty (1434050541225)
     *
     * Vars:
     */
    bool TransitionCondition1434050690800::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434050686620) ENABLED START*/
        auto opp = wm->robots->opponents.getOpponentsAlloClustered();
        if (opp == nullptr || opp->size() == 0)
        {
            return false;
        }

        for (shared_ptr<geometry::CNPoint2D> ego : *opp)
        {
            if (ego->length() < wm->robots->opponents.getOpponentProtectDistance())
            {
                double angDiff = geometry::normalizeAngle(ego->angleTo() - M_PI);

                //Console.WriteLine("angle : " + angDiff);
                if (abs(angDiff) < wm->robots->opponents.getOpponentProtectAngle())
                {
                    return true;
                }
            }
        }
        return false;
        /*PROTECTED REGION END*/

    }

    //State: ProtectBall in Plan: Dribble

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : any child success 
     *
     * Plans in State: 				
     *   - Plan - (Name): ProtectBallDefault, (PlanID): 1457706612268 				
     *   - Plan - (Name): DribbleEmergencyKickSafe, (PlanID): 1457706895442 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434049476068)
     *
     * States:
     *   - Dribble (1434049476067)
     *   - AlignToGoal (1434050474119)
     *   - AttackAgain (1434050502701)
     *   - ProtectBall (1434050522682)
     *   - TurnOneEighty (1434050541225)
     *
     * Vars:
     */
    bool TransitionCondition1434050685640::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434050681521) ENABLED START*/
        return rp->anyChildrenStatus(PlanStatus::Success);
        /*PROTECTED REGION END*/

    }

    //State: TurnOneEighty in Plan: Dribble

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : Success && Angle to goal < 90 degrees 
     *
     * Plans in State: 				
     *   - Plan - (Name): OneEightyDefault, (PlanID): 1434650910857 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434049476068)
     *
     * States:
     *   - Dribble (1434049476067)
     *   - AlignToGoal (1434050474119)
     *   - AttackAgain (1434050502701)
     *   - ProtectBall (1434050522682)
     *   - TurnOneEighty (1434050541225)
     *
     * Vars:
     */
    bool TransitionCondition1434050650300::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434050649347) ENABLED START*/
        if (!rp->anyChildrenStatus(PlanStatus::Success))
        {
            return false;
        }
        shared_ptr < geometry::CNPoint2D > ballPos = wm->ball->getEgoBallPosition();
        if (ballPos == nullptr)
        {
            return false;
        }
        shared_ptr < geometry::CNPosition > ownPos = wm->rawSensorData->getOwnPositionVision();
        if (ownPos == nullptr)
        {
            return false;
        }
        double dang = geometry::deltaAngle(
                ballPos->angleTo(),
                make_shared < geometry::CNPoint2D
                        > (wm->field->getFieldLength() / 2, 0.0)->alloToEgo(*ownPos)->angleTo());
        return abs(dang) < M_PI / 2.0;
        /*PROTECTED REGION END*/

    }

    /*
     *		
     * Transition:
     *   - Name: MISSING_NAME, ConditionString: , Comment : (Success && angle to goal > 90 degrees) or Fail 
     *
     * Plans in State: 				
     *   - Plan - (Name): OneEightyDefault, (PlanID): 1434650910857 				
     *   - Plan - (Name): DribbleControlMOSDefault, (PlanID): 1479905216821 
     *
     * Tasks: 
     *   - Attack (1222613952469) (Entrypoint: 1434049476068)
     *
     * States:
     *   - Dribble (1434049476067)
     *   - AlignToGoal (1434050474119)
     *   - AttackAgain (1434050502701)
     *   - ProtectBall (1434050522682)
     *   - TurnOneEighty (1434050541225)
     *
     * Vars:
     */
    bool TransitionCondition1434050655008::evaluate(shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(1434050650481) ENABLED START*/
        shared_ptr < geometry::CNPoint2D > ballPos = wm->ball->getEgoBallPosition();
        if (ballPos == nullptr)
        {
            return false;
        }
        shared_ptr < geometry::CNPosition > ownPos = wm->rawSensorData->getOwnPositionVision();
        if (ownPos == nullptr)
        {
            return false;
        }
        double dang = geometry::deltaAngle(
                ballPos->angleTo(),
                make_shared < geometry::CNPoint2D
                        > (wm->field->getFieldLength() / 2, 0.0)->alloToEgo(*ownPos)->angleTo());
        return (rp->anyChildrenStatus(PlanStatus::Success) && abs(dang) >= M_PI / 2.0)
                || rp->anyChildrenStatus(PlanStatus::Failed);
        /*PROTECTED REGION END*/

    }

}
