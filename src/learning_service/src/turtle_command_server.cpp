#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Trigger.h>

ros::Publisher turtle_vel_pub;
bool pubCommand = false;

// service回调函数，当有客户端请求时被调用
bool commandCallback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res)
{
    pubCommand = !pubCommand;

    // 显示请求数据
    ROS_INFO("Publish turtle velocity command [%s]", pubCommand == true ? "Yes" : "No");

    // 设置反馈数据
    res.success = true;
    res.message = "Change turtle command state!";

    return true;
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "turtle_command_server");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个名为/turtle1/cmd_vel的Publisher，消息类型为geometry_msgs::Twist，队列长度为10
    turtle_vel_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);

    // 创建一个名为/turtle_command的ServiceServer，注册回调函数commandCallback
    ros::ServiceServer command_service = n.advertiseService("/turtle_command", commandCallback);

    // 循环等待回调函数
    ROS_INFO("Ready to receive turtle command.");

    //设置循环的频率
    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        //查看一次回调函数
        ros::spinOnce();

        //如果标志为真，则发布速度指令
        if (pubCommand)
        {
            geometry_msgs::Twist vel_msg;
            vel_msg.linear.x = 0.5;
            vel_msg.angular.z = 0.5;
            turtle_vel_pub.publish(vel_msg);
        }

        //按照循环频率延时
        loop_rate.sleep();
    }

    return 0;
}