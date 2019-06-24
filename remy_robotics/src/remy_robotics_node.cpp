//#include <input.in>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <Connection.h>
#include <Robot.h>
#include <ros/ros.h>
using namespace std;




//functions

vector<vector<float>>  open_in_file(string input_file){
    vector<vector<float> > matrix;

    int sum = 0;
    float x,y,z,t;
    ifstream inFile;
    
    inFile.open(input_file);
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    while (inFile >> x >> y >> z >> t) {
	vector<float> myvector = {x,y,z,t};
	cout << "x" << myvector[0];
	//cout << "y" << y;
	//cout << "z" << z;
	//cout << "t" << t;
	//cout << "t" << myvector[3];
	matrix.push_back(myvector);
    }
    
    inFile.close();

    return matrix;
}

//main


int main(int argc, char** argv) {
    
    Robot ro;
    //ExampleRosClass exampleRosClass(&nh);


   //initialize ros
    ros::init(argc, argv, "remy_robotics_node");
    ros::NodeHandle nh;
    //ros::AsyncSpinner spinner(1);

    Connection cn(&nh);
    //spinner.start();
   
    //initializePublishers();
    
    // string input_file = "/home/julia/ws_moveit/src/remy_robotics/include/input.in";
    // open_in_file(input_file);
    std::vector<float> joints{0.8, 0.2, 0.6};
    const unsigned char* bytes = reinterpret_cast<const unsigned char*>(&joints[0]);
    std::vector<unsigned char> data(bytes, bytes + sizeof(float) * joints.size());

    cn.send(data);

    //cn.open(argc, argv);
    //ro.init();
     
     //static const std::string PLANNING_GROUP = "manipulator";
     /*moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
     moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
     const robot_state::JointModelGroup* joint_model_group =
     move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);
     namespace rvt = rviz_visual_tools;
     moveit_visual_tools::MoveItVisualTools visual_tools("RR_base");
     visual_tools.deleteAllMarkers();
     visual_tools.loadRemoteControl();
     Eigen::Isometry3d text_pose = Eigen::Isometry3d::Identity();
     text_pose.translation().z() = 1.75;
     visual_tools.publishText(text_pose, "MoveGroupInterface Demo", rvt::WHITE, rvt::XLARGE);
     visual_tools.trigger();
     ROS_INFO_NAMED("tutorial", "Planning frame: %s", move_group.getPlanningFrame().c_str());

     // We can also print the name of the end-effector link for this group.
     ROS_INFO_NAMED("tutorial", "End effector link: %s", move_group.getEndEffectorLink().c_str());

     // We can get a list of all the groups in the robot:
     ROS_INFO_NAMED("tutorial", "Available Planning Groups:");
     std::copy(move_group.getJointModelGroupNames().begin(), move_group.getJointModelGroupNames().end(),
            std::ostream_iterator<std::string>(std::cout, ", "));

     // Start the demo
     // ^^^^^^^^^^^^^^^^^^^^^^^^^
     visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to start the demo");

     // Planning to a Pose goal
     // ^^^^^^^^^^^^^^^^^^^^^^^
     // We can plan a motion for this group to a desired pose for the
     // end-effector.
     geometry_msgs::Pose target_pose1;
     target_pose1.orientation.w = 1.0;
     target_pose1.position.x = 0.28;
     target_pose1.position.y = -0.2;
     target_pose1.position.z = 0.5;
     move_group.setPoseTarget(target_pose1); */
     //loop_rate.sleep();

    ros::spin();

    
    return 0;

}

//cin>>CC; cin>>RR; already done



