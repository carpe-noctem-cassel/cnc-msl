using namespace std;
#include "Plans/TestPlans/DribbleControlTest/DribbleControlMOS.h"

/*PROTECTED REGION ID(inccpp1479905178049) ENABLED START*/ //Add additional includes here
#include "msl_actuator_msgs/BallHandleCmd.h"
#include "RawSensorData.h"
#include "MSLWorldModel.h"
#include "math.h"
#include "SystemConfig.h"
#include "Ball.h"
/*PROTECTED REGION END*/
namespace alica
{
	/*PROTECTED REGION ID(staticVars1479905178049) ENABLED START*/ //initialise static variables here
	/*PROTECTED REGION END*/
	DribbleControlMOS::DribbleControlMOS() :
			DomainBehaviour("DribbleControlMOS")
	{
		/*PROTECTED REGION ID(con1479905178049) ENABLED START*/ //Add additional options here
		this->sc = supplementary::SystemConfig::getInstance();
		dkFactor = 1;
		testingMode = false;
		/*PROTECTED REGION END*/
	}
	DribbleControlMOS::~DribbleControlMOS()
	{
		/*PROTECTED REGION ID(dcon1479905178049) ENABLED START*/ //Add additional options here
		/*PROTECTED REGION END*/
	}

	//sends ballhandleCmd depending on odometry
	void DribbleControlMOS::run(void* msg)
	{
		/*PROTECTED REGION ID(run1479905178049) ENABLED START*/ //Add additional options here
		//---
		// 1 only rotation, increases by pi/3 every time
		// 2 rotation with increasing translation speed, rotation increases every ten times
		// 3 rotation with changing translation angle
		// 4 changing translation angle
		// 5 increasing speed
		// default forth and back
		auto odom = wm->rawSensorData->getOwnVelocityMotion();

		if (odom == nullptr)
		{
			cerr << "DribbleControlMOS: no odometry!" << endl;
			return;
		}

		auto robotAngle = odom->angle;
		auto robotVel = odom->translation;
		auto robotRot = (double)odom->rotation;
		msl_actuator_msgs::BallHandleCmd msgback;

		cout << "Angle odometry = " << robotAngle << endl;
		cout << "translation odometry = " << robotVel << endl;
		cout << "rotation odometry = " << robotRot << endl;

		bool haveBall = wm->ball->haveBall();

		if (!haveBall && !testingMode)
		{
			msgback.rightMotor = -speedNoBall;
			msgback.leftMotor = -speedNoBall;
			send(msgback);
			return;
		       }

//		auto robotAngle = 0;
//		auto robotVel = 1000;
//		auto robotRot = 1.5;

		cout << "robotAngle odometry = " << robotAngle << endl;
		cout << "robotVel odometry = " << robotVel << endl;
		cout << "robotRot odometry = " << robotRot << endl;

//	auto ballVel = getBallVelocity(robotAngle, robotVel, robotRot);
//	auto ballAngle = getBallAngle(robotAngle, robotVel, robotRot);

		double velX;
		double velY;

		//calculates desired ball path depending on robot movement, corrected to guarantee grip
		getBallPath(robotVel, robotAngle, robotRot, velX, velY);
		auto ballVel = getBallVelocity(velX, velX);
		auto ballAngle = getBallAngle(velX, velY);

		cout << "DribbleControlMOS::run: ballVel = " << ballVel << endl;
		cout << "DribbleControlMOS::run: ballAngle = " << ballAngle << endl;

		//calculates dribble wheel velocities depending on Ball path
		auto right = getRightArmVelocity(ballVel, ballAngle);
		auto left = getLeftArmVelocity(ballVel, ballAngle);

		//depends on hardware connection, left and right in this method are as seen from the robots point of view
		msgback.leftMotor = right;
		msgback.rightMotor = left;
		cout << "DribbleControlMOS: BHC: left: " << msgback.leftMotor << " right: " << msgback.rightMotor << endl;
		send(msgback);

//        cout << "DribbleControlMOS:: " << robotAngle << "  " << robotVel << "  " << robotRot << "  " << ballVel << "  "
//                << ballAngle << "  " << left << " " << right << endl;

		/*PROTECTED REGION END*/
	}
	void DribbleControlMOS::initialiseParameters()
	{
		/*PROTECTED REGION ID(initialiseParameters1479905178049) ENABLED START*/ //Add additional options her
		testBehaviour = (*sc)["DribbleAlround"]->get<int>("DribbleAlround.testBehaviour", NULL);
		testSpeed = (*sc)["DribbleAlround"]->get<int>("DribbleAlround.testSpeed",
		NULL);
		testAngle = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.testAngle",
		NULL) * M_PI;
		testRot = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.testRot",
		NULL) * M_PI;
		testCount = 0;
		testCount = 0;

		velToInput = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.velToInput", NULL);
		staticUpperBound = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.staticUpperBound", NULL);
		staticMiddleBound = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.staticMiddleBound", NULL);
		staticLowerBound = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.staticLowerBound", NULL);
		staticNegVelX = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.staticNegVelX", NULL);
		rBallRobot = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.rBallRobot", NULL);
		epsilonT = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.epsilonT",
		NULL);
		epsilonRot = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.epsilonRot", NULL);
		epsilonY = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.epsilonY",
		NULL);
		velYFactor = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.velYFactor", NULL);
		powerFactor = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.powerFactor", NULL);
		transTolerance = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.transTolerance", NULL);
		rotTolerance = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.rotTolerance", NULL);
		angleTolerance = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.angleTolerance", NULL);
		testingMode = (*sc)["DribbleAlround"]->get<bool>("DribbleAlround.testingMode", NULL);
		powerOfRotation = (*sc)["DribbleAlround"]->get<double>("DribbleAlround.powerOfRotation", NULL);

		speedNoBall = (*sc)["Actuation"]->get<double>("Dribble.SpeedNoBall", NULL);

		phi = M_PI / 6; //horizontal angle between y and arm

		//very static
		forwConst = sqrt(
				(sin(M_PI / 2 - 0.82)) * sin(M_PI / 2 - 0.82)
						+ (sin(0.75) * cos(M_PI / 2 - 0.82)) * (sin(0.75) * cos(M_PI / 2 - 0.82))) / cos(0.349); //ballVel -> ArmVel for forward
		sidewConst = sin(0.559) / sin(0.438); //ballVel -> ArmVel for sideways
		diagConst = sin(1.18) / (cos(0.349) * sin(0.82)); //ballVel -> ArmVel for diagonal

		/*PROTECTED REGION END*/
	}
	/*PROTECTED REGION ID(methods1479905178049) ENABLED START*/ //Add additional methods here

	//calculates desired ball path depending on the robot movement and corrected to ensure grib
	void DribbleControlMOS::getBallPath(double translation, double angle, double rotation, double &velX, double &velY)
	{
	        //ball velocity form only the robots translation
		double velXTemp = -cos(angle) * translation;
		double velYTemp = -sin(angle) * translation;

		//correcting desired ball velocity towards robot to guarantee grib
		//			velX -= epsilonT * abs(translation) + epsilonRot * abs(rotation);
		velX = velXTemp;

		//correction of velocity in x , depending on x (epsilonT), depending on y (epsilonY)
		//epsilonT<1 ; epsilonY<0.45*velYFactor
		velX = velX - (epsilonT * velXTemp * sign(velXTemp)) - epsilonY * velYTemp * sign(velYTemp);

		//correction of velocity in x depending on rotation (epsilonRot)
		if (fabs(velYTemp) > 200)
		{
		    //special case where y velocity and rotation result in positive x velocity (sign(velY)!=sign(rot))
			velX = velX - epsilonRot * sign(velYTemp) * rBallRobot * rotation;
		}
		else
		{
			// rotation goes in nonlinear to fit for high as well as low
			velX = velX - epsilonRot * pow(rotation * sign(rotation), powerOfRotation)* rBallRobot;
		}

		//rotation results in y velocity of the ball
		velY = velYTemp + 3.0 / 4.0 * rBallRobot * rotation;

		//factor so robot can hold the ball if driving sideways
		velY = velY * velYFactor;

//	double powerFactor = 2;
//	double transTolerance = 200;
//	double rotTolerance = 0.4;
//	double angleTolerance = 0.4;

		// for higher grip when starting motion, we multiply the velocity with powerFactor for the first iterations
		//only for negative x, so we don't push the ball out
		if (velXTemp < 0)
		{
		    //detect jumo in odometry values
			if (transTolerance <= fabs(translation - translationOld)
					&& rotTolerance <= fabs(rotation - rotationOld)
					&& angleTolerance <= fabs(angle - angleOld))
			{
			    //powerFactor decays over the iterations
				double newPowerFactor = powerFactor * dkFactor;
				velY = velY * newPowerFactor;
				velX = velX * newPowerFactor;
				dkFactor = dkFactor <= 1 ? 1 : dkFactor - 0.1;
			}
			else
			{
				dkFactor = 1;
			}
		}
		cout << "velX = " << velX << endl;
		cout << "velY = " << velY << endl;

		//if we start moving forward, we don't want to push directly
		if (velXTemp <= staticUpperBound && velXTemp >= staticMiddleBound && velYTemp <= staticUpperBound
				&& velYTemp >= staticMiddleBound && rotation <= 0.1 && rotation >= -0.1)
		{
		    //results in 0 arm wheel movement
			velX = 0;
		}
		else if (velXTemp <= staticMiddleBound && velXTemp >= staticLowerBound && velYTemp <= staticMiddleBound
				&& velYTemp >= staticLowerBound && rotation <= 0.1 && rotation >= -0.1)
		{
		    //results in minimum negative arm wheel movement
			velX = -10;
		}
	}

	double DribbleControlMOS::getBallVelocity(double velX, double velY)
	{
		return sqrt(velX * velX + velY * velY);
	}

