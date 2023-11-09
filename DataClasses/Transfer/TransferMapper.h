#ifndef TRANSFER_MAPPER_H
#define TRANSFER_MAPPER_H

#include "DBConnection.h"
#include "Transfer.h"
#include <vector>

class TransferMapper {
public:
    TransferMapper(DBConnection* conn);
    ~TransferMapper();
    std::vector<Transfer> getByEmployeeID(unsigned employeeId);
    std::vector<Transfer> getAll();
    bool save(Transfer& transfer);
    bool remove(Transfer& transfer);

private:
    DBConnection* conn;
};

#endif  // TRANSFER_MAPPER_H
