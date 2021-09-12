# Ball Chasing Robot
A mobile robot that performs object detection and following tasks.

## Content
- Create the `my_robot` package
    - Model a mobile robot with the URDF (Unified Robot Description Format).
    - Equip the robot with a camera and a lidar sensor.
- Create the `ball_chaser` package
    - `drive_bot`: a server node that provides a robot motion command service and publishes robot kinematic data.
    - `process_image`: a clinent node that subscribes to robot's camera images and determine the position of white ball.
- Detecting and following
    - From the camera image, the robot determines whether a white ball is in the scene.
    - If a white ball is in the scene, drive towards it, otherwise stand by.

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

## Build and Launch
Build and source ROS packages:
```bash
$ catkin_make
$ source devel/setup.bash
```
Launch Gazebo world:
```bash
$ roslaunch my_robot world.launch
```
Open a new terminal and launch the ball chaser service:
```bash
$ source devel/setup.bash
$ roslaunch ball_chaser ball_chaser.launch
```

