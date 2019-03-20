#ifndef SUBJECT_H_INCLUDED
#define SUBJECT_H_INCLUDED

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

class Subject
{
    private:
        bool nameset, faceset, ageset;
        std::string first_name, last_name, faces_path, state;
        int age;
    public:
        Subject();
        Subject(std::string _faces_path);
        Subject(std::string _first_name, std::string _last_name, std::string _faces_path, int _age);
        std::string get_name() const;
        std::string get_first_name() const;
        std::string get_last_name() const;
        std::string get_faces_path() const;
        int get_age() const;
        void set_first_name(std::string _first_name);
        void set_last_name(std::string _last_name);
        void set_faces_path(std::string _path);
        void set_age(int _age);
        bool is_nameset() const;
        bool is_faceset() const;
        bool is_ageset() const;
};

#endif // SUBJECT_H_INCLUDED
