#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>
#include <ros/ros.h>
//#include <Connection.h>

using namespace std;
class Robot
{
    public:
        Robot(){}
        ~Robot(){}
	
	

        int ik();
        int dk();
        int init(int j1,int j2, int j3);

        
};

int dk(int j1, int j2, int j3){
    


     return 0;




}  
