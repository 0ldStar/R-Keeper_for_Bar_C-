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

std::vector<std::string> Drink::getString() {
    std::vector<std::string> stringArray;
    stringArray.push_back(std::to_string(id));
    stringArray.push_back(name);
    stringArray.push_back(std::to_string(portion_size));
    stringArray.push_back(capacity);
    return stringArray;
}

void Drink::print() {
    std::cout << "Name: " << name << " Portion Size: " << portion_size << " Capacity: " << capacity << std::endl;
}

unsigned Drink::getId() {
    return id;
}
