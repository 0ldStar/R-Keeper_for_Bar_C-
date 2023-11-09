#ifndef PRODUCT_MAPPER_H
#define PRODUCT_MAPPER_H

#include "DBConnection.h"
#include "Product.h"
#include <vector>

class ProductMapper {
public:
    ProductMapper(DBConnection* conn);
    ~ProductMapper();

    std::vector<Product> getByAssortmentId(unsigned assortmentId);
    std::vector<Product> getAll();
    bool save(Product& product);
    bool remove(Product& product);

private:
    DBConnection* conn;
};

#endif  // PRODUCT_MAPPER_H
