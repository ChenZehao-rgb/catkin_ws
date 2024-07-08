# ROS学习

1、C++回调函数，函数名作为指向回调函数的指针，调用时只需要函数名即可。

```
bool commandCallback(std_srvs::Trigger::Request&req, std_srvs::Trigger::Response&res)
```
