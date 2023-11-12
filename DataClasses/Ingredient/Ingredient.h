#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <iostream>
#include <string>

#include "Product.h"

class Ingredient {
    friend class IngredientMapper;

   public:
    Ingredient(Product product, unsigned productId, unsigned quantity, std::string unitOfMeasurement);
    Ingredient(Product product, unsigned id, unsigned productId, unsigned quantity, std::string unitOfMeasurement);
    ~Ingredient();

    std::vector<std::string> getString();
    void print();
    unsigned getId() const;
    unsigned getProductId() const;
    unsigned getQuantity() const;
    std::string getUnitOfMeasurement() const;

   private:
    unsigned id;
    unsigned productId;
    unsigned quantity;
    std::string unitOfMeasurement;
    Product product;
};

#endif  // INGREDIENT_H
