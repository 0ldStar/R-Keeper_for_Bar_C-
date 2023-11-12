#include "Snack.h"

Snack::Snack(unsigned id, std::string name, unsigned size_of_portions) {
    this->id = id;
    this->name = name;
    this->size_of_portions = size_of_portions;
}

Snack::Snack(std::string name, unsigned size_of_portions) {
    this->id = 0;
    this->name = name;
    this->size_of_portions = size_of_portions;
}

Snack::~Snack() {
}

std::vector<std::string> Snack::getString() {
    std::vector<std::string> stringArray;
    stringArray.push_back(std::to_string(id));
    stringArray.push_back(name);
    stringArray.push_back(std::to_string(size_of_portions));
    return stringArray;
}

void Snack::print() {
    std::cout << "Name: " << name << " Size of Portions: " << size_of_portions << std::endl;
}

unsigned Snack::getId() {
    return id;
}
