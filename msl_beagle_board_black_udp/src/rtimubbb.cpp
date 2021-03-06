

#include "RTIMULib.h"

RTIMUBBB::RTIMUBBB() {
	int sampleCount = 0;
	int sampleRate = 0;
	uint64_t rateTimer;
	uint64_t displayTimer;
	uint64_t now;

	//  Using RTIMULib here allows it to use the .ini file generated by RTIMULibDemo.
	//  Or, you can create the .ini in some other directory by using:
	//      RTIMUSettings *settings = new RTIMUSettings("<directory path>", "RTIMULib");
	//  where <directory path> is the path to where the .ini file is to be loaded/saved

	RTIMUSettings *settings = new RTIMUSettings("/home/cn/cnws/src/rt_imu_lib_test/src/", "RTIMULib");
	imu = new RTIMU::createIMU(settings);

	if ((imu == NULL) || (imu->IMUType() == RTIMU_TYPE_NULL)) {
		printf("No IMU found\n");
	}

	//  This is an opportunity to manually override any settings before the call IMUInit

	//  set up IMU

	imu->IMUInit();

	//  this is a convenient place to change fusion parameters

	imu->setSlerpPower(0.02);
	imu->setGyroEnable(true);
	imu->setAccelEnable(true);
	imu->setCompassEnable(true);

	oldData = imu->getIMUData();
}

RTIMUBBB::~RTIMUBBB() {

}

void RTIMUBBB::calculate() {
	RTIMU_DATA newData = imu->getIMUData();

	int vx = 0;
	int vy = 0;

	int xdiff = newData.fusionPose.x() - oldData.fusionPose.x();
	int ydiff = newData.fusionPose.y() - oldData.fusionPose.y();


}
