#include "Ingredient.h"

Ingredient::Ingredient(Product product, unsigned productId, unsigned quantity, std::string unitOfMeasurement)
    : id(0), productId(productId), quantity(quantity), unitOfMeasurement(unitOfMeasurement), product(product) {}

Ingredient::Ingredient(Product product, unsigned id, unsigned productId, unsigned quantity, std::string unitOfMeasurement)
    : id(id), productId(productId), quantity(quantity), unitOfMeasurement(unitOfMeasurement), product(product) {}

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
    std::cout << "Name: "<< product.getName() << " Quantity: " << quantity << " Unit of measurement: " << unitOfMeasurement << std::endl;
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
