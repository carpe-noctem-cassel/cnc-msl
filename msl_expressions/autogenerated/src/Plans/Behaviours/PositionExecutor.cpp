using namespace std;
#include "Plans/Behaviours/PositionExecutor.h"

/*PROTECTED REGION ID(inccpp1438790362133) ENABLED START*/ // Add additional includes here
#include "engine/Assignment.h"
#include "engine/RunningPlan.h"
#include "engine/model/EntryPoint.h"
#include "engine/model/Plan.h"

#include "MSLWorldModel.h"
#include "pathplanner/PathProxy.h"
#include "pathplanner/evaluator/PathEvaluator.h"

#include <Ball.h>
#include <Game.h>
#include <RawSensorData.h>
#include <Robots.h>

/*PROTECTED REGION END*/
namespace alica
{
/*PROTECTED REGION ID(staticVars1438790362133) ENABLED START*/ // initialise static variables here
/*PROTECTED REGION END*/
PositionExecutor::PositionExecutor()
    : DomainBehaviour("PositionExecutor")
{
    /*PROTECTED REGION ID(con1438790362133) ENABLED START*/ // Add additional options here
    readConfigParameters();
    /*PROTECTED REGION END*/
}
PositionExecutor::~PositionExecutor()
{
    /*PROTECTED REGION ID(dcon1438790362133) ENABLED START*/ // Add additional options here
    /*PROTECTED REGION END*/
}
void PositionExecutor::run(void *msg)
{
    /*PROTECTED REGION ID(run1438790362133) ENABLED START*/ // Add additional options here
    msl::RobotMovement rm;

    auto ownPos =
        wm->rawSensorData->getOwnPositionVisionBuffer().getLastValidContent(); // actually ownPosition corrected
    auto egoBallPos = wm->ball->getPositionEgo();

    // return if necessary information is missing
    if (!ownPos || !egoBallPos)
    {
        return;
    }

    // Create allo ball
    auto alloBall = egoBallPos->toAllo(*ownPos);



    // get entry point of task name to locate robot with task name

    if (receiverEp != nullptr)
    {
        // get the plan in which the behavior is running
        auto parent = this->runningPlan->getParent().lock();
        if (parent == nullptr)
        {
            cout << "parent null" << endl;
            return;
        }
        // get robot ids of robots in found entry point
        shared_ptr<vector<int>> ids = parent->getAssignment()->getRobotsWorking(receiverEp);
        nonstd::optional<geometry::CNPositionAllo> receiverPos;
        // exactly one robot is receiver
        int id = ids->at(0);
        if (id != -1)
        {
            // get receiver position by id
            receiverPos = wm->robots->teammates.getTeammatePositionBuffer(id).getLastValidContent();
        }

        geometry::CNPointEgo egoTarget;
        if (receiverPos)
        {
            // calculate target 60cm away from the ball and on a line with the receiver
            egoTarget = (alloBall + ((alloBall - receiverPos->getPoint()).normalize() * ballDistanceEx)).toEgo(*ownPos);
        }
        else
        {
            // if there is no receiver, align to middle
            egoTarget = (alloBall + alloTargetOffset).toEgo(*ownPos);
        }

        if (this->wm->game->getSituation() == msl::Situation::Start)
        {   // they already pressed start and we are still positioning, so speed up!
            query.snapDistance = fastCatchRadius;
            query.fast = true;
        }
        else
        {   // still enough time to position ...
            query.snapDistance = slowCatchRadius;
            query.fast = false;
        }

        query.egoDestinationPoint = egoTarget;
        query.egoAlignPoint = egoBallPos;
        // Create additional points for with ball path planning
        vector<geometry::CNPointAllo> additionalPoints;
		additionalPoints.push_back(alloBall);
        query.additionalPoints = additionalPoints;
        msl_actuator_msgs::MotionControl mc = rm.moveToPoint(query);

        // if we reached the point and are aligned, the behavior is successful
        if (mc.motion.translation == 0.0 && fabs(egoBallPos->rotateZ(M_PI).angleZ()) < (M_PI / 180) * alignTolerance)
        {
            this->setSuccess(true);
        }
        if (!std::isnan(mc.motion.translation))
        {
            send(mc);
        }
        else
        {
            cout << "Motion command is NaN!" << endl;
        }
    }
    /*PROTECTED REGION END*/
}
void PositionExecutor::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1438790362133) ENABLED START*/ // Add additional options here
    string receiverTaskName;
    if (getParameter("receiverTask", receiverTaskName))
    {
        receiverEp = this->getParentEntryPoint(receiverTaskName);
    }

    if (receiverEp == nullptr)
    { // there is no entrypoint with the receiver task given by the behaviour parameters
        auto parent = this->runningPlan->getParent().lock();
        if (parent != nullptr && ((Plan *)parent->getPlan())->getEntryPoints().size() == 2)
        { // there is only one other entry point than our own entry point, so it must be the receivers entry point.

            // which is my own entry point, so take the other one for the receiver
            auto activeEp = this->runningPlan->getActiveEntryPoint();
            auto eps = ((Plan *)parent->getPlan())->getEntryPoints();

            for (auto ep : eps)
            {
                if (ep.first != activeEp->getId())
                {
                    receiverEp = ep.second;
                    break;
                }
            }
        }
        else
        {
            cerr << "PositionExecutor: Could not determine the receivers entry point!" << endl;
            throw std::runtime_error("PositionExecutor: Could not determine the receivers entry point!");
        }
    }
    else
    { // we found the entry point of the receiver, so everything is cool
    }

    // set some static member variables
    alloTargetOffset = geometry::CNVecAllo(-500, 0);
    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1438790362133) ENABLED START*/ // Add additional methods here
void PositionExecutor::readConfigParameters()
{
    supplementary::SystemConfig *sc = supplementary::SystemConfig::getInstance();
    fastCatchRadius = (*sc)["Drive"]->get<double>("Drive.Fast.CatchRadius", NULL);
    slowCatchRadius = (*sc)["Drive"]->get<double>("Drive.Carefully.CatchRadius", NULL);
    alignTolerance = (*sc)["Drive"]->get<double>("Drive.Default.AlignTolerance", NULL);
    ballDistanceEx = (*sc)["Drive"]->get<double>("Drive.KickOff.BallDistEx", NULL);
}
/*PROTECTED REGION END*/
} /* namespace alica */
