#ifndef DATABASEMANAGER_H_INCLUDED
#define DATABASEMANAGER_H_INCLUDED

#include "../plugin/sqlite3.h"
#include "../classes/subject.h"

class DataBaseManager
{
    private:
        bool state;
        sqlite3 *db;
        sqlite3_stmt *req;
        int code_error;
        std::string str_sql, db_path, error;

    public:
        DataBaseManager();
        DataBaseManager(std::string _db_path);
        int add_subject(Subject _subject); // return last insert row id when succeed
        int update_subject(int _id, Subject _subject_up_to_date);
        int delete_subject(int _id);
        std::string get_error();
};

#endif // DATABASEMANAGER_H_INCLUDED
