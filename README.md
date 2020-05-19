# Robotics-ND-P2-Go-Chase-It

## Introduction
This project is about making a robot chasing a white ball using chase white ball algorithm and camera sensors in gazebo.

## Body
There is two packages in the src file, which are **ball_chaser** and **my_robot**

### ball_chaser
ball_chaser has the drive_bot algorithm to recieve linear and angular commands as the process_image algorithm to chase the white ball.

### my_robot
this file launches gazebo, rviz and spawns the robot in the world.



## Setup 
First, Install Gazebo and ROS in Linux.

To install ROS:
http://wiki.ros.org/melodic/Installation

To install Gazebo:
http://gazebosim.org/tutorials?tut=ros_installing&cat=connect_ros

### Launch files 
1. Create a catkin workspace and initialize workspace  
```
 $ mkdir -o catkin_ws/src  `
 $ cd catkin_ws/src  `
 $ catkin_init_workspace`
```
2. Download git repository and make catkin package  
```
$ git clone https://github.com/JuanWeiFoo/Robotics-ND-P2-Go-Chase-It.git
$ catkin_make
```
