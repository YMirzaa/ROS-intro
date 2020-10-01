#include <ros/ros.h>
#include <meturone_egitim/RandomArray.h>
#include <servis/gonder.h>
int cevap;

bool cevapgonder(servis::gonder::Request &req, servis::gonder::Response &res)
{

	res.numara = cevap;

	ROS_INFO_STREAM("CEVAP ========="<< res.numara);

	return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "odev2");
  ros::NodeHandle nh;

  int i=0,min=0,max=0;

  ros::Rate rate(1);
  ros::ServiceClient RandomArrayClient
	 = nh.serviceClient<meturone_egitim::RandomArray>("RandomArray");
	
  meturone_egitim::RandomArray::Request req;
  meturone_egitim::RandomArray::Response resp;

  ros::ServiceServer server = nh.advertiseService("gonder", &cevapgonder);
  while(ros::ok){
  
	  bool success= RandomArrayClient.call(req,resp);

  
  if(success){
  
		  ROS_INFO_STREAM("basarili ");
       		min=resp.arr[0];
  		max=resp.arr[0];

  for(i=0; i<resp.n; i++){
  	if(max<resp.arr[i]);
		max=resp.arr[i];

	if(min>resp.arr[i])
		min=resp.arr[i]; 
  
  }

  cevap=max-min;
  ROS_INFO_STREAM("SONUC "<< cevap);
  ros::spinOnce();
  rate.sleep();
  }
  
	 else{
  		ROS_ERROR_STREAM("FAILED TO DO");
  		}
	}
}
