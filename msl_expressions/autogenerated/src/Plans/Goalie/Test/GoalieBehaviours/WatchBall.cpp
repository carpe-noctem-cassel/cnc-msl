using namespace std;
#include "Plans/Goalie/Test/GoalieBehaviours/WatchBall.h"

/*PROTECTED REGION ID(inccpp1447863466691) ENABLED START*/ // Add additional includes here
#include <Ball.h>
#include <RawSensorData.h>
#include <cmath>
#include <obstaclehandler/Obstacles.h>
#include <msl_robot/robotmovement/RobotMovement.h>
#include <msl_robot/MSLRobot.h>
#include <msl_actuator_msgs/VisionRelocTrigger.h>
#include <Game.h>
#include <vector>
/*PROTECTED REGION END*/
namespace alica
{
/*PROTECTED REGION ID(staticVars1447863466691) ENABLED START*/
/*PROTECTED REGION END*/
WatchBall::WatchBall()
    : DomainBehaviour("WatchBall")
{
    /*PROTECTED REGION ID(con1447863466691) ENABLED START*/ // Add additional options here

	// Read in config values.
    goalieSize = (*this->sc)["Behaviour"]->get<int>("Goalie.GoalieSize", NULL);
    snapDistance = (*this->sc)["Behaviour"]->get<int>("Goalie.SnapDistance", NULL);
    ballMovingThreshold = (*this->sc)["Behaviour"]->get<double>("Goalie.BallMovingThreshold", NULL);
    const auto maxRotationDeg = (*this->sc)["Behaviour"]->tryGet<double>(45.0, "Goalie.MaxRotation", NULL);
    maxRotationRad = maxRotationDeg * (M_PI/180.0);

	// Ros node for relocMsg
    ros::NodeHandle n;
	relocPub = n.advertise<msl_actuator_msgs::VisionRelocTrigger>(
			"/CNActuator/VisionRelocTrigger", 10);

	// Create query for movement.
    query = make_shared<msl::MovementQuery>();
    /*PROTECTED REGION END*/
}
WatchBall::~WatchBall()
{
    /*PROTECTED REGION ID(dcon1447863466691) ENABLED START*/ // Add additional options here
    /*PROTECTED REGION END*/
}
void WatchBall::run(void *msg)
{
    /*PROTECTED REGION ID(run1447863466691) ENABLED START*/ // Add additional options here
    ownPos = wm->rawSensorData->getOwnPositionVision();
    msl_actuator_msgs::MotionControl mc;

    // Stop Robot if own position is unknown
    if (ownPos == nullptr)
    {
        mc.motion.translation = 0;
        mc.motion.angle = 0;
        mc.motion.rotation = 0;
        send(mc);
        cout << "[WatchBall]: ownPos is null" << endl;
        return;
    }

    const auto alloGoalMid = wm->field->posOwnGoalMid();
    alloGoalLeft = make_shared<geometry::CNPoint2D>(
    		alloGoalMid->x, wm->field->posLeftOwnGoalPost()->y - goalieSize / 2);
    alloGoalRight = make_shared<geometry::CNPoint2D>(
    		alloGoalMid->x, wm->field->posRightOwnGoalPost()->y + goalieSize / 2);
    
    alloBall = wm->ball->getAlloBallPosition();

    auto laserGoalOffset = wm->rawSensorData->getEgoGoalMid();
	bool laserDetectedGoal = laserGoalOffset != nullptr;
		if (laserDetectedGoal) {
		// TODO: Eventually reloc every second or so
			printf("laserGoalOffset: x: %f y: %f\n",
					laserGoalOffset->x, laserGoalOffset->y);
			
			geometry::CNPoint2D relocPos;
			relocPos.x = alloGoalMid->x + laserGoalOffset->x;
			relocPos.y = alloGoalMid->y + laserGoalOffset->y;

			printf("relocPos: x: %f y: %f\n",
					relocPos.x, relocPos.y);

			sendReloc(relocPos, 0.0);
		}

	// Special case that depend on the ball presence and position.
    // If ball is not seen or the ball is further away than the goal mid point is.
    if (alloBall == nullptr // Ball is not seen
		|| abs(alloBall->x) > abs(alloGoalMid->x) + 50 // Ball is behind goal
		|| alloBall->x > 1000) // Ball is in opponent half, TODO: Probably make configurable
    {
        // Goalie drives to last known target and rotates towards mirrored own position
        // cout << "[WatchBall]: Special case: Moving to GoalMid" << endl;
        mc = driveAndAlignTo(alloGoalMid, mirroredOwnPos());
        send(mc);
        return;
    }

    // Calculate target position on goal line.
	
	// Lambda that returns one prediction of the goal impact or nullptr if
	// a prediction is not possible.
	auto determineTarget = [&]() -> shared_ptr<geometry::CNPoint2D> {

		// Retrieve ball velocity vector
		auto ballVec = wm->ball->getEgoBallVelocity();

		double targetY = 0;

		const auto calcResult = calcGoalImpactY(alloBall, ballVec, alloGoalMid->x);
		bool wouldImpact = calcResult.first;
		double impactPoint = calcResult.second;

		if (ballIsMoving(ballVec) && wouldImpact) {
			targetY = impactPoint;
		} else {
			// if ball is not moving or would not hit goal, then
			// do drive to ball height.
			targetY = alloGoalMid->y;
		} // TODO: Try out speculative keeping

		// Limit or clamp targetY to goal area
		targetY = fitTargetY(targetY, alloGoalLeft->y, alloGoalRight->y);
		const double offsetX = 80;
		const double targetX = alloGoalMid->x + offsetX;

		return make_shared<geometry::CNPoint2D>(targetX, targetY);
	};

	auto alloTarget = determineTarget();

	//sdf If alloTarget was not calculated, move to the goal mid.
	if (alloTarget == nullptr) {
		alloTarget = alloGoalMid;
	}

	//printf("Driving to target: %f %f\n", alloTarget->x, alloTarget->y);

	// Finaly if a goal impact can be calculated drive to the calculated impact
	mc = faster(driveAndAlignTo(alloTarget, mirroredOwnPos()));

    send(mc);

    /*PROTECTED REGION END*/
}
void WatchBall::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1447863466691) ENABLED START*/ // Add additional options here
    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1447863466691) ENABLED START*/ // Add additional methods here
