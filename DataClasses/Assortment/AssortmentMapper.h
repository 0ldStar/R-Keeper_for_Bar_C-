#ifndef ASSORTMENT_MAPPER_H
#define ASSORTMENT_MAPPER_H

#include <vector>

#include "Assortment.h"
#include "DBConnection.h"
#include "SupplierMapper.h"

class AssortmentMapper {
   public:
    AssortmentMapper(DBConnection* conn);
    ~AssortmentMapper();

    std::vector<Assortment> getBySupplierName(std::string name);
    std::vector<Assortment> getAll();
    bool save(Assortment& assortment);
    bool remove(Assortment& assortment);

   private:
    void saveId(PGresult* res, Assortment& assortment);
        DBConnection* conn;
};

#endif  // ASSORTMENT_MAPPER_H
