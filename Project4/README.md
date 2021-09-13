# Mapping My World
Create a 2D occupancy grid and 3D octomap from a simulated environment using with the `RTAB-Map` package.

## Contents
- Equip the robot with an RGB-D camera.
- Develop the package `gazebo_map` to interface with the `rtabmap_ros` package.
- Navigate the robot around the building.
- The acquired a map with a least 3 loop closured and a identifiable occupancy grid.

## Structure
```
.
├── pic
│   ├── map.PNG
│   └── rtabmap.PNG
├── README.md
└── src
    ├── gazebo_map
    │   ├── CMakeLists.txt
    │   ├── config
    │   │   ├── base_local_planner_params.yaml
    │   │   ├── costmap_common_params.yaml
    │   │   ├── global_costmap_params.yaml
    │   │   ├── local_costmap_params.yaml
    │   │   └── __MACOSX
    │   ├── include
    │   │   └── gazebo_map
    │   ├── launch
    │   │   ├── localization.launch
    │   │   ├── mapping.launch
    │   │   ├── robot_description.launch
    │   │   ├── teleop.launch
    │   │   └── world.launch
    │   ├── maps
    │   │   ├── mymap.pgm
    │   │   └── mymap.yaml
    │   ├── meshes
    │   │   └── hokuyo.dae
    │   ├── package.xml
    │   ├── src
    │   ├── urdf
    │   │   ├── my_robot.gazebo
    │   │   └── my_robot.xacro
    │   └── worlds
    │       └── myworld
    └── teleop_twist_keyboard
        ├── ...
```


## Build and Launch
Build
```bash
$ cd <PROJECT_PATH>/Project4
$ catkin_make
```

Launch Gazebo with robot
```
$ source devel/setup.bash
$ roslaunch gazebo_map world.launch
```

In a new terminal, launch `teleop_twist_keyboard` to robot nagivation by keyboard
```
$ roslaunch gazebo_map teleop.launch
```

Launch `RTAB-map` to perform mapping
```
$ roslaunch gazebo_map mapping.launch
```

After mapping, open the mapping database
```
$ rtabmap-databaseViewer ~/.ros/rtabmap.db
```
Save/Move this map database file.

