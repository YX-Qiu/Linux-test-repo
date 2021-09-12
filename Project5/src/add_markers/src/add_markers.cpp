#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

// Robot pose (estimated)
double pose_x;
double pose_y;
double pose_a;

// Pick up location
double goal1_x=4.3;
double goal1_y=-4.3;
double goal1_w=1.0;

// Drop off location
double goal2_x=5.9;
double goal2_y=-4.9;
double goal2_w=1.0;

double threshold = 0.35;

bool reached_goal1 = false;
bool left_goal1 = false;
bool reached_goal2 = false;

double dist2goal1 = 100;
double dist2goal2 = 100;

double marker_size = 0.3;

void position_det(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
     pose_x=msg->pose.pose.position.x;
     pose_y=msg->pose.pose.position.y;
     pose_a=msg->pose.pose.orientation.w;

     // ROS_INFO("x : %f, y: %f",pose_x,pose_y);

     dist2goal1 = sqrt(pow((pose_x - goal1_x),2) + pow((pose_y-goal1_y),2));
     dist2goal2 = sqrt(pow((pose_x - goal2_x),2) + pow((pose_y-goal2_y),2));
}



int main(int argc, char **argv)
{
    ros::init(argc,argv,"add_markers");
    ros::NodeHandle n;
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_maker",1);
    ros::Subscriber pos=n.subscribe("/amcl_pose",10,position_det);

    visualization_msgs::Marker marker;
    uint32_t shape = visualization_msgs::Marker::CUBE;

    marker.header.frame_id="/map";
    marker.header.stamp=ros::Time::now();

    marker.ns="Destination";
    marker.id=0;
    marker.type=shape;
    marker.action=visualization_msgs::Marker::ADD;

    marker.pose.position.x=goal1_x;
    marker.pose.position.y=goal1_y;
    marker.pose.position.z=0.0;
    marker.pose.orientation.x=0.0;
    marker.pose.orientation.y=0.0;
    marker.pose.orientation.z=0.0;
    marker.pose.orientation.w=1.0;

    marker.scale.x=marker_size;
    marker.scale.y=marker_size;
    marker.scale.z=0.1;

    marker.color.r=0.0f;
    marker.color.g=0.0f;
    marker.color.b=1.0f;
    marker.color.a=1.0;
    marker.lifetime=ros::Duration();
    ros::Duration(5.0).sleep();

    while(ros::ok())
    {
        while(marker_pub.getNumSubscribers()<1)
        {
            if(!ros::ok())
            {
                return 0;
            }
            ROS_WARN_ONCE("Please create a subscriber to the marker");
            sleep(1);
        }
        marker_pub.publish(marker);

        if( (dist2goal1 < threshold) && !reached_goal1)
        {
            reached_goal1 = true;
            ROS_INFO("reached pickup location");
            marker.action=visualization_msgs::Marker::DELETE;
            marker_pub.publish(marker);  
        }
        else if(reached_goal1 && (dist2goal1 >= threshold) && !reached_goal2 && !left_goal1)
        {
            left_goal1 = true;
            ROS_INFO("left pickup location");
            ros::Duration(1).sleep();
            // ROS_INFO("x : %f, y: %f, gap: %f",pose_x,pose_y,dist2goal2);
        }
        else if(reached_goal1 && (dist2goal2 < threshold))
        {
            reached_goal2 = true;
            ROS_INFO("reached drop off location");

            marker.action=visualization_msgs::Marker::ADD;
            marker.pose.position.x=goal2_x;
            marker.pose.position.y=goal2_y;
            marker_pub.publish(marker);

            ros::Duration(1).sleep();
            ros::spin();
        }
        
        ros::spinOnce();
    }
    
}