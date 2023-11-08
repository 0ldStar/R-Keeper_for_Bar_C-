#include "BankDetails.h"

BankDetails::BankDetails(unsigned id, unsigned supplierId, std::string name, std::string city, std::string TIN, std::string settlementAccount)
    : id(id), supplierId(supplierId), name(name), city(city), TIN(TIN), settlementAccount(settlementAccount) {}

BankDetails::BankDetails(unsigned supplierId, std::string name, std::string city, std::string TIN, std::string settlementAccount)
    : id(0), supplierId(supplierId), name(name), city(city), TIN(TIN), settlementAccount(settlementAccount) {}

BankDetails::~BankDetails() {}

std::string* BankDetails::getString() {
    std::string* stringArray = new std::string[6];
    stringArray[0] = std::to_string(id);
    stringArray[1] = std::to_string(supplierId);
    stringArray[2] = name;
    stringArray[3] = city;
    stringArray[4] = TIN;
    stringArray[5] = settlementAccount;
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
