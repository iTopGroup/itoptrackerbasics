#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

class Utility
{
    private:
        std::vector<std::string> VIDEXT;
        std::vector<std::string> PICEXT;

    public:
        Utility();
        bool ispic(std::string path);
        bool isvideo(std::string path);
        std::string getext(std::string path);
};

#endif // UTILITY_H_INCLUDED
