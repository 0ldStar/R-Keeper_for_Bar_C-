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

std::string* Snack::getString() {
    std::string* stringArray = new std::string[3];
    stringArray[0] = std::to_string(id);
    stringArray[1] = name;
    stringArray[2] = std::to_string(size_of_portions);
    return stringArray;
}

void Snack::print() {
    std::cout << "Name: " << name << " Size of Portions: " << size_of_portions << std::endl;
}
