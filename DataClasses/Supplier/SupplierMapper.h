#ifndef SUPPLIER_MAPPER_H
#define SUPPLIER_MAPPER_H

#include "DBConnection.h"
#include "Supplier.h"
#include "BankDetailsMapper.h"
#include <vector>

class SupplierMapper {
public:
    SupplierMapper(DBConnection* conn);
    ~SupplierMapper();

    std::vector<Supplier> getByName(std::string name);
    std::vector<Supplier> getAll();
    bool save(Supplier& supplier);
    bool remove(Supplier& supplier);

private:
    DBConnection* conn;
};

#endif  // SUPPLIER_MAPPER_H
