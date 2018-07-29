#include"holesDetction.hpp"
void holesDetection(Mat *src,Mat *output)
{   
   Mat gray,binary;
   GaussianBlur(*src,*src, Size(3, 3), 0, 0, BORDER_DEFAULT);

  cvtColor( *src, gray, CV_BGR2GRAY );
 inRange(*src,Scalar(20,20,20),Scalar(80,80,80),binary);
 Mat kernel = Mat::ones(10, 10, CV_8U);
 Mat morphological,canny_output;
 morphologyEx(binary,morphological,MORPH_OPEN,kernel);
 vector<vector<Point> > contours;
 vector<Vec4i> hierarchy;

 findContours( morphological, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);



        int m=1;  
  for (int i=0;i<contours.size();i++)
  {       double area = contourArea(contours[i]);
       if (area<250)
	       continue;
        else{
        Point2f center;
        float radius = 0;
        minEnclosingCircle(contours[i], center, radius);
	cout<<"rad"<<m<<" "<<radius<<endl;
        cout<<center.x<<" " <<center.y<<endl; 
       circle( *src, center, radius, Scalar(0, 0, 255), 10, LINE_AA );
       Point org;
       org.x=center.x-10;
       org.y=center.y+10;
       putText( *src, to_string(m), org,FONT_HERSHEY_SIMPLEX, 0.8, Scalar(255, 255, 255),2);
       m++;
	}

    
  }
  //imshow("holes",*output);
  //waitKey(30);

}
