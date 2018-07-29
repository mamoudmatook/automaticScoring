#include"circleDetection.hpp"
void circleDetection(Mat *src,Mat *output)
{      cout<<"insid circle detection"<<endl;
	GaussianBlur(*src, *src, Size(3, 3), 0, 0, BORDER_DEFAULT);
        Mat gray;
        cvtColor(*src,gray,CV_BGR2GRAY);
        Mat kernel = Mat::ones(5,5,CV_8U);
        Mat morphological;
        morphologyEx(gray,morphological,MORPH_OPEN,kernel);
        //level of debugging
	//imshow("morphoutput",morphological);
	Mat binary;
        threshold(morphological,binary,80,255,CV_THRESH_BINARY_INV);
	//first level of debugging
	//imshow("binary_output",binary);
	//imwrite("binary.png", binary);
	Mat canny_output;
	Canny(binary,canny_output,80,200);
	//second level of debugging
	//imshow("canny_output",canny_output);
	//imwrite("canny_output.png", canny_output);
	vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
	double contour_area;
	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	vector<Point2f> centers;
       // Mat drawing2 = Mat::zeros( src.size(), CV_8UC3 );
	for (int i = 0; i < contours.size(); i++)
          {

	  Point2f center;
        float radius = 0;
        minEnclosingCircle(contours[i], center, radius);
	centers.push_back(center);
	cout<<"rad"<<i<<" "<<radius<<endl;
        cout<<center.x<<" " <<center.y<<endl;
	if(abs(center.x-304)<100 && abs(center.y-242)<100)
       circle( *output, center, radius, Scalar(0, 0, 0), 10, LINE_AA );

          }
        // imshow("circle",*output); 
	 //waitKey(40);
}
