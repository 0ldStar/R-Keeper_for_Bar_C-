#ifndef SNACK_MAPPER
#define SNACK_MAPPER

#include <vector>

#include "DBConnection.h"
#include "Snack.h"

class SnackMapper {
   public:
    SnackMapper(DBConnection* conn);
    ~SnackMapper();
    std::vector<Snack> getByName(std::string name);
    std::vector<Snack> getAll();
    bool save(Snack& snack);
    bool remove(Snack& snack);

   private:
    void saveId(PGresult* res, Snack& snack);
    DBConnection* conn;
};

#endif  // SNACK_MAPPER
