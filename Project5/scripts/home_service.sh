#!/bin/sh

cd ..

xterm  -e  " source /opt/ros/kinetic/setup.bash; source devel/setup.bash" & 
sleep 2

xterm  -e  " source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/src/map/myworld" &
sleep 5

xterm  -e  " source devel/setup.bash && roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5

xterm  -e  " source devel/setup.bash && roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(pwd)/src/map/mymap.yaml " &
sleep 5


xterm -e " source devel/setup.bash && rosrun add_markers add_markers " &
sleep 7


xterm -e "source devel/setup.bash && rosrun pick_objects pick_objects"

