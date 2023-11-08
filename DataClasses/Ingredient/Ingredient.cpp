#include "Ingredient.h"

Ingredient::Ingredient(unsigned id, unsigned productId, unsigned quantity, std::string unitOfMeasurement)
    : id(id), productId(productId), quantity(quantity), unitOfMeasurement(unitOfMeasurement) {}

Ingredient::Ingredient(unsigned productId, unsigned quantity, std::string unitOfMeasurement)
    : id(0), productId(productId), quantity(quantity), unitOfMeasurement(unitOfMeasurement) {}

Ingredient::~Ingredient() {}

std::string* Ingredient::getString() {
    std::string* stringArray = new std::string[4];
    stringArray[0] = std::to_string(id);
    stringArray[1] = std::to_string(productId);
    stringArray[2] = std::to_string(quantity);
    stringArray[3] = unitOfMeasurement;
    return stringArray;
}

void Ingredient::print() {
    std::cout << productId << " " << quantity << " " << unitOfMeasurement << std::endl;
}

unsigned Ingredient::getId() const {
    return id;
}

unsigned Ingredient::getProductId() const {
    return productId;
}

unsigned Ingredient::getQuantity() const {
    return quantity;
}

std::string Ingredient::getUnitOfMeasurement() const {
    return unitOfMeasurement;
}
