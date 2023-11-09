#ifndef INGREDIENT_MAPPER_H
#define INGREDIENT_MAPPER_H

#include "DBConnection.h"
#include "Ingredient.h"
#include "ProductMapper.h"
#include <vector>

class IngredientMapper {
public:
    IngredientMapper(DBConnection* conn, ProductMapper* productMapper);
    ~IngredientMapper();

    std::vector<Ingredient> getByProductName(std::string name);
    std::vector<Ingredient> getAll();
    bool save(Ingredient& ingredient);
    bool remove(Ingredient& ingredient);

private:
    DBConnection* conn;
    ProductMapper* productMapper;
};

#endif  // INGREDIENT_MAPPER_H
