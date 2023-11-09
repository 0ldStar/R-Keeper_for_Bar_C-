#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H
#include <libpq-fe.h>

#include <iostream>

class DBConnection {
   public:
    DBConnection();
    ~DBConnection();

    void printInfo();

    void executeCreateTables(char *query);

    PGconn *conn;
   private:
    void terminate(int code);
    void clearRes();
    
    PGresult *res;
    
};
#endif // DB_CONNECTION_H