pair<bool, double> WatchBall::calcGoalImpactY(
		shared_ptr<geometry::CNPoint2D> alloBallPos,
		shared_ptr<geometry::CNVelocity2D> egoBallVel,
		const double goalLineX)
{
	if (egoBallVel == nullptr || alloBallPos == nullptr) {
		return std::make_pair(false, 0.0);
	}

	// Calculation itself.
	// I solved the vector equation for a line for y.
	const auto bvx = -egoBallVel->x; // ball velocity x
	const auto bvy = -egoBallVel->y;
	const auto bpx = alloBallPos->x; // ball position x
	const auto bpy = alloBallPos->y;

	if (bvx >= 0) {
		//puts("Ball not moving to our direction");
		return std::make_pair(false, 0.0);
	}

	const auto y = bpy + ((goalLineX-bpx)/bvx) * bvy;

	return std::make_pair(true, y);
}

bool WatchBall::ballIsMoving(shared_ptr<geometry::CNVelocity2D> ballVec)
{
	// Retrieve ball velocity vector
	if (ballVec == nullptr) {
		return 0; // TODO: Indicate error
	}
	const auto ballSpeed = ballVec->length();
	return ballSpeed >= ballMovingThreshold;
}

double WatchBall::fitTargetY(double targetY, double goalLeft, double goalRight)
{
    if (targetY > goalLeft) {
        return goalLeft;
    } else if (targetY < goalRight) {
        return goalRight;
    }
    return targetY;
}

double WatchBall::clampRotation(double mcRotation, double ownTheta, double maxRot)
{
	if (ownTheta > maxRot && mcRotation > 0) {
		return 0;
	}

	if (ownTheta < -(maxRot) && mcRotation < 0) {
		return 0;
	}

	return mcRotation;
}

msl_actuator_msgs::MotionControl WatchBall::driveAndAlignTo(
	shared_ptr<geometry::CNPoint2D> targetAllo,
	shared_ptr<geometry::CNPoint2D> alloAlginPoint
	)
{
	msl_actuator_msgs::MotionControl mc;

	auto egoAlignPoint = alloAlginPoint->alloToEgo(*ownPos);
	auto egoTarget = targetAllo->alloToEgo(*ownPos);

	// Build Query
	query->egoDestinationPoint = egoTarget;
	query->egoAlignPoint = egoAlignPoint;
	query->snapDistance = snapDistance; // TODO: Test if rotation still works
	// Add goal posts as obstacles
	auto additionalPoints = make_shared<vector<shared_ptr<geometry::CNPoint2D>>>();
	additionalPoints->push_back(alloGoalLeft);
	additionalPoints->push_back(alloGoalRight);
	query->additionalPoints = additionalPoints;
	// TODO: Test if good
	query->blockOwnPenaltyArea = true;
	mc = robot->robotMovement->moveToPoint(query);

	return mc;
}

MotionControl WatchBall::faster(MotionControl in)
{
	in.motion.translation *= 2; // Foxy, move faster!
	// TODO: Probably remove as soon as motion is fixed
	// Clamp translation because of motion failure
	if (in.motion.translation > 1500) {
		in.motion.translation = 1500;
	}
	return in;
}

shared_ptr<geometry::CNPoint2D> WatchBall::mirroredOwnPos() {
	auto mirrored = std::make_shared<geometry::CNPoint2D>(
			ownPos->x+1000, ownPos->y);
	return mirrored;
}

void WatchBall::sendReloc(geometry::CNPoint2D alloRelocPos, double heading) {
	msl_actuator_msgs::VisionRelocTrigger vrt;
	vrt.receiverID = 12; // TODO: Fetch robot id from alica
	vrt.usePose = true; // TODO: Fetch robot id from alica

	vrt.position = toVisionCoordinates(alloRelocPos.x, alloRelocPos.y, heading);

	relocPub.publish(vrt);
}

msl_msgs::PositionInfo
WatchBall::toVisionCoordinates(double x, double y, double heading) {
	msl_msgs::PositionInfo pi;

	// Eventuall convert coordinates
	if (wm->game->ownGoalColor != Color::Yellow) // == Blue?
	{
		pi.x = -x;
		pi.y = -y;

		heading += M_PI;
		while (heading > M_PI)
		{
			heading -= 2 * M_PI;
		}
		heading += M_PI;
		while (heading > M_PI)
		{
			heading -= 2 * M_PI;
		}
		pi.angle = heading;
	}

	pi.certainty = 100.0;

	return pi;
}

/*PROTECTED REGION END*/
} /* namespace alica */
