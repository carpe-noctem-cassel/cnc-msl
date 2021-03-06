#include "Plans/Standards/Own/PassIntoPath/constraints/PassIntoPath1457530916296Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1457530916296) ENABLED START*/
#include <memory>
#include "AutoDiff.h"
#include "MSLConstraintBuilder.h"
#include "MSLFootballField.h"
#include "engine/constraintmodul/SolverTerm.h"
#include "engine/constraintmodul/ProblemDescriptor.h"
#include "MSLWorldModel.h"
#include <Robots.h>
#include <WhiteBoard.h>
#include <Ball.h>
/*PROTECTED REGION END*/

namespace alicaAutogenerated
{
    //Plan:PassIntoPath

    /*		
     * Tasks: 
     * - EP:1457530916298 : ExecuteStandard (1439997010902)
     * - EP:1457530953060 : ReceiveStandard (1439997023446)
     * - EP:1457531047960 : Block (1461237765109)
     *
     * States:
     * - Align (1457530916297)
     * - Align (1457531111752)
     * - Block (1457531122593)
     * - GrabBall (1457531267822)
     * - PassKick (1457531281152)
     * - SpatialDefend (1457531293259)
     * - ReceiveAtTarget (1457531324804)
     * - NewSuccessState (1457531345727)
     *
     * Vars:				
     * - passGoalX (1457531196542) 				
     * - passGoalY (1457531200123) 
     */

    /*
     * RuntimeCondition - (Name): NewRuntimeCondition
     * (ConditionString): 
     * Static Variables: [passGoalX, passGoalY]
     * Domain Variables:

     * forall agents in Block let v = [x, y] 

     */
    void Constraint1457531039142::getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(cc1457531039142) ENABLED START*/
        msl::MSLWorldModel* wm = msl::MSLWorldModel::get();
        auto constraint = autodiff::LTConstraint::TRUE;
        auto util = autodiff::TermBuilder::constant(0);
        auto domainVariables = c->getDomainVars();

        vector < shared_ptr < TVec >> poses;
        vector < shared_ptr < TVec >> blocker;
        vector < shared_ptr < geometry::CNPosition >> robotPositions;

        c->getStaticRanges()->at(0).at(0) = -wm->field->getFieldLength() / 2;
        c->getStaticRanges()->at(0).at(1) = wm->field->getFieldLength() / 2;
        c->getStaticRanges()->at(1).at(0) = -wm->field->getFieldWidth() / 2;
        c->getStaticRanges()->at(1).at(1) = wm->field->getFieldWidth() / 2;

        vector < shared_ptr < autodiff::Term >> targetPosVec;
        targetPosVec.push_back(dynamic_pointer_cast < autodiff::Term > (c->getStaticVars()->at(0)));
        targetPosVec.push_back(dynamic_pointer_cast < autodiff::Term > (c->getStaticVars()->at(1)));
        shared_ptr < autodiff::TVec > passGoal = make_shared < autodiff::TVec > (targetPosVec);

