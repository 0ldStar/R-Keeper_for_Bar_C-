#ifndef SNACK_MAPPER
#define SNACK_MAPPER

#include "DBConnection.h"
#include "Snack.h"
#include <vector>

class SnackMapper {
public:
    SnackMapper(DBConnection* conn);
    ~SnackMapper();
    std::vector<Snack> getByName(std::string name);
    std::vector<Snack> getAll();
    bool save(Snack& snack);
    bool remove(Snack& snack);

private:
    DBConnection* conn;
};

#endif  // SNACK_MAPPER
