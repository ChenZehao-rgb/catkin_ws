#include <ros/ros.h>
#include <learning_service/person.h>

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "person_client");

    // 创建节点句柄
    ros::NodeHandle n;

    //发现 /spawn服务后，创建一个服务客户端，连接名为/spawn的service
    ros::service::waitForService("/show_person");
    ros::ServiceClient person_client = n.serviceClient<learning_service::person>("/show_person");

    //初始化learning_service::person类型的service消息
    learning_service::person srv;
    srv.request.name = "Tom";
    srv.request.age = 18;
    srv.request.sex = learning_service::person::Request::male;

    // 发现服务后，调用服务
    ROS_INFO("Call service to show person[name:%s, age:%d, sex:%d]", srv.request.name.c_str(), srv.request.age, srv.request.sex);
    person_client.call(srv);

    // 显示服务调用结果
    ROS_INFO("Show person result: %s", srv.response.result.c_str());

    return 0;
}