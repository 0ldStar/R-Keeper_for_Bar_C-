#ifndef DEFAULT_TABELS_H
#define DEFAULT_TABELS_H
#include "DBConnection.h"

class DefaultTables {
   public:
    DefaultTables(DBConnection* dbConnnection);
    ~DefaultTables();

   private:
    DBConnection* dbConnection;
    
};
#endif // DEFAULT_TABELS_H