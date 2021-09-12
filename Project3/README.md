# Where Am I
Robot localization while nagivating around in a map.

## Contents
- Use the `pgm_map_creator` package to create the map (ground truth) of a building.
- Create the `gazebo_map` package to use configure and use the `AMCL` (Adaptive Monte Carlo Localization) for localization.

## Structure
```
.Project3
├── pic
│   └── localization screenshot.PNG
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
    │   │   ├── amcl.launch
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
    ├── pgm_map_creator
    │   ├── ...
    └── teleop_twist_keyboard
        ├── ...
```

## Build and Launch
Build
```bash
cd <WORKSPACE_PATH>/Project3/
catkin_make
```

Refer to [pgm_map_creator](https://github.com/hyfan1116/pgm_map_creator) for ground truth map generation. Copy the map to the `gazebo-map` package
```bash
cp src/pgm_map_creator/maps/<YOUR MAP NAME>  src/<YOUR PACKAGE NAME>/maps/<YOUR MAP NAME>
```

Lauch Gazebo
```bash
roslaunch my_robot world.launch
```

Launch AMCL
```bash
roslaunch my_robot amcl.launch
```

Run teleop-twist-keyboard to navigate the robot using keyboard
```bash
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

## Tips
AMCL parameters can be adjusted in `src/launch/amcl.launch`. (see [AMCL package](http://wiki.ros.org/amcl#Parameters) )
