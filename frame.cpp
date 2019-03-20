#include "classes/frame.h"

using namespace cv;

Frame::Frame()
{
    path = "images/me.jpg";
    frame = imread(path);
}

Frame::Frame(cv::Mat _frame)
{
    frame = _frame;
}

Mat Frame::get_frame() const
{
    return frame;
}

void Frame::set_frame(Mat _frame)
{
    frame = _frame;
}

void Frame::toGrayScale()
{
    cvtColor( frame, frame, COLOR_BGR2GRAY );
}
