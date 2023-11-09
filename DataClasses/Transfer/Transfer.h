#ifndef TRANSFER_H
#define TRANSFER_H

#include <iostream>
#include <string>

class Transfer {
    friend class TransferMapper;

public:
    Transfer(unsigned id, unsigned employeeId, std::string position, std::string reason, unsigned numberOfOrder, std::string dateOfOrder);
    Transfer(unsigned employeeId, std::string position, std::string reason, unsigned numberOfOrder, std::string dateOfOrder);
    ~Transfer();

    std::vector<std::string> getString();
    void print();

private:
    unsigned id;
    unsigned employeeId;
    std::string position;
    std::string reason;
    unsigned numberOfOrder;
    std::string dateOfOrder;
};

#endif  // TRANSFER_H
