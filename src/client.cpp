#include "ros/ros.h"
#include "gorev2/Service.h"
#include <cstdlib>
#include <string>

int main(int argc, char ** argv){
    ros::init(argc,argv,"client");

    if(argc != 3){
        ROS_INFO("there should be 2 parameters");
        return 1;
    }
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<gorev2::Service>("addStrings");

    gorev2::Service srv;
    std::string str1 = argv[1];
    std::string str2 = argv[2];
    srv.request.a.data = str1;
    srv.request.b.data = str2;
    if(client.call(srv)){
        std::cout << srv.response.c.data;
    }else{
        std::cout << "error";
    }

    return 0;
}