#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

class Frame
{
    private
        cv::Mat frame;

    public
        Frame(cv::Mat _frame);
        cv::Mat get() const;
};

#endif // FRAME_H_INCLUDED
