#include "Ingredient.h"

Ingredient::Ingredient(unsigned id, unsigned productId, unsigned quantity, std::string unitOfMeasurement)
    : id(id), productId(productId), quantity(quantity), unitOfMeasurement(unitOfMeasurement) {}

Ingredient::Ingredient(unsigned productId, unsigned quantity, std::string unitOfMeasurement)
    : id(0), productId(productId), quantity(quantity), unitOfMeasurement(unitOfMeasurement) {}

Ingredient::~Ingredient() {}

std::vector<std::string> Ingredient::getString() {
    std::vector<std::string> stringArray;
    stringArray.push_back(std::to_string(id));
    stringArray.push_back(std::to_string(productId));
    stringArray.push_back(std::to_string(quantity));
    stringArray.push_back(unitOfMeasurement);
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
