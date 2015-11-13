/*
 * Motion.h
 *
 *  Created on: Aug 19, 2015
 *      Author: Stephan Opfer
 */

#ifndef MSL_DRIVER_MOTION_H_
#define MSL_DRIVER_MOTION_H_

#define TMC_MOTION_DEBUG // for toggling debug output

#include <ros/ros.h>
#include <msl_actuator_msgs/RawOdometryInfo.h>
#include "msl_actuator_msgs/MotionControl.h"
#include "msl_actuator_msgs/MotionStatInfo.h"
#include "msl_msgs/MotionInfo.h"
#include "MotionData.h"
#include <chrono>
#include <cmath>
#include "AccelCompensation.h"
#include "CircleTrace.h"
#include <CNMC.h>
#include <mutex>

// serial port stuff
#include <termios.h>
#include <fcntl.h>

using namespace std;

namespace std
{
	class thread;
}

namespace msl_driver
{

	class Motion
	{
	public:
		Motion(int argc, char** argv);
		virtual ~Motion();

		void initCommunication(int argc, char** argv);
		void initialize();
		void open();
		void start();
		void handleMotionControl(msl_actuator_msgs::MotionControlPtr mc);bool isRunning();

		static void pmSigintHandler(int sig);
		static void pmSigTermHandler(int sig);

	protected:
		MotionSet* motionValue = nullptr;
		MotionSet* motionResult = nullptr;
		MotionSet* motionValueOld = nullptr;
		AccelCompensation* accelComp = nullptr;
		CircleTrace* traceModel = nullptr;
		CNMC* driver = nullptr;
		std::mutex motionValueMutex;

		double slipControlFactor = 1.0;
		double slipControlMinSpeed = 1250.0;
		double slipControlDiffAngle = ((M_PI / 180.0) * 10.0);
		double slipControlDiffAngleMinSpeed = 400.0;
		double slipControlOldMaxRot = (M_PI / 20.0);
		double slipControlNewMinRot = (M_PI / 2.0);
		double accelCompMaxAccel = 4000.0;
		double accelCompMaxAngularAccel = M_PI / 2.0;

		bool accelCompEnabled = false;bool slipControlEnabled = false;bool quit = false;

		int driverAlivePeriod = 250;
		int driverOpenAttemptPeriod = 1000;
		int ownId;
		int odometryDelay = 0;

//		void notifyDriverStatusChange(StatusCode code, string message);
//		void notifyDriverResultAvailable(DriverData data);

	private:
		// ROS STUFF
		ros::NodeHandle* rosNode;
		ros::AsyncSpinner* spinner;
		ros::Subscriber handleMotionControlSub;
		ros::Publisher rawOdometryInfoPub;
		ros::Publisher motionStatInfoPub;

		bool running;
		thread runThread;

		// SERIAL PORT STUFF
		struct termios newtio;
		int port = 0;
		string device = "";
		int initReadTimeout = 0; // Initial read timeout (required to read the garbage provided by the VMC after power on
		int readTimeout = 0; // General read timeout
		int readTimeoutCount = 0; // Global counter for read timeouts
		int writeTimeout = 0; // General write timeout
		int writeTimeoutCount = 0; // Global counter for write timeouts

		supplementary::SystemConfig* sc;
		MotorConfig mc;

		long minCycleTime; // Minimum cycle time (us)
		double radius;
		double maxVelocity;
		bool logOdometry;
		shared_ptr<vector<string>> logTypes;

		void run();
		void getMotorConfig();
		void sendMotorConfig();

		void sendData(shared_ptr<CNMCPacket> packet);
		CNMCPacket* readData();
		void checkSuccess(shared_ptr<CNMCPacket> cmd);
	};

} /* namespace msl_driver */

#endif /* MSL_DRIVER_MOTION_H_ */
