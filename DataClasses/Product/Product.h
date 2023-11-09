#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product {
    friend class ProductMapper;
public:
    Product(unsigned id, std::string name);
    Product(std::string name);
    ~Product();

    std::vector<std::string> getString();
    void print();
    unsigned getId() const;
    std::string getName() const;

private:
    unsigned id;
    std::string name;
};

#endif  // PRODUCT_H
