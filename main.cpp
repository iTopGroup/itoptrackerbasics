#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main( int argc, const char** argv )
{
    VideoCapture capture;
    Mat image, gray, frame, mini;
    image = imread("me.jpg");

    CascadeClassifier cascade;

    cascade.load("cascades/haarcascade_frontalface_default.xml");

    int id = 1;

    int counter = 0;

    capture.open(0);

    for(;;)
    {
        capture >> frame;

        cvtColor(frame, gray, COLOR_BGR2GRAY);

        vector<Rect> faces;

        cascade.detectMultiScale(gray, faces, 1.3, 5);

        if(frame.empty())
            break;

        Mat frame1 = frame.clone();

        for ( size_t i = 0; i < faces.size(); i++ )
        {
            double scale = 0.5;
            Scalar color = Scalar(255,0,255);
            Rect r = faces[i];
            rectangle( gray, Point(cvRound(r.x*scale), cvRound(r.y*scale)),
                       Point(cvRound((r.x + r.width-1)*scale), cvRound((r.y + r.height-1)*scale)),
                       color, 3, 8, 0);
            counter++;
            imwrite("dataset/im.jpg", gray);
            imshow("frame", gray);
        }
    }
}
