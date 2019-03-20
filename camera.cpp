#include "classes/camera.h"

using namespace cv;

Camera::Camera()
{
    number = 0;
}

Camera::Camera(int _num)
{
    number = _num;
}

int Camera::num() const
{
    return number;
}

void Camera::stream()
{
    capture.open(number);
}

VideoCapture Camera::get_capture()
{
    stream();
    return capture;
}
