#include <ros/ros.h>
#include <learning_topic/person.h>

int main(int argc, char **argv)
{
    //ros节点初始化
    ros::init(argc, argv, "person_publisher");

    //创建节点句柄
    ros::NodeHandle n;

    //创建一个Publisher，发布名为/person_info的topic，消息类型为learning_topic::Person，队列长度为10
    ros::Publisher person_info_pub = n.advertise<learning_topic::person>("/person_info", 10);

    //设置循环的频率
    ros::Rate loop_rate(1);

    while (ros::ok())
    {
        //初始化learning_topic::Person类型的消息
        learning_topic::person person_msg;
        person_msg.name = "Tom";
        person_msg.age = 18;
        person_msg.sex = learning_topic::person::male;

        //发布消息
        person_info_pub.publish(person_msg);

        //打印消息
        ROS_INFO("Publish Person Info: name:%s  age:%d  sex:%d", person_msg.name.c_str(), person_msg.age, person_msg.sex);

        //根据循环频率延时
        loop_rate.sleep();
    }

}