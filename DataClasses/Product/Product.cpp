#include "Product.h"

Product::Product(unsigned id, std::string name) : id(id), name(name) {}

Product::Product(std::string name) : id(0), name(name) {}

Product::~Product() {}

std::string* Product::getString() {
    std::string* stringArray = new std::string[2];
    stringArray[0] = std::to_string(id);
    stringArray[1] = name;
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
