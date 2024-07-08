#include <string>
#include <ros/ros.h>
#include <std_srvs/Empty.h>

int main(int argc, char **argv)
{
    int red, green, blue;

    // ros节点初始化
    ros::init(argc, argv, "parameter_config");

    // 创建节点句柄
    ros::NodeHandle nh;

    // 读取参数
    ros::param::get("/turtlesim/background_r", red);
    ros::param::get("/turtlesim/background_g", green);
    ros::param::get("/turtlesim/background_b", blue);

    ROS_INFO("background color: R=%d, G=%d, B=%d", red, green, blue);

    //设置参数
    ros::param::set("/turtlesim/background_r", 255);
    ros::param::set("/turtlesim/background_g", 255);
    ros::param::set("/turtlesim/background_b", 255);

    ROS_INFO("background color changed to: R=%d, G=%d, B=%d", 255, 255, 255);

    // 读取参数
    ros::param::get("/turtlesim/background_r", red);
    ros::param::get("/turtlesim/background_g", green);
    ros::param::get("/turtlesim/background_b", blue);

    ROS_INFO("Re-get background color: R=%d, G=%d, B=%d", red, green, blue);

    //调用服务
    ros::service::waitForService("/clear");
    ros::ServiceClient clear_background = nh.serviceClient<std_srvs::Empty>("/clear");

    std_srvs::Empty srv;
    clear_background.call(srv);

    sleep(1);

    return 0;
}