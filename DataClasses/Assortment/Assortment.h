#ifndef ASSORTMENT_H
#define ASSORTMENT_H

#include <iostream>
#include <string>

class Assortment {
public:
    Assortment(unsigned id, unsigned supplierId, double wholesalePrice, std::string deliveryTerms, std::string paymentTerms);
    Assortment(unsigned supplierId, double wholesalePrice, std::string deliveryTerms, std::string paymentTerms);
    ~Assortment();

    std::string* getString();
    void print();
    unsigned getId() const;
    unsigned getSupplierId() const;
    double getWholesalePrice() const;
    std::string getDeliveryTerms() const;
    std::string getPaymentTerms() const;

private:
    unsigned id;
    unsigned supplierId;
    double wholesalePrice;
    std::string deliveryTerms;
    std::string paymentTerms;
};

#endif  // ASSORTMENT_H
