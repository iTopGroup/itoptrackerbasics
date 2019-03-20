#ifndef FACEDETECTOR_H_INCLUDED
#define FACEDETECTOR_H_INCLUDED

#include "../classes/camera.h"
#include "../classes/stream.h"
#include "../classes/frame.h"
#include "../classes/utility.h"

class FaceDetector
{
    private:
        std::string state;
        Camera camera;
        cv::VideoCapture capture;
        DataStream datastream;
        Frame response;
        std::string face_cascade_path;
        cv::CascadeClassifier face_cascade;
        double scale;
        bool flip;

    public:
        FaceDetector();
        FaceDetector(Camera _camera);
        FaceDetector(DataStream _datastream);
        FaceDetector(Camera _camera, std::string _face_cascade_path, double _scale, bool _flip);
        FaceDetector(DataStream _datastream, std::string _face_cascade_path, double _scale, bool _flip);
        void set_facecascade(std::string _path);
        void set_scale(double _scale);
        void set_flip(bool _flip);
        std::vector<cv::Rect> render();
        std::vector<cv::Rect> detectOnCamera();
        std::vector<cv::Rect> detectOnDataStream();
        std::vector<cv::Rect> detectFaces();
};

#endif // FACEDETECTOR_H_INCLUDED
