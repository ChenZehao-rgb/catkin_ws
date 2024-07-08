#include <ros/ros.h>
#include <learning_service/person.h>

bool personCallback(learning_service::person::Request &req, learning_service::person::Response &res)
{
    // 显示请求数据
    ROS_INFO("person name:%s  age:%d  sex:%d", req.name.c_str(), req.age, req.sex);

    // 反馈结果
    res.result = "OK";

    return true;
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "person_server");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个名为/show_person的server，注册回调函数personCallback
    ros::ServiceServer person_service = n.advertiseService("/show_person", personCallback);
    ROS_INFO("Ready to show person information.");
    
    // 循环等待回调函数
    ros::spin();

    return 0;
}