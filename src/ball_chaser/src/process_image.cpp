#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

using namespace std;

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    ROS_INFO_STREAM("Driving the robot to the target.");
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

     if (!client.call(srv)) {
	    ROS_ERROR("Failed to call service DriveToTarget.");
	}
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image image)
{
    // Initialize white dots
   int white_colour = 255;
   bool ball = false;
   int columns = 0;
   int height = image.height;
   int step = image.step;


    for (int i=0; i < height * step; i += 3)
    {
        if ((image.data[i] == white_colour) && (image.data[i+1] == white_colour) && (image.data[i+2] == white_colour))
        {
            columns= i % step;

            if (columns < step / 3)
                drive_robot(0.5, 1);
            else if (columns< (step/3 * 2))
                drive_robot(0.5, 0);
            else
                drive_robot(0.5, -1);
            ball = true;
            break;
        }

    }
    if (ball == false){
    drive_robot(0,0);
    }
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/drive_bot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
