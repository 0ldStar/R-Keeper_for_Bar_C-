#ifndef INGREDIENT_MAPPER_H
#define INGREDIENT_MAPPER_H

#include <vector>

#include "DBConnection.h"
#include "Ingredient.h"
#include "ProductMapper.h"

class IngredientMapper {
   public:
    IngredientMapper(DBConnection* conn, ProductMapper* productMapper);
    ~IngredientMapper();

    std::vector<Ingredient> getByProductName(std::string name);
    std::vector<Ingredient> getAll();
    bool save(Ingredient& ingredient);
    bool remove(Ingredient& ingredient);

   private:
    void saveId(PGresult* res, Ingredient& ingredient);
    DBConnection* conn;
    ProductMapper* productMapper;
};

#endif  // INGREDIENT_MAPPER_H
