#ifndef SUPPLIER_MAPPER_H
#define SUPPLIER_MAPPER_H

#include <vector>

#include "BankDetailsMapper.h"
#include "DBConnection.h"
#include "Supplier.h"

class SupplierMapper {
   public:
    SupplierMapper(DBConnection* conn);
    ~SupplierMapper();

    std::vector<Supplier> getByName(std::string name);
    std::vector<Supplier> getAll();
    bool save(Supplier& supplier);
    bool remove(Supplier& supplier);

   private:
    void saveId(PGresult* res, Supplier& supplier);
    DBConnection* conn;
};

#endif  // SUPPLIER_MAPPER_H
