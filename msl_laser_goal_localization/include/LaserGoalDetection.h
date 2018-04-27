#pragma once

#include <pcl/common/projection_matrix.h>
#include <pcl/point_types.h>
#include <ros/node_handle.h>
#include <ros/spinner.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Point.h>
#include <sensor_msgs/PointCloud.h>

namespace sensor_msgs
{
ROS_DECLARE_MESSAGE(LaserScan)
}

namespace msl
{
namespace goaldetection
{

class LaserGoalDetection
{
  public:
    LaserGoalDetection(int argc, char **argv);
    virtual ~LaserGoalDetection();

    void onScan(const sensor_msgs::LaserScanConstPtr &);

  private:
    ros::NodeHandle rosNode;
    ros::Subscriber subscriber;
    std::shared_ptr<ros::Publisher> debugPublisher;
    std::shared_ptr<ros::Publisher> lineCloudPublisher;
    std::shared_ptr<ros::Publisher> linesPublisher;
    std::shared_ptr<ros::Publisher> pointPublisher;
    std::shared_ptr<ros::Publisher> candPublisher;
    std::shared_ptr<ros::Publisher> goalMidResultPublisher;
    std::shared_ptr<ros::Publisher> goalMidPublisher;
    std::shared_ptr<ros::Publisher> goalMidPointPublisher;

    ros::AsyncSpinner spinner;

    std::vector<int> detectLinePoints(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);
    void deleteInliers(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud, std::vector<int> inliers);
};
}
} /* namespace msl */