#include "Assortment.h"
#include <iostream>

Assortment::Assortment(unsigned id, unsigned supplierId, double wholesalePrice, std::string deliveryTerms, std::string paymentTerms)
    : id(id), supplierId(supplierId), wholesalePrice(wholesalePrice), deliveryTerms(deliveryTerms), paymentTerms(paymentTerms) {}

Assortment::Assortment(unsigned supplierId, double wholesalePrice, std::string deliveryTerms, std::string paymentTerms)
    : id(0), supplierId(supplierId), wholesalePrice(wholesalePrice), deliveryTerms(deliveryTerms), paymentTerms(paymentTerms) {}

Assortment::~Assortment() {}

std::vector<std::string> Assortment::getString() {
    std::vector<std::string> stringArray;
    stringArray.push_back(std::to_string(id));
    stringArray.push_back(std::to_string(supplierId));
    stringArray.push_back(std::to_string(wholesalePrice));
    stringArray.push_back(deliveryTerms);
    stringArray.push_back(paymentTerms);
    return stringArray;
}

void Assortment::print() {
    std::cout << wholesalePrice << " " << deliveryTerms << " " << paymentTerms << std::endl;
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
