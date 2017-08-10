using namespace std;
#include "Plans/Behaviours/Joystick.h"

/*PROTECTED REGION ID(inccpp1421854975890) ENABLED START*/ //Add additional includes here
#include <msl_actuator_msgs/KickControl.h>
#include <msl_actuator_msgs/BallHandleCmd.h>
#include <msl_actuator_msgs/MotionControl.h>
#include <msl_actuator_msgs/KickControl.h>
#include <msl_actuator_msgs/ShovelSelectCmd.h>
#include "MSLWorldModel.h"
#include <RawSensorData.h>
/*PROTECTED REGION END*/
namespace alica
{
	/*PROTECTED REGION ID(staticVars1421854975890) ENABLED START*/ //initialise static variables here
	/*PROTECTED REGION END*/
	Joystick::Joystick() :
			DomainBehaviour("Joystick")
	{
		/*PROTECTED REGION ID(con1421854975890) ENABLED START*/ //Add additional options here
		/*PROTECTED REGION END*/
	}
	Joystick::~Joystick()
	{
		/*PROTECTED REGION ID(dcon1421854975890) ENABLED START*/ //Add additional options here
		/*PROTECTED REGION END*/
	}
	void Joystick::run(void* msg)
	{
		/*PROTECTED REGION ID(run1421854975890) ENABLED START*/ //Add additional options here
		cout << "=========================" << endl;
		auto joy = wm->rawSensorData->getJoystickCommand();
		msl_actuator_msgs::MotionControl mc;

		if (!joy)
		{
			// for smooth driving
			//if (this->smoothDrivingState)
			//{
			msl_actuator_msgs::MotionControl mc;
			pastControlInput.push(std::valarray<double>(init,3));
			pastControlInput.push(std::valarray<double>(init,3));
			pastControlInput.push(std::valarray<double>(init,3));
			pastTranslations.push(std::valarray<double>(init,3));
			pastTranslations.push(std::valarray<double>(init,3));
			pastTranslations.push(std::valarray<double>(init,3));
			pastControlInput.pop();
			pastControlInput.pop();
			pastControlInput.pop();
			pastTranslations.pop();
			pastTranslations.pop();
			pastTranslations.pop();
			send(mc);

			cout << "Joystick: x = " << mc.motion.translation << endl;

			//} else
			//{
			//	mc.motion = joy->motion;
			//}

			send(mc);
			return;
		}

//		if (lastProcessedCmd == joy) // only process new commands from WM
//		{
//			msl_actuator_msgs::MotionControl mc;
//			send(mc);
//			return;
//		}
		//cout << "Joystick-Beh: " << *joy << endl;
		if (!std::isnan(joy->motion.translation) && !std::isnan(joy->motion.rotation) && !std::isnan(joy->motion.angle))
		{

			// smooth driving stuff
//			if (this->smoothDrivingState)
//			{
			double input[] = {cos(joy->motion.angle)*joy->motion.translation, sin(joy->motion.angle)*joy->motion.translation, joy->motion.rotation};
			pastControlInput.push(std::valarray<double>(input,3));


			std::valarray<double> translation = ptController();
			mc.motion.translation = sqrt(pow(translation[0],2.0) + pow(translation[1],2.0));
			mc.motion.angle = atan2(translation[1],translation[0]);
			mc.motion.rotation = translation[2];

			cout << "Joystick: x = " << mc.motion.translation << endl;
//			} else
//			{
//				mc.motion = joy->motion;
//			}

			// acceleration memory
			// saving translation of the last 3 iterations



			mc.motion.angle = joy->motion.angle;
			send(mc);
		}
		else
		{
			msl_actuator_msgs::MotionControl mc;
			pastControlInput.push(std::valarray<double>(init,3));
			pastControlInput.push(std::valarray<double>(init,3));
			pastControlInput.push(std::valarray<double>(init,3));
			pastTranslations.push(std::valarray<double>(init,3));
			pastTranslations.push(std::valarray<double>(init,3));
			pastTranslations.push(std::valarray<double>(init,3));
			pastControlInput.pop();
			pastControlInput.pop();
			pastControlInput.pop();
			pastTranslations.pop();
			pastTranslations.pop();
			pastTranslations.pop();
			send(mc);
			//cout << "Joystick: Some Motion Value is NaN!" << endl;
		}

		if (joy->ballHandleState == msl_msgs::JoystickCommand::BALL_HANDLE_ON)
		{
			//cout << "Joy Ball handle on" << endl;
			msl_actuator_msgs::BallHandleCmd bhc;
			bhc.leftMotor = joy->ballHandleLeftMotor;
			bhc.rightMotor = joy->ballHandleRightMotor;
			send(bhc);
		}

		msl_actuator_msgs::ShovelSelectCmd ssc;

		if (joy->shovelIdx == 0)
		{
			ssc.passing = true;
		}
		else
		{
			ssc.passing = false;
		}
		send(ssc);

		if (joy->kick == true)
		{
			msl_actuator_msgs::KickControl kc;
			kc.power = joy->kickPower;
			kc.extension = joy->shovelIdx;
			kc.extTime = 1;
			kc.forceVoltage = false;
			send(kc);
		}

		lastProcessedCmd = joy;
		/*PROTECTED REGION END*/
	}
	void Joystick::initialiseParameters()
	{
		/*PROTECTED REGION ID(initialiseParameters1421854975890) ENABLED START*/ //Add additional options here
		if (pastTranslations.empty())
		{
			pastTranslations.push(std::valarray<double>(init,3) );
			pastTranslations.push(std::valarray<double>(init,3) );
		}
		if (pastControlInput.empty())
		{
			pastControlInput.push(std::valarray<double>(init,3) );
			pastControlInput.push(std::valarray<double>(init,3) );
		}

		lastJump = 1000;

		/*PROTECTED REGION END*/
	}
	/*PROTECTED REGION ID(methods1421854975890) ENABLED START*/ //Add additional methods here
	std::valarray<double> Joystick::ptController()
	{
		int newJump = max(abs(pastControlInput.back()[0]-pastControlInput.front()[0]),abs(pastControlInput.back()[1]-pastControlInput.front()[1]));
		if (newJump != 0) {
			lastJump=newJump;
		}

		// slope variable
		double a = 6.33333 - 4.0/3000.0*lastJump;
		// changing point for slope
		double b = pow(a, 2.0);
		// sending frequency
		double TA = 1.0 / 30.0;

//		double n1 = pow(a, 2.0) / (1.0 / pow(TA, 2.0) + (2.0 / TA) + pow(a, 2.0));
//
//		double d1 = (-(2.0 / pow(TA, 2.0)) - ((2.0 * a) / TA)) / (1.0 / pow(TA, 2.0) + 2.0 / TA + pow(a, 2.0));
//		double d2 = (1.0 / pow(TA, 2.0)) / (1.0 / pow(TA, 2.0) + 2.0 / TA + pow(a, 2.0));

		double n1 = 1.0 - exp(-a * TA) - exp(-a * TA) * a * TA;
		double n2 = exp(-2 * a * TA) - exp(-a * TA) + exp(-a * TA) * TA * a;

		double d1 = -2 * exp(-a * TA);
		double d2 = exp(-2 * a * TA);

		cout << "n1 = " << n1 << endl;
 		cout << "n2 = " << n2 << endl;

		cout << "d1 = " << d1 << endl;
		cout << "d2 = " << d2 << endl;
//		cout << "d3 = " << d3 << endl;
//		cout << "d4 = " << d4 << endl;

//		return n1 * pastControlInput->at(0) - d1 * pastTranslations->at(0) - d2 * pastTranslations->at(1);
		pastTranslations.push(std::valarray<double>(init,3));
		pastTranslations.back() += n2*pastControlInput.front() - d2* pastTranslations.front();
		pastControlInput.pop();
		pastTranslations.pop();
		pastTranslations.back() += n1* pastControlInput.front() - d1* pastTranslations.front();

		return pastTranslations.back();
	}

/*PROTECTED REGION END*/
} /* namespace alica */
