#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv) 
{
    //ros节点初始化
    ros::init(argc, argv, "velocity_publisher");

    //创建节点句柄
    ros::NodeHandle n;

    //创建一个Publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist，队列长度为1000
    ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

    //设置循环的频率
    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        //初始化geometry_msgs::Twist类型的消息
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 0.5;
        vel_msg.angular.z = 0.5;

        //发布消息
        turtle_vel_pub.publish(vel_msg);

        //打印消息
        ROS_INFO("Publish turtle velocity command[%0.2f m/s, %0.2f rad/s]", vel_msg.linear.x, vel_msg.angular.z);

        //根据循环频率延时
        loop_rate.sleep();


    }
    
}