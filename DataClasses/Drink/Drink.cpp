#include "Drink.h"

Drink::Drink(unsigned id, std::string name, unsigned portion_size, std::string capacity) {
    this->id = id;
    this->name = name;
    this->portion_size = portion_size;
    this->capacity = capacity;
}

Drink::Drink(std::string name, unsigned portion_size, std::string capacity) {
    this->id = 0;
    this->name = name;
    this->portion_size = portion_size;
    this->capacity = capacity;
}

Drink::~Drink() {
}

std::string* Drink::getString() {
    std::string* stringArray = new std::string[4];
    stringArray[0] = std::to_string(id);
    stringArray[1] = name;
    stringArray[2] = std::to_string(portion_size);
    stringArray[3] = capacity;
    return stringArray;
}

void Drink::print() {
    std::cout << "Name: " << name << " Portion Size: " << portion_size << " Capacity: " << capacity << std::endl;
}
