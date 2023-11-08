#ifndef PRODUCT
#define PRODUCT

#include <iostream>
#include <string>

class Product {
    friend class ProductMapper;
public:
    Product(unsigned id, std::string name);
    Product(std::string name);
    ~Product();

    std::string* getString();
    void print();
    unsigned getId() const;
    std::string getName() const;

private:
    unsigned id;
    std::string name;
};

#endif  // PRODUCT
