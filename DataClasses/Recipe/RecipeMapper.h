#ifndef RECIPE_MAPPER_H
#define RECIPE_MAPPER_H

#include <vector>

#include "DBConnection.h"
#include "Recipe.h"

class RecipeMapper {
   public:
    RecipeMapper(DBConnection* conn);
    ~RecipeMapper();

    std::vector<Recipe> getByType(Recipe::RecipeType type);
    std::vector<Recipe> getByPositionId(Recipe::RecipeType type, unsigned id);
    std::vector<Recipe> getAll();
    bool save(Recipe& recipe);
    bool remove(Recipe& recipe);

   private:
    DBConnection* conn;
};

#endif  // RECIPE_MAPPER_H
