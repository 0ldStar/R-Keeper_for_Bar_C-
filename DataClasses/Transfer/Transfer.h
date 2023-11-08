#ifndef TRANSFER
#define TRANSFER

#include <iostream>
#include <string>

class Transfer {
    friend class TransferMapper;

public:
    Transfer(unsigned id, unsigned employeeId, std::string position, std::string reason, unsigned numberOfOrder, std::string dateOfOrder);
    Transfer(unsigned employeeId, std::string position, std::string reason, unsigned numberOfOrder, std::string dateOfOrder);
    ~Transfer();

    std::string* getString();
    void print();

private:
    unsigned id;
    unsigned employeeId;
    std::string position;
    std::string reason;
    unsigned numberOfOrder;
    std::string dateOfOrder;
};

#endif  // TRANSFER
