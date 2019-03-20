#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

class Frame
{
    private:
        std::string path;
        cv::Mat frame;

    public:
        Frame();
        Frame(cv::Mat _frame);
        cv::Mat get_frame() const;
        void set_frame(cv::Mat _frame);
        void toGrayScale();
};



#endif // FRAME_H_INCLUDED
