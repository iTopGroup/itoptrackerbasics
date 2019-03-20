#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

class Camera
{
    private:
        cv::VideoCapture capture;
        int number;
        std::vector<int> previous, next;

    public:
        Camera();
        Camera(int _num);
        int num() const;
        void stream();
        cv::VideoCapture get_capture();
};

#endif // CAMERA_H_INCLUDED
