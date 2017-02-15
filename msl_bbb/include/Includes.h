//#pragma once
//
//#include <iostream>
//#include <signal.h>
//#include <sstream>
//#include <stdint.h>
//#include <sys/time.h>
//
//// Threads
//#include <condition_variable>
//#include <mutex>
//#include <thread>
//
//#include <SystemConfig.h>
//
//// BlackLibs
//#include "BlackADC.h"
//#include "BlackDef.h"
//#include "BlackGPIO.h"
//#include "BlackI2C.h"
//#include "BlackPWM.h"
//#include "BlackSPI.h"
//
//// BBB C++ API
//#include <BeagleGPIO.h>
//#include <BeaglePWM.h>
//#include <BeaglePins.h>
//
//// ROS
//#include "msl_actuator_msgs/BallHandleCmd.h"
//#include "msl_actuator_msgs/HaveBallInfo.h"
//#include "msl_actuator_msgs/IMUData.h"
//#include "msl_actuator_msgs/MotionBurst.h"
//#include "msl_actuator_msgs/MotionLight.h"
//#include "msl_actuator_msgs/ShovelSelectCmd.h"
//#include "msl_actuator_msgs/VisionRelocTrigger.h"
//#include "process_manager/ProcessCommand.h"
//#include "ros/ros.h"
//#include "std_msgs/Bool.h"
//#include "std_msgs/Empty.h"
//#include "std_msgs/String.h"
//
//#define TIMEDIFFUS(n, o) (((n).tv_usec - (o).tv_usec))
//
//#define IMU_UPDATE_TIMEOUT 10 // ms
//#define IMU_SEND_TIMEOUT 30   // ms
//
//#define OpticalFlow_UPDATE_TIMEOUT 1 // ms
//#define OpticalFlow_BURST_TIMEOUT 1  // ms
