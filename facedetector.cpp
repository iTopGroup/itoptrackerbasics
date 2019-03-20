#include "facedetector/facedetector.h"

using namespace cv;
using namespace std;

FaceDetector::FaceDetector()
{
    state = "NULL";
    face_cascade_path = "classes/haarcascade_frontalface_default.xml";
    scale = 0.5;
    flip = false;
}

FaceDetector::FaceDetector(Camera _camera)
{
    camera = _camera;
    state = "CAMERA";
    face_cascade_path = "classes/haarcascade_frontalface_default.xml";
    scale = 0.5;
    flip = false;
}

FaceDetector::FaceDetector(DataStream _datastream)
{
    datastream = _datastream;
    state = "DATASTREAM";
    face_cascade_path = "classes/haarcascade_frontalface_default.xml";
    scale = 0.5;
    flip = false;
}

FaceDetector::FaceDetector(Camera _camera, string _face_cascade_path, double _scale, bool _flip)
{
    camera = _camera;
    face_cascade_path = _face_cascade_path;
    scale = _scale;
    flip = _flip;
    state = "CAMERA";
}

FaceDetector::FaceDetector(DataStream _datastream, string _face_cascade_path, double _scale, bool _flip)
{
    datastream = _datastream;
    face_cascade_path = _face_cascade_path;
    scale = _scale;
    flip = _flip;
    state = "DATASTREAM";
}

void FaceDetector::set_facecascade(string _path)
{
    face_cascade_path = _path;
}

void FaceDetector::set_flip(bool _flip)
{
    flip = _flip;
}

void FaceDetector::set_scale(double _scale)
{
    scale = _scale;
}

vector<Rect> FaceDetector::render()
{
    vector<Rect> output;

    if(state == "NULL")
    {
        cout << "No input found! Please submit an input data" << endl;
    }

    if(state == "CAMERA")
    {
        output = detectOnCamera();
    }

    if(state == "DATASTREAM")
    {
        output = detectOnDataStream();
    }

    return output;
}

vector<Rect> FaceDetector::detectOnCamera()
{
    vector<Rect> faces;
    capture = camera.get_capture();
    if(capture.isOpened())
    {
        cout << "Video capturing from camera #" << camera.num() <<" has been started ..." << endl;
        for(;;)
        {
            Mat frame;
            Mat mini;
            double fx = 1/scale;

            capture >> frame;
            if( frame.empty() )
                break;
            Frame input(frame);
            input.toGrayScale();

            resize( input.get_frame(), mini, Size(), fx, fx, INTER_LINEAR_EXACT );
            equalizeHist( mini, mini );
            if(!face_cascade.load(face_cascade_path)) cout << "Can't load face cascade parsed!" << endl;

            face_cascade.detectMultiScale( mini, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
        }

    }
    else
    {
        cout << "Can't open camera #" << camera.num() << endl;
    }

    return faces;
}

vector<Rect> FaceDetector::detectOnDataStream()
{
    vector<Rect> output;
    return output;
}
