#ifndef ASSORTMENT_MAPPER_H
#define ASSORTMENT_MAPPER_H

#include "DBConnection.h"
#include "Assortment.h"
#include "SupplierMapper.h"
#include <vector>

class AssortmentMapper {
public:
    AssortmentMapper(DBConnection* conn);
    ~AssortmentMapper();

    std::vector<Assortment> getBySupplierName(std::string name);
    std::vector<Assortment> getAll();
    bool save(Assortment& assortment);
    bool remove(Assortment& assortment);

private:
    DBConnection* conn;
};

#endif  // ASSORTMENT_MAPPER_H
