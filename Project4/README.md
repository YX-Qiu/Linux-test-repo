roslaunch gazebo_map world.launch
roslaunch gazebo_map teleop.launch
roslaunch gazebo_map mapping.launch



source devel/setup.bash

rtabmap-databaseViewer ~/Desktop/Workspace/project4/rtabmap.db


