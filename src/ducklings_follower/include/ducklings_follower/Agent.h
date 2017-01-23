#ifndef __AGENT_CPP__
#define __AGENT_CPP__

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <geometry_msgs/Twist.h>


#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>




#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/common/projection_matrix.h>
#include <pcl/common/common.h>

#include <pcl/conversions.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/PCLPointCloud2.h>

#include <pcl/impl/point_types.hpp>

#include <vector>

using namespace std;
using namespace pcl;
using namespace ros;
using namespace cv;


class Agent {
    
    sensor_msgs::PointCloud2 tmpPointCloud2;

private:

    bool whatPointCloud(PointCloud <pcl::PointXYZ> & cloud);
    void buildViews(const PointCloud <pcl::PointXYZ> & cloud, Mat & frontalDepthView, Mat & topView, PointXYZ & delta);

    void detectTurtlebots(const Mat & topView, vector<Vec3f> & circles);

    bool walk(const vector<Vec3f> & circles,  PointXYZ & delta, geometry_msgs::Twist & twist);

    void showViews(const Mat & frontalDepthView, const Mat & topView, const vector<Vec3f> & circles ,  PointXYZ & delta);

public:
    Agent();
    void init();

    bool body(geometry_msgs::Twist & twist);

    void setDepthView(const sensor_msgs::PointCloud2 pointCloud2);
};


#endif
