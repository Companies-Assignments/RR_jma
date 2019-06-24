#include <vector>
#include <iostream>
#include <sensor_msgs/JointState.h>
#include <ros/ros.h>
#include <sstream>
using namespace std;
class Connection
{
    public:
        Connection(ros::NodeHandle* nodehandle){}
        ~Connection(){}

        int open(int,char**);
        int close();


	//send data to the robot. use explicit pointer convertion

        int receive(std::vector<unsigned char> &data);
	//receive state of the robot. record to data. use explicit pointer convertion

        //void chatterCallback(const sensor_msgs::JointState& msg);
        ros::Subscriber minimal_subscriber_; //these will be set up within the class constructor, hiding these ugly details
	ros::Publisher minimal_publisher_;
 	double val_from_subscriber_; //example member variable: better than using globals; convenient way to pass data from a subscriber to other member functions
	double val_to_remember_;
	void initializeSubscribers(); // we will define some helper methods to encapsulate the gory details of initializing subscribers, publishers and services
    	void initializePublishers();
    	//void initializeServices();
	void subscriberCallback(const sensor_msgs::JointState& msg); //prototype for callback of example subscriber
	void send(std::vector<unsigned char> &data);
        
        private:
   
        ros::NodeHandle nh_; // we will need this, to pass between "main" and constru

//prototype for callback for example service

};

void Connection::initializePublishers(){
		ROS_INFO("Initializing Publishers");
		minimal_publisher_ = nh_.advertise<sensor_msgs::JointState>("/joint_states", 100); 
		cout << "minimal_publisher " << minimal_publisher_; 
	}

void Connection::send(std::vector<unsigned char> &data){
	    Connection::initializePublishers();
	    unsigned char* bytes = &(data[0]);
	    float * floatArray = reinterpret_cast<float*>(bytes);
	    float j1 = floatArray[0];
	    float j2 = floatArray[1];
	    float j3 = floatArray[2];
	    //ros::init(argc, argv, "talker");
	   
	    //ros::NodeHandle n;
	    //ros::Rate loop_rate(10);
	    sensor_msgs::JointState joint_state;
	    
	    joint_state.name.resize(4);
	    joint_state.position.resize(4);
	    joint_state.velocity.resize(4);
	    joint_state.effort.resize(4);
	    
	    
	   //joint1
	    joint_state.name[0]  = "RR_joint_1";
	    joint_state.position[0]  = j1;
	    joint_state.velocity[0]  = 0.1;
	    joint_state.effort[0]  = 0.1;
	    	
	    //joint2

	    joint_state.name[1]  = "RR_joint_2";
	    joint_state.position[1]  = j2;
	    joint_state.velocity[1]  = 0.1;
	    joint_state.effort[1]  = 0.1;

	    //joint3

	    joint_state.name[2]  = "RR_joint_3";
	    joint_state.position[2]  = j3;
	    joint_state.velocity[2]  = 0.1;
	    joint_state.effort[2]  = 0.1;

	    //tcp
	    joint_state.name[3]  = "RR_joint_tcp";
	    joint_state.position[3]  = 0.0;
	    joint_state.velocity[3]  = 0.0;
	    joint_state.effort[3]  = 0.0;

	    for (int i = 0; i < data.size(); i++) {
	       cout << "data[" << i << "] = " << (char)data[i] << "\n";
	    }
	    cout << "j1 = " << 0.5 << "\n";
	    cout << "j2 = " << j2 << "\n";
	    cout << "j3 = " << j3 << "\n";
	    
	 
	    //joint_state.header.stamp.sec= 500;
	    minimal_publisher_.publish(joint_state);
	    //ros::spinOnce();
	    //return 0;


	}



/*void subscriberCallback(const sensor_msgs::JointState& message_holder) {
    val_from_subscriber_ = message_holder.data; // copy the received data into member variable, so ALL member funcs of ExampleRosClass can access it
    ROS_INFO("myCallback activated: received value %f",val_from_subscriber_);
    sensor_msgs::JointState output_msg;
    val_to_remember_ += val_from_subscriber_; //can use a member variable to store values between calls; add incoming value each callback
    output_msg.data= val_to_remember_;
    // demo use of publisher--since publisher object is a member function
    minimal_publisher_.publish(output_msg); //output the square of the received value; 
}*/





void chatterCallback(const sensor_msgs::JointState& msg){
 	 //ROS_INFO("I heard: [%s]", msg->data.c_str());
	}

int receive(std::vector<unsigned char> &data){    
      //ros::NodeHandle n;
      //ros::Subscriber sub = n.subscribe("joint_states", 1000, chatterCallback);
      //ros::spin();
}

