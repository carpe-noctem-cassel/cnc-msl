#include "Plans/Standards/Opponent/FreeKick/constraints/OppFreeKick1445411471122Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1445411471122) ENABLED START*/
//Add additional using directives here
#include <memory>
#include "AutoDiff.h"
#include "MSLConstraintBuilder.h"
#include "MSLFootballField.h"
#include "engine/constraintmodul/SolverTerm.h"
#include "engine/constraintmodul/ProblemDescriptor.h"
#include "MSLWorldModel.h"
#include <Robots.h>
#include <Ball.h>
#include <Game.h>
/*PROTECTED REGION END*/

namespace alicaAutogenerated
{
    //Plan:OppFreeKick

    /*		
     * Tasks: 
     * - EP:1445411471124 : Defend (1225115406909)
     * - EP:1454663032454 : Block (1461237765109)
     * - EP:1454663045348 : Attack (1222613952469)
     *
     * States:
     * - PosDefDefender (1445411471123)
     * - Success (1447875657650)
     * - PosDefBlocker (1454663055945)
     * - PosDefAttacker (1454663058990)
     *
     * Vars:
     */

    /*
     * RuntimeCondition - (Name): NewRuntimeCondition
     * (ConditionString): 
     * Static Variables: []
     * Domain Variables:

     * forall agents in PosDefBlocker let v = [x, y] 

     * forall agents in PosDefDefender let v = [x, y] 

     * forall agents in PosDefAttacker let v = [x, y] 

     */
    void Constraint1445442215438::getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(cc1445442215438) ENABLED START*/

        // START INITILIZE VARIABLE CONTAINER
        msl::MSLWorldModel* wm = msl::MSLWorldModel::get();
        auto constraint = autodiff::LTConstraint::TRUE;
        auto util = autodiff::TermBuilder::constant(0);
        auto domainVariables = c->getDomainVars();

        vector < shared_ptr < TVec >> poses;

        vector < shared_ptr < TVec >> defender;
        vector < shared_ptr < TVec >> blocker;
        vector < shared_ptr < TVec >> attacker;

        vector < nonstd::optional< geometry::CNPositionAllo>> robotPositions;

        for (int i = 0; i < domainVariables->at(0)->size(); i++)
        {
            c->getDomainRanges()->at(0).at(i).at(0).at(0) = -wm->field->getFieldLength() / 2;
            c->getDomainRanges()->at(0).at(i).at(0).at(1) = wm->field->getFieldLength() / 2;
            c->getDomainRanges()->at(0).at(i).at(1).at(0) = -wm->field->getFieldWidth() / 2;
            c->getDomainRanges()->at(0).at(i).at(1).at(1) = wm->field->getFieldWidth() / 2;
            auto robotPos = wm->robots->teammates.getTeammatePositionBuffer(c->getAgentsInScope()->at(0)->at(i)).getLastValidContent();
            if (!robotPos)
            {
                continue;
            }
            robotPositions.push_back(robotPos);
            auto vec = make_shared < TVec
                    > (initializer_list<shared_ptr<Term>> {dynamic_pointer_cast < autodiff::Variable
                                                                   > (domainVariables->at(0)->at(i)->at(0)),
                                                           dynamic_pointer_cast < autodiff::Variable
                                                                   > (domainVariables->at(0)->at(i)->at(1))});
            poses.push_back(vec);
            blocker.push_back(vec);
        }
        for (int i = 0; i < domainVariables->at(1)->size(); i++)
        {
            c->getDomainRanges()->at(1).at(i).at(0).at(0) = -wm->field->getFieldLength() / 2;
            c->getDomainRanges()->at(1).at(i).at(0).at(1) = wm->field->getFieldLength() / 2;
            c->getDomainRanges()->at(1).at(i).at(1).at(0) = -wm->field->getFieldWidth() / 2;
            c->getDomainRanges()->at(1).at(i).at(1).at(1) = wm->field->getFieldWidth() / 2;
            auto robotPos = wm->robots->teammates.getTeammatePositionBuffer(c->getAgentsInScope()->at(1)->at(i)).getLastValidContent();
            if (!robotPos)
            {
                continue;
            }
            robotPositions.push_back(robotPos);
            auto vec = make_shared < TVec
                    > (initializer_list<shared_ptr<Term>> {dynamic_pointer_cast < autodiff::Variable
                                                                   > (domainVariables->at(1)->at(i)->at(0)),
                                                           dynamic_pointer_cast < autodiff::Variable
                                                                   > (domainVariables->at(1)->at(i)->at(1))});
            poses.push_back(vec);
            defender.push_back(vec);
        }
        for (int i = 0; i < domainVariables->at(2)->size(); i++)
        {
            c->getDomainRanges()->at(2).at(i).at(0).at(0) = -wm->field->getFieldLength() / 2
                    + wm->field->getPenaltyAreaLength() + 550;
            c->getDomainRanges()->at(2).at(i).at(0).at(1) = wm->field->getFieldLength() / 2;
            c->getDomainRanges()->at(2).at(i).at(1).at(0) = -wm->field->getFieldWidth() / 2;
            c->getDomainRanges()->at(2).at(i).at(1).at(1) = wm->field->getFieldWidth() / 2;
            auto robotPos = wm->robots->teammates.getTeammatePositionBuffer(c->getAgentsInScope()->at(2)->at(i)).getLastValidContent();
            if (!robotPos)
            {
                continue;
            }
            robotPositions.push_back(robotPos);
            auto vec = make_shared < TVec
                    > (initializer_list<shared_ptr<Term>> {dynamic_pointer_cast < autodiff::Variable
                                                                   > (domainVariables->at(2)->at(i)->at(0)),
                                                           dynamic_pointer_cast < autodiff::Variable
                                                                   > (domainVariables->at(2)->at(i)->at(1))});
            poses.push_back(vec);
            attacker.push_back(vec);
        }
        cout << "OPFKC: poses, blocker, defender, attacker " << poses.size() << " " << blocker.size() << " "
                << defender.size() << " " << attacker.size() << endl;
        // END INITILIZE VARIABLE CONTAINER

