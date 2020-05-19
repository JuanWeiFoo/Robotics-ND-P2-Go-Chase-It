# Robotics-ND-P2-Go-Chase-It

## Introduction
This project is about making a robot chasing a white ball using chase white ball algorithm and camera sensors in gazebo.

## Body
There is two packages in the src file, which are **ball_chaser** and **my_robot**

### ball_chaser
ball_chaser has the drive_bot algorithm to recieve linear and angular commands as the process_image algorithm to chase the white ball.

### my_robot
this file launches gazebo, rviz and spawns the robot in the world.



## Setup and Launch Files
1.First, Install Gazebo and ROS in Linux.

To install ROS:
http://wiki.ros.org/melodic/Installation

To install Gazebo:
http://gazebosim.org/tutorials?tut=ros_installing&cat=connect_ros


2. Create a catkin workspace and initialize workspace  
```
 $ mkdir -p catkin_ws/src  `
 $ cd catkin_ws/src  `
 $ catkin_init_workspace`
```
3. Download git repository and make catkin package  
```
$ git clone https://github.com/JuanWeiFoo/Robotics-ND-P2-Go-Chase-It.git
$ cd ..
$ catkin_make
```
4. To launch gazebo with robot in it
```
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```
5.(a) To launch drive_bot algorithm (*open another terminal*)  
```
$ cd catkin_ws
$ source devel/setup.bash
$ rosrun ball_chaser drive_bot
```
5.(b) To launch process_image algorithm (*open another terminal*) 
```
$ cd catkin_ws
$ source devel/setup.bash
$ roslaunch ball_chaser ball_chaser.launch
```


