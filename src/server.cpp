#include "ros/ros.h"
#include "gorev2/Service.h"
#include <string>


bool addStrings(gorev2::Service::Request &req, gorev2::Service::Response &res){
   
    std::string result = "My name is "+req.a.data + ". I am " + req.b.data + "\n";
    std::cout << result;
    res.c.data = "My name is "+req.a.data + ". I am " + req.b.data +"\n";
    
    
    return true ;
}

int main(int argc, char ** argv){
    ros::init(argc,argv,"server");
    ROS_INFO("Ready to recieve from client");
    ros::NodeHandle n;

    ros::ServiceServer server = n.advertiseService("addStrings", addStrings);

    ros::spin();
    return 0;
}