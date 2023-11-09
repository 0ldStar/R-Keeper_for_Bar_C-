#ifndef DRINK_MAPPER_H
#define DRINK_MAPPER_H

#include <vector>

#include "DBConnection.h"
#include "Drink.h"

class DrinkMapper {
   public:
    DrinkMapper(DBConnection* conn);
    ~DrinkMapper();
    std::vector<Drink> getByName(std::string name);
    std::vector<Drink> getAll();
    bool save(Drink& drink);
    bool remove(Drink& drink);

   private:
    DBConnection* conn;
};

#endif  // DRINK_MAPPER_H
