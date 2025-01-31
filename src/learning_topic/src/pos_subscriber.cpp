#include <ros/ros.h>
#include <turtlesim/Pose.h>

// 回调函数，当接收到/turtle1/pose消息后，会进入消息回调函数
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
    // 将接收到的消息打印出来
    ROS_INFO("Turtle pose: x:%0.6f, y:%0.6f", msg->x, msg->y);
}

int main(int argc, char** argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "pose_subscriber");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Subscriber，订阅名为/turtle1/pose的topic，注册回调函数poseCallback
    ros::Subscriber turtle_pose_sub = n.subscribe("/turtle1/pose", 1000, poseCallback);

    // 循环等待回调函数
    ros::spin();

    return 0;
}