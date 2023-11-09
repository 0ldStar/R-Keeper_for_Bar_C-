#include "Supplier.h"

#include <iostream>

Supplier::Supplier(unsigned id, std::string name, std::string postAddress, std::string phoneNumber, std::string faxNumber, std::string email)
    : id(id), name(name), postAddress(postAddress), phoneNumber(phoneNumber), faxNumber(faxNumber), email(email) {}

Supplier::Supplier(std::string name, std::string postAddress, std::string phoneNumber, std::string faxNumber, std::string email)
    : id(0), name(name), postAddress(postAddress), phoneNumber(phoneNumber), faxNumber(faxNumber), email(email) {}

Supplier::~Supplier() {}

std::vector<std::string> Supplier::getString() {
    std::vector<std::string> stringArray;
    stringArray.push_back(std::to_string(id));
    stringArray.push_back(name);
    stringArray.push_back(postAddress);
    stringArray.push_back(phoneNumber);
    stringArray.push_back(faxNumber);
    stringArray.push_back(email);
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