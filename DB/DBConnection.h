#ifndef DB_CONNECTION
#define DB_CONNECTION
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
#endif // DB_CONNECTION