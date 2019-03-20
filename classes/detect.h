#ifndef DETECT_H_INCLUDED
#define DETECT_H_INCLUDED

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class Detection
{
    private:
        cv::Mat img;
        cv::CascadeClassifier cascade;
        cv::CascadeClassifier nestedCascade;
        double scale;
        bool tryflip;
        std::vector<cv::Rect> faces, faces2;
        cv::Scalar colors[8];
        bool state;

    public:
        Detection();
        Detection(cv::Mat& in, cv::CascadeClassifier& model, double scale);
        bool setNestedCascade();
        bool render();
        bool stop();
        void detectAndDraw( cv::Mat& img, cv::CascadeClassifier& cascade,
                    cv::CascadeClassifier& nestedCascade,
                    double scale, bool tryflip );
};

#endif // DETECT_H_INCLUDED
