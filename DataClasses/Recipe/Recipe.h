#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <string>
#include <vector>

#include "Ingredient.h"

class Recipe {
    friend class RecipeMapper;

   public:
    enum RecipeType {
        DRINK,
        SNACK
    };

    Recipe(unsigned id, RecipeType type, std::vector<Ingredient> ingredients);
    ~Recipe();

    std::vector<std::string> getString();
    void print();

    RecipeType getType() const { return type; }

   private:
    unsigned id;
    RecipeType type;
    std::vector<Ingredient> ingredients;
};

#endif  // RECIPE_H
