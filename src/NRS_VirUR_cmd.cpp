#include <stdio.h>
#include "ros/ros.h"
#include <iostream>
#include <csignal>

/* Header for command from Actaul */
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Float64MultiArray.h"

/* Header for command to RVIZ */
#include "sensor_msgs/JointState.h"

std::vector<double> Sub_Jangle;
double cmd_out[6] = {0,};
void UR10_Jangle_callback(const std_msgs::Float64MultiArray::ConstPtr& msg)
{
    Sub_Jangle = msg->data;
    for(int i=0;i<6;i++) {cmd_out[i] = Sub_Jangle[i];}
}

void signal_handler(int signum){exit(signum);}


int main(int argc, char* argv[])
{
    signal(SIGINT, signal_handler);

    ros::init(argc,argv,"NRS_VirUR_cmd");

    ros::NodeHandle nh;

    /* Publisher parameter setup */
    ros::Publisher SenMsg_pub = nh.advertise<sensor_msgs::JointState>("joint_states",10);

    sensor_msgs::JointState SenMsg_msg;

    /* Subscriber parameter setup */
    ros::Subscriber Jangle_sub = nh.subscribe("UR10_Jangle",10,UR10_Jangle_callback);

    /* Start flag */
    int Pub_start_flag = 0;

    std::cout << "Start the program??(Start:1,Quit:0): ";
    std::cin >> Pub_start_flag;

    if(Pub_start_flag == 0){signal_handler(1);}

    /* ROS Loop */
    ros::Rate loop_rate(10);

    while(ros::ok())
    {   
        // 필요한 필드 설정
        SenMsg_msg.header.stamp = ros::Time::now();

        SenMsg_msg.name = {"shoulder_pan_joint", "shoulder_lift_joint", "elbow_joint",
        "wrist_1_joint", "wrist_2_joint", "wrist_3_joint"};

        SenMsg_msg.position = {cmd_out[0],cmd_out[1],cmd_out[2],cmd_out[3],cmd_out[4],cmd_out[5]};

        /* Message publication */
        SenMsg_pub.publish(SenMsg_msg);

        SenMsg_msg.name.clear();
        SenMsg_msg.position.clear();

        ros::spinOnce();
        loop_rate.sleep();        
    }

    return 0;
}