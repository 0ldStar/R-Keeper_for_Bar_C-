#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <iostream>
#include <string>

class Ingredient {
public:
    Ingredient(unsigned id, unsigned productId, unsigned quantity, std::string unitOfMeasurement);
    Ingredient(unsigned productId, unsigned quantity, std::string unitOfMeasurement);
    ~Ingredient();

    std::string* getString();
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
};

#endif  // INGREDIENT_H
