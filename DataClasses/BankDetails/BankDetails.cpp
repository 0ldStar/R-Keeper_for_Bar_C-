#include "BankDetails.h"

BankDetails::BankDetails(unsigned id, unsigned supplierId, std::string name, std::string city, std::string TIN, std::string settlementAccount)
    : id(id), supplierId(supplierId), name(name), city(city), TIN(TIN), settlementAccount(settlementAccount) {}

BankDetails::BankDetails(unsigned supplierId, std::string name, std::string city, std::string TIN, std::string settlementAccount)
    : id(0), supplierId(supplierId), name(name), city(city), TIN(TIN), settlementAccount(settlementAccount) {}

BankDetails::~BankDetails() {}

std::vector<std::string> BankDetails::getString() {
    std::vector<std::string> stringArray;
    stringArray.push_back(std::to_string(id));
    stringArray.push_back(std::to_string(supplierId));
    stringArray.push_back(name);
    stringArray.push_back(city);
    stringArray.push_back(TIN);
    stringArray.push_back(settlementAccount);
    return stringArray;
}

void BankDetails::print() {
    std::cout << supplierId << " " << name << " " << city << " " << TIN << " " << settlementAccount << std::endl;
}

unsigned BankDetails::getId() const {
    return id;
}

unsigned BankDetails::getSupplierId() const {
    return supplierId;
}

std::string BankDetails::getName() const {
    return name;
}

std::string BankDetails::getCity() const {
    return city;
}

std::string BankDetails::getTIN() const {
    return TIN;
}

std::string BankDetails::getSettlementAccount() const {
    return settlementAccount;
}
