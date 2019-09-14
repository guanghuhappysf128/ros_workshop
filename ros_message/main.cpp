#include <ros/ros.h>
#include <signal.h>
#include "std_msgs/String.h"

  void mySigintHandler(int sig)
  {
      //triggered by rosnode kill /node_name
    // Do some custom action.
    // For example, publish a stop message to some other nodes.
    
    // All the default sigint handler does is call shutdown()
    ros::shutdown();
  }
  
  int main(int argc, char** argv)
  {
    ros::init(argc, argv, "my_node_name", ros::init_options::NoSigintHandler);
    ros::NodeHandle nh;
  
    // Override the default ros sigint handler.
    // This must be set after the first NodeHandle is created.
    signal(SIGINT, mySigintHandler);

    ros::Publisher pub = nh.advertise<std_msgs::String>("my_topic", 5);
    std_msgs::StringPtr str(new std_msgs::String);
    str->data = "hello world";

    // This works because you have to wait for the publisher to be built
    sleep(3);
    pub.publish(str);

  //  ros::Rate loop_rate(10);
  //  while(ros::ok())
  //  {
  //     pub.publish(str);
  //     //ros::spinOnce();
  //     loop_rate.sleep();
  //  }
  //ros::spinOnce();
    //...
    // If remove this, it will stopped directly.
    // It looks like it is waiting for something, not sure what it is.
    // In this application all user callbacks will be called from within the ros::spin() call. ros::spin() will not return until the node has been shutdown, either through a call to ros::shutdown() or a Ctrl-C.
    ros::spin();
    // it will not return until the node is been shutdown
    
    return 0;
  }