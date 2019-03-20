#include "classes/stream.h"

using namespace std;
using namespace cv;

DataStream::DataStream()
{
    state = 'NULL';
}

DataStream::DataStream(vector<Camera> _cameras)
{
    if(_cameras.empty()) cout << "No camera found in datas given";
    else
    {
        vector<Camera>::iterator i;
        for(i=_cameras.begin(); i!=_cameras.end(); ++i)
        {
            Camera cam = *i;
            int const n = cam.num();
            if(camera.open(n)) cameras.push_back(*i);
            else
            {
                if(!c_errors.empty())
                {
                    c_errors.clear();
                    c_errors.push_back(n);
                }
                else
                    c_errors.push_back(n);
            }
        }
        state = (cameras.empty()) ? 'NULL' : 'CAMERAS';
    }
    if(!c_error()) cout << "All cameras loaded with success !" <<endl;
}

DataStream::DataStream(string _path, bool _many = false)
{
    if(!_many)
    {
        state = (readpic(_path)) ? 'VIEW' : ( (readvideo(_path)) ? 'VIDEO' : 'NULL');
    }
    else
    {
        readfile(_path);
        state = (files.empty()) ? 'NULL' : 'FILES';
        if(!f_error()) cout << "All files readen successfuly!" << endl;
    }
}

bool DataStream::readpic(string _path)
{
    if(utility.ispic(_path))
    {
        view = imread(_path, IMREAD_COLOR);
        if (view.empty())
        {
            cout << "Could not read image \"" << _path << "\"" << endl;
            return false;
        }
        else
        {
            cout << "Reading file : " << _path <<endl;
            return true;
        }
    }
    else if(utility.isvideo(_path))
    {
        cout << "Could not read video : \"" << _path << "\". Expecting image file!" << endl;
        return false;
    }
    else
        cout << "Could not read file \"" << _path << "\". Maybe extension is missing or not supported! " << endl;

    return false;
}

bool DataStream::readvideo(string _path)
{
    if(utility.ispic(_path))
    {
        cout << "Could not read image \"" << _path << "\". Expecting video file" << endl;
        return false;
    }
    else if(utility.isvideo(_path))
    {
        if(!file.open(_path))
        {
            cout << "Could not read video \"" << _path << "\"" << endl;
            return false;
        }
        else
        {
            video = _path;
            cout << "Reading video : " << _path << endl;
            return true;
        }
    }
    else
        cout << "Could not read file \"" << _path << "\". Maybe extension is missing or not supported!" << endl;

    return false;
}

void DataStream::readfile(string _path)
{
    FILE* f = fopen( _path.c_str(), "rt" );

        if( f )
        {
            char buf[1000+1];
            while( fgets( buf, 1000, f ) )
            {
                int len = (int)strlen(buf);
                while( len > 0 && isspace(buf[len-1]) )
                    len--;
                buf[len] = '\0';
                cout << "file " << buf << endl;

                if(readpic(buf) || readvideo(buf))
                {
                    files.push_back(buf);
                }
                else
                {
                    if(!f_errors.empty())
                    {
                        f_errors.clear();
                        f_errors.push_back(buf);
                    }
                    else
                        f_errors.push_back(buf);
                }
            }
            fclose(f);
        }
        else
            cout << "Can't reade file :\"" << _path <<"\""<< endl;
}

bool DataStream::f_error() const
{
    if(f_errors.empty()) return false;

    vector<string>::size_type i;
    for(i = 0; i < f_errors.size(); ++i)
    {
        cout << "Could not read file : " << f_errors[i] <<endl;
    }
    return true;
}

bool DataStream::c_error() const
{
    if(c_errors.empty()) return false;

    vector<int>::size_type i;
    for(i = 0; i < c_errors.size(); ++i)
    {
        cout << "Could not read stream from camera # " << c_errors[i] <<endl;
    }
    return true;
}

string DataStream::get_state()
{
    return state;
}
