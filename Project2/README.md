# Project Description
## Build and Launch

## Structure
```
.Project2
├── README.md
└── src
    ├── ball_chaser
    │   ├── CMakeLists.txt
    │   ├── launch
    │   │   └── ball_chaser.launch
    │   ├── package.xml
    │   ├── src
    │   │   ├── drive_bot.cpp
    │   │   └── process_image.cpp
    │   └── srv
    │       └── DriveToTarget.srv
    └── my_robot
        ├── CMakeLists.txt
        ├── launch
        │   ├── robot_description.launch
        │   └── world.launch
        ├── meshes
        │   └── hokuyo.dae
        ├── package.xml
        ├── urdf
        │   ├── my_robot.gazebo
        │   └── my_robot.xacro
        └── worlds
            └── myworld

```

```
$ catkin_make
$ source devel/setup.bash
roslaunch my_robot world.launch
```

Open a new terminal,
```
$ source devel/setup.bash
$ roslaunch ball_chaser ball_chaser.launch
```

