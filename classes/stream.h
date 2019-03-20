#ifndef STREAM_H_INCLUDED
#define STREAM_H_INCLUDED

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

//Custom classes
#include "utility.h"
#include "camera.h"
#include "frame.h"

/**
 * This class construct datastream
 * for detection purpose
 */

class DataStream
{
    private:
        Utility utility;
        std::string state, video;
        cv::VideoCapture camera, file;
        std::vector<Camera> cameras;
        std::vector<std::string> files;
        cv::Mat view;
        std::vector<std::string> f_errors;
        std::vector<int> c_errors;

    public:
        DataStream();
        DataStream(std::vector<Camera> _cameras);
        DataStream(std::string _path, bool _many);
        bool readpic(std::string _path);
        bool readvideo(std::string _path);
        void readfile(std::string _path);
        bool f_error() const;
        bool c_error() const;
        std::string get_state();
};

#endif // STREAM_H_INCLUDED
