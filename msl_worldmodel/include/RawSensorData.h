#pragma once

#include "InfoBuffer.h"
#include "InformationElement.h"

#include <msl_actuator_msgs/HaveBallInfo.h>
#include <msl_actuator_msgs/IMUData.h>
#include <msl_actuator_msgs/MotionBurst.h>
#include <msl_actuator_msgs/MotionControl.h>
#include <msl_actuator_msgs/RawOdometryInfo.h>
#include <msl_msgs/JoystickCommand.h>
#include <msl_msgs/MotionInfo.h>
#include <msl_sensor_msgs/BallHypothesisList.h>
#include <msl_sensor_msgs/BallInfo.h>
#include <msl_sensor_msgs/WorldModelData.h>
#include <std_msgs/Bool.h>

#include <cnc_geometry/CNPointAllo.h>
#include <cnc_geometry/CNPositionAllo.h>
#include <cnc_geometry/CNVecAllo.h>

#include <memory>
#include <vector>

namespace msl
{

class MSLWorldModel;

class RawSensorData
{

  public:
    RawSensorData(MSLWorldModel *wm, int ringBufferLength);
    virtual ~RawSensorData();

    // Data Integration Methods
    void processWorldModelData(msl_sensor_msgs::WorldModelDataPtr data);
    void processJoystickCommand(msl_msgs::JoystickCommandPtr msg);
    void processMotionBurst(msl_actuator_msgs::MotionBurstPtr msg);
    void processLightBarrier(std_msgs::BoolPtr msg);
    void processRawOdometryInfo(msl_actuator_msgs::RawOdometryInfoPtr msg);
    void processMotionControlMessage(msl_actuator_msgs::MotionControl &mc);
    void processCorrectedOdometryInfo(msl_sensor_msgs::CorrectedOdometryInfoPtr &coi);
    void processBallHypothesisList(msl_sensor_msgs::BallHypothesisListPtr &list);
    void processIMUData(msl_actuator_msgs::IMUDataPtr msg);

    // Data Access Methods
    const InfoBuffer<std::shared_ptr<std::vector<double>>> &getDistanceScanBuffer();
    const InfoBuffer<bool> &getLightBarrierBuffer();
    const InfoBuffer<geometry::CNVecEgo> &getOpticalFlowBuffer();
    const InfoBuffer<geometry::CNPositionAllo> &getOwnPositionMotionBuffer();
    const InfoBuffer<geometry::CNPositionAllo> &getOwnPositionVisionBuffer();
    const InfoBuffer<msl_msgs::MotionInfo> &getOwnVelocityMotionBuffer();
    const InfoBuffer<msl_msgs::MotionInfo> &getOwnVelocityVisionBuffer();
    const InfoBuffer<msl_actuator_msgs::MotionControl> &getLastMotionCommandBuffer();
    const InfoBuffer<int> &getCompassBuffer();
    const InfoBuffer<msl_sensor_msgs::CorrectedOdometryInfo> &getCorrectedOdometryBuffer();
    const InfoBuffer<msl_actuator_msgs::IMUData> &getImuDataBuffer();
    const InfoBuffer<msl_sensor_msgs::BallHypothesisList> &getBallHypothesisBuffer();
    const InfoBuffer<msl_msgs::JoystickCommand> &getJoystickCommandsBuffer();

  private:
    // buffers
    InfoBuffer<std::shared_ptr<const std::vector<double>>> distanceScan;
    InfoBuffer<bool> lightBarrier;
    InfoBuffer<geometry::CNVecEgo> opticalFlow;
    InfoBuffer<geometry::CNPositionAllo> ownPositionMotion;
    InfoBuffer<geometry::CNPositionAllo> ownPositionVision;
    InfoBuffer<msl_msgs::MotionInfo> ownVelocityMotion;
    InfoBuffer<msl_msgs::MotionInfo> ownVelocityVision;
    InfoBuffer<msl_actuator_msgs::MotionControl> lastMotionCommand;
    InfoBuffer<int> compass;
    InfoBuffer<msl_actuator_msgs::IMUData> imuData;
    InfoBuffer<msl_sensor_msgs::CorrectedOdometryInfo> correctedOdometry;
    InfoBuffer<msl_msgs::JoystickCommand> joystickCommands;
    InfoBuffer<msl_sensor_msgs::BallHypothesisList> ballHypothesis;

    MSLWorldModel *wm;

    // 1000000000[nsec] -> 1 [sec]
    // TODO: replace with ?DEFINES? or whatever for each info type
    const InfoTime maxValidity = 1000000000;
    int ownID;
};

} /* namespace msl */
