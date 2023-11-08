#include "Supplier.h"

#include <iostream>

Supplier::Supplier(unsigned id, std::string name, std::string postAddress, std::string phoneNumber, std::string faxNumber, std::string email)
    : id(id), name(name), postAddress(postAddress), phoneNumber(phoneNumber), faxNumber(faxNumber), email(email) {}

Supplier::Supplier(std::string name, std::string postAddress, std::string phoneNumber, std::string faxNumber, std::string email)
    : id(0), name(name), postAddress(postAddress), phoneNumber(phoneNumber), faxNumber(faxNumber), email(email) {}

Supplier::~Supplier() {}

std::string* Supplier::getString() {
    std::string* stringArray = new std::string[6];
    stringArray[0] = std::to_string(id);
    stringArray[1] = name;
    stringArray[2] = postAddress;
    stringArray[3] = phoneNumber;
    stringArray[4] = faxNumber;
    stringArray[5] = email;
    return stringArray;
}

void Supplier::print() {
    std::cout << name << " " << postAddress << " " << phoneNumber << " " << faxNumber << " " << email << std::endl;
}

unsigned Supplier::getId() const {
    return id;
}

std::string Supplier::getName() const {
    return name;
}

std::string Supplier::getPostAddress() const {
    return postAddress;
}

std::string Supplier::getPhoneNumber() const {
    return phoneNumber;
}

std::string Supplier::getFaxNumber() const {
    return faxNumber;
}

std::string Supplier::getEmail() const {
    return email;
}

void Supplier::setPostAddress(const std::string& postAddress) {
    this->postAddress = postAddress;
}

void Supplier::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Supplier::setFaxNumber(const std::string& faxNumber) {
    this->faxNumber = faxNumber;
}

void Supplier::setEmail(const std::string& email) {
    this->email = email;
}