        auto ballPose = wm->ball->getPositionAllo();
        if (!ballPose)
        {
            ballPose = nonstd::make_optional < geometry::CNPointAllo > (0, 0);
        }
        shared_ptr < TVec > tvecBallPose = make_shared < TVec > (initializer_list<double> {ballPose->x, ballPose->y});
        auto ownGoalPos = wm->field->posOwnGoalMid();
        shared_ptr < TVec > ownGoalVec = make_shared < TVec > (initializer_list<double> {ownGoalPos.x, ownGoalPos.y});
        constraint = constraint & msl::MSLConstraintBuilder::applyRules(-1, poses);

        //Just for the case when we use this after "start" has been pressed
        if (wm->game->getSituation() == msl::Situation::Start)
        {
            constraint = constraint
                    & msl::MSLConstraintBuilder::ownPenaltyAreaDistanceExceptionRule(tvecBallPose, poses);
        }

        //default nearest opp
//		shared_ptr<geometry::CNPoint2D> nearestOpp = nullptr;
//		if (ballPose != nullptr)
//			nearestOpp = make_shared<geometry::CNPoint2D>(ballPose->x - 250, ballPose->y);
//		double dist = 999999999;

        auto opps = wm->robots->opponents.getOpponentsAlloClusteredBuffer().getLastValidContent();
        vector < shared_ptr < TVec >> blockPositions;
        vector < shared_ptr < TVec >> blockOpponents;
        if (opps)
        {
            for (auto opp : *opps)
            {

                opp = wm->field->mapOutOfOwnPenalty(opp, (*ballPose) - opp);
//				double oDist = opp->distanceTo(ballPose);
//				if (oDist < dist)
//				{
//					nearestOpp = opp;
//					oDist = dist;
//				}

//add blocking position
                auto blockingPos = opp + ((*ballPose) - opp).normalize() * 700;

                //only add if opp is in close to midline && further away from ball than 1100 (that makes no sense in oppenent standards, because we already use apply rules)
                if (blockingPos.x > wm->field->getFieldLength() / 6.0 // ignore obs more than 3 meter in oppenent half
                || ballPose->distanceTo(blockingPos) < 4500 // ignore obs that are too close to the ball to be blocked
                        )
                {
                    continue;
                }

                bool toClose = false;
                for (auto opp2 : *opps)
                {
                    if (blockingPos.distanceTo(opp2) < 500)
                    {
                        toClose = true;
                        break;
                    }
                }
                if (toClose)
                {
                    continue;
                }

                cout << "OppFreeKick-Const:" << opp.toString() << endl;
                blockPositions.push_back(
                        make_shared < TVec > (initializer_list<double> {blockingPos.x, blockingPos.y}));
                blockOpponents.push_back(make_shared < TVec > (initializer_list<double> {opp.x, opp.y}));
            }
        }

//		cout << "OppFreekick before: blocker size: " << blocker.size() << " attacker size: " << attacker.size() << endl;
        while (blockPositions.size() < blocker.size())
        {
            auto temp = blocker.at(blocker.size() - 1);
            attacker.push_back(temp);
            blocker.erase(blocker.end());
        }
//		cout << "OppFreekick after: blocker size: " << blocker.size() << " attacker size: " << attacker.size() << endl;

        //attacker aka ball watcher
        if (attacker.size() > 0)
        {
            constraint = constraint & msl::MSLConstraintBuilder::see(tvecBallPose, false, 10000, attacker);

            auto utilattack = autodiff::TermBuilder::constant(0);
            auto ball2Goal = (ownGoalVec - tvecBallPose);
            for (int j = 0; j < attacker.size(); j++)
            {
                auto relPos = ConstraintBuilder::inCoordsOf(attacker.at(j) - tvecBallPose, ball2Goal);
                constraint = constraint & (relPos->normalize()->getX() > autodiff::TermBuilder::constant(-1000)); // this is always TRUE!!!
                //Near Ball
                utilattack = utilattack
                        + 100
                                * (1
                                        - ((ConstraintBuilder::distanceSqr(attacker.at(j), tvecBallPose))
                                                / (wm->field->getMaxDistanceSqr())));
                //Near own goal
                utilattack = utilattack
                        + 10
                                * (1
                                        - ((ConstraintBuilder::distanceSqr(attacker.at(j), ownGoalVec))
                                                / (wm->field->getMaxDistanceSqr())));
            }
            util = util + utilattack;
        }

