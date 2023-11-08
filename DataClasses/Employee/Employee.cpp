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

std::string* Employee::getString() {
    std::string* stringArray = new std::string[6];
    stringArray[0] = std::to_string(id);
    stringArray[1] = name;
    stringArray[2] = address;
    stringArray[3] = dateOfBirth;
    stringArray[4] = position;
    stringArray[5] = std::to_string(salary);
    return stringArray;
}

void Employee::print() {
    std::cout << "Name: "<<name << " Address: " << address << " Date of birth: "
              << " " << dateOfBirth << " Position: " << position << " Salary: " << salary << std::endl;
}

unsigned Employee::getId(){ return id;}