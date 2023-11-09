#include "Product.h"

Product::Product(unsigned id, std::string name) : id(id), name(name) {}

Product::Product(std::string name) : id(0), name(name) {}

Product::~Product() {}

std::vector<std::string> Product::getString() {
    std::vector<std::string> stringArray;
    stringArray.push_back(std::to_string(id));
    stringArray.push_back(name);
    return stringArray;
}

void Product::print() {
    std::cout << name << std::endl;
}

unsigned Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}
