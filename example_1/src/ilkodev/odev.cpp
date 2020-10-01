#include <ros/ros.h>
#include <meturone_egitim/Dummy.h>
#include <iomanip>
#include <mesaj/Num.h>
int sonuc;
void mesajalindi(const meturone_egitim::Dummy &msg){

	int i=0,min=0,max=0;

		min =msg.arr[0];
		max=msg.arr[0];
	for(i=0; i<msg.n; i++){
	
		if (max<msg.arr[i])
			max=msg.arr[i];
		
		if(min>msg.arr[i])
			min=msg.arr[i];
	}
	sonuc=max-min;
	ROS_INFO_STREAM("arr[0]="<<msg.arr[0]);
	ROS_INFO_STREAM("sonuc "<<sonuc);
}		


int main(int argc, char** argv){

	ros::init(argc,argv,"birodev");
	ros::NodeHandle nh;

	ROS_INFO_STREAM("CALISIYOR MU ?");
	ROS_INFO_STREAM("CALISIYOR MU ?");
	ROS_INFO_STREAM("CALISIYOR MU ?");
	/*subscribe kurulumu */
	ros::Subscriber sub= nh.subscribe("dummy_topic", 1000, &mesajalindi);
	

	/*publisher kurulumu */
	ros::Publisher pub= nh.advertise<mesaj::Num>("answer", 1000);
	
	ros::Rate rate(2);
	mesaj::Num msg;
	while(ros::ok()){
		msg.num=sonuc;
		pub.publish(msg);

		ros::spinOnce();

	}


}
