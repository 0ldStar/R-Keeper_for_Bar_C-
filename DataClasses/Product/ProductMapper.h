#ifndef PRODUCT_MAPPER_H
#define PRODUCT_MAPPER_H

#include <vector>

#include "DBConnection.h"
#include "Product.h"

class ProductMapper {
   public:
    ProductMapper(DBConnection* conn);
    ~ProductMapper();

    std::vector<Product> getByAssortmentId(unsigned assortmentId);
    std::vector<Product> getAll();
    bool save(Product& product);
    bool remove(Product& product);

   private:
    void saveId(PGresult* res, Product& product);
    DBConnection* conn;
};

#endif  // PRODUCT_MAPPER_H
