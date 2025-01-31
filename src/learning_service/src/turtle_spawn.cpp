#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char **argv)
{
    //初始化ROS节点
    ros::init(argc, argv, "turtle_spawn");

    //创建节点句柄
    ros::NodeHandle n;

    // 发现/spawn服务后，创建一个服务客户端，连接名为/spawn的service
    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = n.serviceClient<turtlesim::Spawn>("spawn");

    //初始化turtlesim::Spawn的请求数据
    turtlesim::Spawn srv;
    srv.request.x = 2;
    srv.request.y = 2;
    srv.request.theta = 0;
    srv.request.name = "turtle2";

    //请求服务调用
    ROS_INFO("Call service to spawn turtle[x:%0.6f, y:%0.6f, theta:%0.6f, name:%s]", srv.request.x, srv.request.y, srv.request.theta, srv.request.name.c_str());
    add_turtle.call(srv);

    //显示服务调用结果
    ROS_INFO("Spawn turtle successfully [name:%s]", srv.response.name.c_str());

    return 0;
}