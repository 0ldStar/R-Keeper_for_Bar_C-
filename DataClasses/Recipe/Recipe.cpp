#include "Recipe.h"

Recipe::Recipe(unsigned id, RecipeType type, std::vector<Ingredient> ingredients): id(id), type(type), ingredients(ingredients) {}

Recipe::~Recipe() {
}


void Recipe::print() {
    for (auto &i : ingredients) {
        i.print();
    }
    
}