        for (int i = 0; i < domainVariables->at(0)->size(); i++)
        {
            c->getDomainRanges()->at(0).at(i).at(0).at(0) = -wm->field->getFieldLength() / 2 + 1000;
            c->getDomainRanges()->at(0).at(i).at(0).at(1) = wm->field->getFieldLength() / 2 - 1000;
            c->getDomainRanges()->at(0).at(i).at(1).at(0) = -wm->field->getFieldWidth() / 2 + 1000;
            c->getDomainRanges()->at(0).at(i).at(1).at(1) = wm->field->getFieldWidth() / 2 - 1000;
            auto robotPos = wm->robots->teammates.getTeamMatePosition(c->getAgentsInScope()->at(0)->at(i));
			if (!robotPos)
			{
				//safety measure in case one agent crashes
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

        shared_ptr < geometry::CNPoint2D > ballPose = wm->ball->getAlloBallPosition();
        if (ballPose == nullptr)
        {
            ballPose = make_shared < geometry::CNPoint2D > (0, 0);
        }
        shared_ptr < TVec > tvecBallPose = make_shared < TVec > (initializer_list<double> {ballPose->x, ballPose->y});

        constraint = constraint & msl::MSLConstraintBuilder::applyRules(-1, poses);

        auto opps = wm->robots->opponents.getOpponentsAlloClustered();

        vector < shared_ptr < TVec >> blockPositions;
        vector < shared_ptr < TVec >> lossGoodBlockOpponents;
        shared_ptr < geometry::CNPoint2D > nearestOpp = nullptr;
        //default nearest opp

        if (opps != nullptr)
        {
            for (auto opp : *opps)
            {
                //Ignore opponents in opp penalty area
                if (opp->x < (-wm->field->getFieldLength() / 2 + wm->field->getPenaltyAreaLength())
                        || opp->x > (wm->field->getFieldLength() / 2 - wm->field->getPenaltyAreaLength())
                        || opp->y > wm->field->getFieldWidth() / 2 - 1000
                        || opp->y < -wm->field->getFieldWidth() / 2 + 1000)
                    continue;

                //Map opponent out of own penalty area
                if (ballPose != nullptr)
                {
                    wm->field->mapOutOfOwnPenalty(opp, ballPose - opp);
                }
                else
                {
                    opp = wm->field->mapOutOfOwnPenalty(opp);
                }

                //add blocking position
                shared_ptr < geometry::CNPoint2D > blockingPos;
                if (ballPose != nullptr)
                {
                    blockingPos = opp + (ballPose - opp)->normalize() * 700;
                }
                else
                {
                    blockingPos = make_shared < geometry::CNPoint2D > (opp->x - 700, opp->y);
                }

                //only add if opp is in close to midline
                if (blockingPos->x < wm->field->getFieldLength() / 6.0 && ballPose->distanceTo(blockingPos) > 1100)
                {
                    blockPositions.push_back(
                            make_shared < TVec > (initializer_list<double> {blockingPos->x, blockingPos->y}));
                }
                else if (ballPose != nullptr && ballPose->distanceTo(opp) > 1100
                        && ballPose->distanceTo(opp) < wm->field->getFieldLength() * 0.35)
                {
                    blockPositions.push_back(
                            make_shared < TVec > (initializer_list<double> {blockingPos->x, blockingPos->y}));
                }
                else
                {
                    lossGoodBlockOpponents.push_back(make_shared < TVec > (initializer_list<double> {blockingPos->x,
                                                                                                     blockingPos->y}));
                }
            }
        }
        //Compute opponents, which should be blocked
        //In der Not isst der Mensch die Ahle Wurscht auch ohne Brot!
        //In case of emergency human beings eat old sausages without bread!
        int opponents2BlockCount = blockPositions.size();
        if (blocker.size() > opponents2BlockCount)
        {
            for (int k = 0; k < min(lossGoodBlockOpponents.size(), blocker.size() - opponents2BlockCount); k++)
            {
                blockPositions.push_back(lossGoodBlockOpponents.at(k));
                opponents2BlockCount++;
            }
        }

        //Define Utility for Blockerposition
        if (blocker.size() > 0)
        {
            int opponents2BlockCount = blockPositions.size();

            constraint = constraint & msl::MSLConstraintBuilder::see(tvecBallPose, true, 10000, blocker);

            for (int k = 0; k < blocker.size(); k++)
            {
                //close to block positions
                auto blockUtil = autodiff::TermBuilder::constant(0);
                //for (int j = 0; j < min(opponents2BlockCount, (int)blocker.size()); j++)
                for (int j = 0; j < opponents2BlockCount; j++)
                {
                    blockUtil = make_shared < autodiff::Max
                            > (blockUtil, 10
                                    * (1
                                            - ((ConstraintBuilder::distanceSqr(blocker.at(k), blockPositions.at(j)))
                                                    / (wm->field->getMaxDistanceSqr() * blocker.size()))));
                }
                util = util + blockUtil;

                //avoid other blockers and prefer block positions with a distance of 2m (to not block the same opponents)
                for (int j = k + 1; j < blocker.size(); j++)
                {
                    auto distBlockBlock = ConstraintBuilder::distanceSqr(blocker.at(k), blocker.at(j));
                    constraint = constraint & distBlockBlock > autodiff::TermBuilder::constant(800 * 800);
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
            if (pos != nullptr)
                realRobotPosesTVec.push_back(make_shared < TVec > (initializer_list<double> {pos->x, pos->y}));
            else
                realRobotPosesTVec.push_back(make_shared < TVec > (initializer_list<double> {0.0, 0.0}));
        }
        util = util + msl::MSLConstraintBuilder::lazyUtil(realRobotPosesTVec, poses);

        //Compute passGoal
        auto passVec = passGoal - tvecBallPose;
        shared_ptr < TVec > msgPoint;

        auto pm = wm->whiteBoard->getPassMsg();
        //Consider Passmsg
        /*
         if(pm != null) {
         msgPoint = new AD.TVec(pm.Destination.X, pm.Destination.Y);
         if(wm.GetSituation==Situation.Start) {
         c.Constraint &= ConstraintBuilder.DistanceSqr(msgPoint, passGoal) < 1000*1000;
         c.Utility += 1-ConstraintBuilder.DistanceSqr(msgPoint, passVec)/field.MaxDistanceSqr;
         }
         else {
         c.Utility += 1-ConstraintBuilder.DistanceSqr(msgPoint, passVec)/field.MaxDistanceSqr;
         }
         }

         //5s after "Start": Don't change the goal anymore
         if((wm.GetSituation == Situation.Start) && (RosCS.RosSharp.Now()-wm.LastStartSignalTime) > 5ul*1000000000ul) {
         if(msgPoint!=null) {
         c.Constraint &= ConstraintBuilder.DistanceSqr(msgPoint, passGoal) < 100*100;
         return;
         }
         }

         //Min and Max pass distance
         c.Constraint &= ConstraintBuilder.DistanceSqr(passGoal, bvec)<3000*3000;
         c.Constraint &= ConstraintBuilder.DistanceSqr(passGoal, bvec)>2500*2500;

         //Dont kick towards outside field
         //Left / Right
         AD.Term Tan = passVec.Y/passVec.X;
         double badAngleRangeY = 0.5*Math.PI* ((Math.Abs(ball.Y))/(field.FieldWidth/2)+0.35);
         if(ball.Y>0) {
         c.Constraint &= ConstraintBuilder.IfThen(passVec.Y>0, Tan > Math.Tan(Math.PI/2+badAngleRangeY) | Tan < Math.Tan(Math.PI/2-badAngleRangeY));
         } else {
         c.Constraint &= ConstraintBuilder.IfThen(passVec.Y<0, Tan > Math.Tan(3*Math.PI/2+badAngleRangeY) | Tan < Math.Tan(3*Math.PI/2-badAngleRangeY));
         }
         //Top / Bottom
         double badAngleRangeX = 0.5*Math.PI* ((Math.Abs(ball.X))/(field.FieldLength/2)+0.25);

         if(ball.X>0) {
         c.Constraint &= ConstraintBuilder.IfThen(passVec.X>0, Tan > Math.Tan(badAngleRangeX) | Tan < Math.Tan(-badAngleRangeX));
         } else {
         c.Constraint &= ConstraintBuilder.IfThen(passVec.X<0, Tan > Math.Tan(Math.PI+badAngleRangeX) | Tan < Math.Tan(Math.PI-badAngleRangeX));
         }
         //Never aim towards own goal
         c.Constraint &= ConstraintBuilder.IfThen(passVec.X<0, Math.Tan(Math.PI/4) > new AD.Abs(Tan - ((ball.X + field.PosOwnGoalMid.X)/(ball.Y + field.PosOwnGoalMid.Y))));

         //prefer angle towards goal
         //c.Utility += 10*(passVec.Y/passVec.X - ((ball.X + field.PosOppGoalMid.X)/(ball.Y + field.PosOppGoalMid.Y)));
         //prefer short pass
         //c.Utility += 1 - ConstraintBuilder.DistanceSqr(passGoal, bvec)/field.MaxDistanceSqr;
         //prefer center and oppnent
         c.Utility += 1 - new AD.Abs(passGoal.Y)/field.FieldWidth;
         c.Utility += (passGoal.X*2)/field.FieldLength;
         //avoid opponents
         {
         AD.Term OppUtil = 0;
         for(int j=0; j<blockPositions.Count; j++) {
         OppUtil += 100.0*(ConstraintBuilder.DistanceSqr(passGoal, blockPositions[j]))/(field.MaxDistanceSqr);
         }
         if(blockPositions.Count>0) c.Utility += OppUtil/blockPositions.Count;
         }*/
        /*PROTECTED REGION END*/
    }

// State: Align

// State: Align

// State: Align

// State: Align

// State: Block

// State: Block

// State: GrabBall

// State: GrabBall

// State: PassKick

// State: PassKick

// State: SpatialDefend

// State: SpatialDefend

// State: ReceiveAtTarget

// State: ReceiveAtTarget

// State: NewSuccessState

// State: NewSuccessState

}