//returns values [pi,-pi[
	double DribbleControlMOS::getBallAngle(double velX, double velY)
	{
		return atan2(velY, velX);
	}

	int DribbleControlMOS::sign(double x)
	{
		if (x == 0)
			return x;
		return x > 0 ? 1 : -1;
	}

	double DribbleControlMOS::getLeftArmVelocity(double ballVelocity, double ballAngle)
	{
		double sec0 = -M_PI;
		double sec1 = -M_PI / 2 - phi;
		double sec2 = -M_PI / 2;
		double sec3 = -M_PI / 2 + phi;
		double sec4 = 0;
		double sec5 = M_PI / 2 - phi;
		double sec6 = M_PI / 2;
		double sec7 = M_PI / 2 + phi;
		double sec8 = M_PI;

		double angleConst = 0;

//linear interpolation of the constants in the 8 sectors

		if (ballAngle <= sec1)
		{
			// pull
			cout << "sec0" << endl;
			angleConst = (ballAngle - sec1) * forwConst / (sec1 - sec0);
		}
		//wheel stops
		else if (ballAngle <= sec2)
		{
		    // push
			cout << "sec1" << endl;
			angleConst = (ballAngle - sec1) * sidewConst / (sec2 - sec1);
		}
		else if (ballAngle <= sec3)
		{

			cout << "sec2" << endl;
			angleConst = sidewConst + (ballAngle - sec2) * (diagConst - sidewConst) / (sec3 - sec2);
		}
		else if (ballAngle <= sec4)
		{
			cout << "sec3" << endl;
			angleConst = diagConst + (ballAngle - sec3) * (forwConst - diagConst) / (sec4 - sec3);
		}
		else if (ballAngle <= sec5)
		{
		    //push
			cout << "sec4" << endl;
			angleConst = forwConst + (ballAngle - sec4) * (-forwConst) / (sec5 - sec4);
		}
		// wheel stops
		else if (ballAngle <= sec6)
		{
		    //pull
			cout << "sec5" << endl;
			angleConst = (ballAngle - sec5) * (-sidewConst) / (sec6 - sec5);
		}
		else if (ballAngle <= sec7)
		{
			cout << "sec6" << endl;
			angleConst = -sidewConst + (ballAngle - sec6) * (sidewConst - diagConst) / (sec7 - sec6);
		}
		else if (ballAngle >= sec7)
		{
			// rotate left
			cout << "sec7" << endl;
			angleConst = -diagConst + (ballAngle - sec7) * (-forwConst + diagConst) / (sec8 - sec7);
		}

		cout << "angleConst left = " << angleConst << endl;
		return ballVelocity * angleConst * velToInput;
	}

	double DribbleControlMOS::getRightArmVelocity(double ballVelocity, double ballAngle)
	{
		double sec0 = -M_PI;
		double sec1 = -M_PI / 2 - phi;
		double sec2 = -M_PI / 2;
		double sec3 = -M_PI / 2 + phi;
		double sec4 = 0;
		double sec5 = M_PI / 2 - phi;
		double sec6 = M_PI / 2;
		double sec7 = M_PI / 2 + phi;
		double sec8 = M_PI;

		double angleConst = 0;

//linear interpolation of the constants in the 8 sectors

		if (ballAngle <= sec1)
		{
			// rotate right
			angleConst = -forwConst + (ballAngle - sec0) * (-diagConst + forwConst) / (sec1 - sec0);
		}
		else if (ballAngle <= sec2)
		{
			angleConst = -diagConst + (ballAngle - sec1) * (-sidewConst + diagConst) / (sec2 - sec1);
		}
		else if (ballAngle <= sec3)
		{
			angleConst = -sidewConst + (ballAngle - sec2) * (sidewConst) / (sec3 - sec2);
		}
		else if (ballAngle <= sec4)
		{
			angleConst = (ballAngle - sec3) * forwConst / (sec4 - sec3);
		}
		else if (ballAngle <= sec5)
		{
			angleConst = forwConst + (ballAngle - sec4) * (diagConst - forwConst) / (sec5 - sec4);
		}
		else if (ballAngle <= sec6)
		{
			angleConst = diagConst + (ballAngle - sec5) * (sidewConst - diagConst) / (sec6 - sec5);
		}
		else if (ballAngle <= sec7)
		{
			angleConst = sidewConst + (ballAngle - sec6) * (-sidewConst) / (sec7 - sec6);
		}
		else if (ballAngle >= sec7)
		{
			// rotate left
			angleConst = (ballAngle - sec7) * (-forwConst) / (sec8 - sec7);
		}

		cout << "angleConst right = " << angleConst << endl;
		return ballVelocity * angleConst * velToInput;
	}

/*PROTECTED REGION END*/
} /* namespace alica */
