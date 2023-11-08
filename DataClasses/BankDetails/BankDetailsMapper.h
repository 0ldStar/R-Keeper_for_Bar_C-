#ifndef BANKDETAILS_MAPPER_H
#define BANKDETAILS_MAPPER_H

#include "DBConnection.h"
#include "BankDetails.h"
#include <vector>

class BankDetailsMapper {
public:
    BankDetailsMapper(DBConnection* conn);
    ~BankDetailsMapper();

    std::vector<BankDetails> getBySupplierName(std::string name);
    std::vector<BankDetails> getAll();
    bool save(BankDetails& bankDetails);
    bool remove(BankDetails& bankDetails);

private:
    DBConnection* conn;
};

#endif  // BANKDETAILS_MAPPER_H
