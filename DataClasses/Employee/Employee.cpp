#include "Employee.h"

Employee::Employee(unsigned id, std::string name, std::string address, std::string dateOfBirth, std::string position, unsigned salary) {
    this->id = id; // move to private and set Mapper as friend class
    this->name = name;
    this->address = address;
    this->dateOfBirth = dateOfBirth;
    this->position = position;
    this->salary = salary;
}
Employee::Employee(std::string name, std::string address, std::string dateOfBirth, std::string position, unsigned salary) {
    this->id = 0;
    this->name = name;
    this->address = address;
    this->dateOfBirth = dateOfBirth;
    this->position = position;
    this->salary = salary;
}
Employee::~Employee() {
}

std::vector<std::string> Employee::getString() {
    std::vector<std::string> stringArray;
    stringArray.push_back(std::to_string(id));
    stringArray.push_back(name);
    stringArray.push_back(address);
    stringArray.push_back(dateOfBirth);
    stringArray.push_back(position);
    stringArray.push_back(std::to_string(salary));
    return stringArray;
}

void Employee::print() {
    std::cout << "Name: "<<name << " Address: " << address << " Date of birth: "
              << " " << dateOfBirth << " Position: " << position << " Salary: " << salary << std::endl;
}

unsigned Employee::getId(){ return id;}