        // Make a defender wall between ball and goal, care other robots
        if (defender.size() > 0)
        {
            auto direction = (*ballPose - ownGoalPos).normalize();
            auto wallVec = direction
                    * max(ownGoalPos.distanceTo(wm->field->posULOwnPenaltyArea()),
                          ballPose->distanceTo(ownGoalPos) / 2);
            auto wallPoint = ownGoalPos + wallVec;

            auto directionTVec = make_shared < TVec > (initializer_list<double> {direction.x, direction.y});
            auto wallPointTVec = make_shared < TVec > (initializer_list<double> {wallPoint.x, wallPoint.y});
            for (int j = 0; j < defender.size(); j++)
            {
                vector < shared_ptr < Term >> diffTerm;
                diffTerm.push_back(defender.at(j)->getX() - autodiff::TermBuilder::constant(wallPoint.x));
                diffTerm.push_back(defender.at(j)->getY() - autodiff::TermBuilder::constant(wallPoint.y));
                auto g2def = make_shared < TVec > (diffTerm);
                auto relPoint = ConstraintBuilder::inCoordsOf(g2def, directionTVec);
                constraint = constraint
                        & ((shared_ptr<autodiff::Term> )make_shared < autodiff::Abs > (relPoint->getX())
                                < autodiff::TermBuilder::constant(200));
                util = util
                        + 100
                                * (1
                                        - (ConstraintBuilder::distanceSqr(defender.at(j), wallPointTVec)
                                                / (wm->field->getMaxDistanceSqr())));
            }
        }

        if (blocker.size() > 0)
        {
            int opponents2BlockCount = blockPositions.size();

            for (int k = 0; k < blocker.size(); k++)
            {
                //close to block positions
                auto blockConstraints = autodiff::LTConstraint::FALSE;
                for (int j = 0; j < opponents2BlockCount; j++)
                {
//					blockUtil = make_shared<autodiff::Max>(
//							blockUtil,
//							10
//									* (1
//											- ((ConstraintBuilder::distanceSqr(blocker.at(k), blockPositions.at(j)))
//													/ (wm->field.MaxDistanceSqr * blocker.size()))));

                    blockConstraints = blockConstraints
                            | msl::MSLConstraintBuilder::insideSphere(blockPositions.at(j), 200.0, blocker.at(k));
                }
                if (opponents2BlockCount > 0)
                {
                    constraint = constraint & blockConstraints;
                }

                util = util
                        + 10
                                * (1
                                        - ((ConstraintBuilder::distanceSqr(blocker.at(k), ownGoalVec))
                                                / (wm->field->getMaxDistanceSqr())));

                //avoid opponents!
                for (int j = 0; j < opponents2BlockCount; j++)
                {
                    auto dist2Opp = ConstraintBuilder::distanceSqr(blocker.at(k), blockOpponents.at(j));
                    constraint = constraint & (dist2Opp > autodiff::TermBuilder::constant(650 * 650));
                }

                //avoid other blockers and prefer block positions with a distance of 2m (to not block the same opponents)
                for (int j = k + 1; j < blocker.size(); j++)
                {
                    auto distBlockBlock = ConstraintBuilder::distanceSqr(blocker.at(k), blocker.at(j));
                    util = util + 5 * make_shared < autodiff::Min
                            > (autodiff::TermBuilder::constant(2000 * 2000), distBlockBlock)
                                    / autodiff::TermBuilder::constant(2000 * 2000 * blocker.size());
                }
            }
        }

        //lazy utility
        vector < shared_ptr < TVec >> realRobotPosesTVec;
        for (int i = 0; i < robotPositions.size(); i++)
        {
            auto pos = robotPositions.at(i);
            if (pos)
                realRobotPosesTVec.push_back(make_shared < TVec > (initializer_list<double> {pos->x, pos->y}));
            //else
            //	realRobotPosesTVec.push_back(make_shared<TVec>(initializer_list<double> {0.0, 0.0}));
        }
        util = util + 5 * msl::MSLConstraintBuilder::lazyUtil(realRobotPosesTVec, poses);

        c->setConstraint(dynamic_pointer_cast < alica::SolverTerm > (constraint));
        c->setUtility(dynamic_pointer_cast < alica::SolverTerm > (util));
        /*PROTECTED REGION END*/
    }

// State: PosDefDefender

// State: PosDefDefender

// State: Success

// State: Success

// State: PosDefBlocker

// State: PosDefBlocker

// State: PosDefAttacker

// State: PosDefAttacker

}
