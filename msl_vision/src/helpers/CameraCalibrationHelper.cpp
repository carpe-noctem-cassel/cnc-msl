#include "CameraCalibrationHelper.h"

#include <SystemConfig.h>

#include <iostream>

using namespace CameraCalibration;

bool CameraCalibrationHelper::settingsAreRequested;
bool CameraCalibrationHelper::setSettings;
Settings* CameraCalibrationHelper::cameraSettings;

msl_sensor_msgs::CameraSettings* CameraCalibrationHelper::cameraSettingsMsgs;

ros::Publisher CameraCalibrationHelper::settingPub;
ros::Subscriber CameraCalibrationHelper::settingSub;
ros::Subscriber CameraCalibrationHelper::settingRequestSub;
ros::NodeHandle* CameraCalibrationHelper::visionNode;

void CameraCalibrationHelper::initialize() {
    int argc = 0;
    char **argv = NULL;
    ros::init(argc, argv, "CNCalibration");
    visionNode = new ros::NodeHandle();
    settingsAreRequested = false;
    setSettings = false;

    cameraSettings = new Settings();
    cameraSettingsMsgs = new msl_sensor_msgs::CameraSettings();
    cameraSettingsMsgs->senderID = supplementary::SystemConfig::getOwnRobotID();
    cameraSettingsMsgs->receiverID = -1;

    settingPub = visionNode->advertise<msl_sensor_msgs::CameraSettings>("CNCalibration/CameraSettings", 1);

    settingSub = visionNode->subscribe<msl_sensor_msgs::CameraSettings>("CNCalibration/CameraSettings", 1, &CameraCalibrationHelper::handleCameraSettings);

    settingRequestSub = visionNode->subscribe<msl_sensor_msgs::CameraSettingsRequest>("CNCalibration/CameraSettingsRequest", 1, &CameraCalibrationHelper::handleCameraSettingsRequest);
}

void CameraCalibrationHelper::sendSettings(Settings* settings) {
    std::cout << "CamCalib\tsendSettings" << std::endl;
    cameraSettingsMsgs->useBrightness = settings->useBrightness;
    cameraSettingsMsgs->brightness = settings->brightness;
    cameraSettingsMsgs->exposure = settings->exposure;
    cameraSettingsMsgs->autoWhiteBalance = settings->autoWhiteBalance;
    cameraSettingsMsgs->whiteBalance1 = settings->whiteBalance1;
    cameraSettingsMsgs->whiteBalance2 = settings->whiteBalance2;
    cameraSettingsMsgs->hue = settings->hue;
    cameraSettingsMsgs->saturation = settings->saturation;
    cameraSettingsMsgs->gamma = settings->gamma;
    cameraSettingsMsgs->autoShutter = settings->autoShutter;
    cameraSettingsMsgs->shutter = settings->shutter;
    cameraSettingsMsgs->autoGain = settings->autoGain;
    cameraSettingsMsgs->gain = settings->gain;
    settingPub.publish(*cameraSettingsMsgs);
}

void CameraCalibrationHelper::handleCameraSettings(const msl_sensor_msgs::CameraSettings::ConstPtr& msg) {
    if(supplementary::SystemConfig::getOwnRobotID() != msg->receiverID) return;
    std::cout << "CamCalib\thandleCameraSettings" << std::endl;
    cameraSettings->useBrightness = msg->useBrightness;
    cameraSettings->brightness = msg->brightness;
    cameraSettings->exposure = msg->exposure;
    cameraSettings->autoWhiteBalance = msg->autoWhiteBalance;
    cameraSettings->whiteBalance1 = msg->whiteBalance1;
    cameraSettings->whiteBalance2 = msg->whiteBalance2;
    cameraSettings->hue = msg->hue;
    cameraSettings->saturation = msg->saturation;
    cameraSettings->gamma = msg->gamma;
    cameraSettings->autoShutter = msg->autoShutter;
    cameraSettings->shutter = msg->shutter;
    cameraSettings->autoGain = msg->autoGain;
    cameraSettings->gain = msg->gain;

    setSettings = true;
}

void CameraCalibrationHelper::handleCameraSettingsRequest(const msl_sensor_msgs::CameraSettingsRequest::ConstPtr& msg) {
    for (int i = 0; i < msg->receiverID.size(); ++i) {
        if (msg->receiverID.at(i) == supplementary::SystemConfig::getOwnRobotID()) {
            std::cout << "CamCalib\thandleCameraSettingsRequest" << std::endl;
            settingsAreRequested = true;
            return;
        }
    }
}
