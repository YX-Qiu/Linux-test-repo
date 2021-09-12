# Build Gazebo World
An introduction to modeling and simulation in Gazebo.

## Contents
- Model a single floor building using the Gazebo **Bulding Editor**. 
- Model a mobile robot using the Gazebo **Model Editor**.
- Import models into a Gazebo world.
- Write a plugin to display a welcome message when launching the Gazebo world.

## Structure
```
.Project1
├── CMakeLists.txt
├── model                       # Building and robot model files
│   ├── building
│   │   ├── model.config
│   │   └── model.sdf
│   └── mobile_robot
│       ├── model.config
│       └── model.sdf
├── pic
│   └── Gazebo_world.PNG
├── script                      # C++ plugin script
│   └── welcome_message.cpp   
└── world                       # Gazebo world file
    └── myworld
```
## Build and Launch
Build:
```bash
$ mkdir build
$ cd build/
$ cmkae ../
$ make
$ export GAZEBO_PLUGIN_PATH={GAZEBO_PLUGIN_PATH}:<project_dir>/build
```

Launch:
```bash
$ cd ../world/
$ gazebo myworld
```
