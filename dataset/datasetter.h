#ifndef DATASETTER_H_INCLUDED
#define DATASETTER_H_INCLUDED

#include "../classes/subject.h"
#include "../classes/frame.h"
#include "../classes/stream.h"
#include "../facedetector/facedetector.h"
#include "databasemanager.h"

class DataSetter
{
    private:
        bool state, datastreamset, subjectset;
        DataBaseManager db;
        DataStream datastream;
        Subject subject;
        std::string error;
    public:
        DataSetter();
        DataSetter(Subject _subject, DataStream _datastream);
        Subject get_subject() const;
        DataStream get_datastream() const;
        void set_subject(Subject _subject);
        void set_datastream(DataStream _datastream);
        bool save();
        std::string get_error() const;
};


#endif // DATASETTER_H_INCLUDED
