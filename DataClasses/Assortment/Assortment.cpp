#include "Assortment.h"
#include <iostream>

Assortment::Assortment(unsigned id, unsigned supplierId, double wholesalePrice, std::string deliveryTerms, std::string paymentTerms)
    : id(id), supplierId(supplierId), wholesalePrice(wholesalePrice), deliveryTerms(deliveryTerms), paymentTerms(paymentTerms) {}

Assortment::Assortment(unsigned supplierId, double wholesalePrice, std::string deliveryTerms, std::string paymentTerms)
    : id(0), supplierId(supplierId), wholesalePrice(wholesalePrice), deliveryTerms(deliveryTerms), paymentTerms(paymentTerms) {}

Assortment::~Assortment() {}

std::string* Assortment::getString() {
    std::string* stringArray = new std::string[5];
    stringArray[0] = std::to_string(id);
    stringArray[1] = std::to_string(supplierId);
    stringArray[2] = std::to_string(wholesalePrice);
    stringArray[3] = deliveryTerms;
    stringArray[4] = paymentTerms;
    return stringArray;
}

void Assortment::print() {
    std::cout << id << " " << supplierId << " " << wholesalePrice << " " << deliveryTerms << " " << paymentTerms << std::endl;
}

unsigned Assortment::getId() const {
    return id;
}

unsigned Assortment::getSupplierId() const {
    return supplierId;
}

double Assortment::getWholesalePrice() const {
    return wholesalePrice;
}

std::string Assortment::getDeliveryTerms() const {
    return deliveryTerms;
}

std::string Assortment::getPaymentTerms() const {
    return paymentTerms;
}
