#ifndef DEFAULT_TABELS
#define DEFAULT_TABELS
#include "DBConnection.h"

class DefaultTables {
   public:
    DefaultTables(DBConnection* dbConnnection);
    ~DefaultTables();

   private:
    DBConnection* dbConnection;
    
};
#endif // DEFAULT_TABELS