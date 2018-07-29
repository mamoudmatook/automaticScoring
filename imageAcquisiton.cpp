#include"imageAcquisiton.hpp"
int main(int argc,char **argv)
{  
cv::VideoCapture cap;
cap.open(0);
if( !cap.isOpened() ) { // check if we succeeded
std::cerr << "Couldn't open capture." << std::endl;
return -1;
}

namedWindow( "live", CV_WINDOW_AUTOSIZE );
cv::Mat frame;
while( 1 ) {
cap >> frame;
if( !frame.data ) break;
 // Ran out of film
Mat drawing = Mat::ones( frame.size(), CV_8UC3 );
 
circleDetection(&frame,&drawing);
holesDetection(&frame,&drawing);
//waitKey(0);
imshow("live",frame);

if( cv::waitKey(10) ==27 ) break;
}



}
