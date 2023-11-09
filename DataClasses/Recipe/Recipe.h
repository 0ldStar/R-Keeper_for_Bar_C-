#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <string>

class Recipe {
   public:
    friend class RecipeMapper;
    enum RecipeType {
        DRINK,
        SNACK
    };

    Recipe(unsigned id, int ingredient_id, RecipeType type);
    Recipe(int ingredient_id, RecipeType type);
    ~Recipe();

    std::string* getString();
    void print();

    RecipeType getType() const { return type; }

   private:
    unsigned id;
    int ingredient_id;
    RecipeType type;
};

#endif  // RECIPE_H
