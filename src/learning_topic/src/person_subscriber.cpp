#include <ros/ros.h>
#include <learning_topic/person.h>

// 回调函数，当接收到/person_info消息后，会进入消息回调函数
void personInfoCallback(const learning_topic::person::ConstPtr& msg)
{
    // 将接收到的消息打印出来
    ROS_INFO("Person Info: name:%s  age:%d  sex:%d", msg->name.c_str(), msg->age, msg->sex);
}

int main(int argc, char **argv)
{
    //ros节点初始化
    ros::init(argc, argv, "person_subscriber");

    //创建节点句柄
    ros::NodeHandle n;

    //创建一个Subscriber，订阅名为/person_info的topic，注册回调函数personInfoCallback
    ros::Subscriber person_info_sub = n.subscribe("/person_info", 10, personInfoCallback);

    // 循环等待回调函数
    ros::spin();

    return 0;
}