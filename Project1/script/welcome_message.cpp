#include <gazebo/gazebo.hh>

namespace gazebo
{
    // inherit gazebo worldplugin class
  class WorldPluginMyRobot : public WorldPlugin
  {
    public: WorldPluginMyRobot() : WorldPlugin()
            {
              printf("Welcome to my world!\n");
            }

    // the load function is mendatory to receive info from world file
    public: void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
            {
            }
  };

  // register the plugin with the simulation
  GZ_REGISTER_WORLD_PLUGIN(WorldPluginMyRobot)
}