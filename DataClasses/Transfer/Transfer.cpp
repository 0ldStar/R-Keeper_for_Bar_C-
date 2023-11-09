#include "Transfer.h"

Transfer::Transfer(unsigned id, unsigned employeeId, std::string position, std::string reason, unsigned numberOfOrder, std::string dateOfOrder) {
    this->id = id;
    this->employeeId = employeeId;
    this->position = position;
    this->reason = reason;
    this->numberOfOrder = numberOfOrder;
    this->dateOfOrder = dateOfOrder;
}

Transfer::Transfer(unsigned employeeId, std::string position, std::string reason, unsigned numberOfOrder, std::string dateOfOrder) {
    this->id = 0;
    this->employeeId = employeeId;
    this->position = position;
    this->reason = reason;
    this->numberOfOrder = numberOfOrder;
    this->dateOfOrder = dateOfOrder;
}

Transfer::~Transfer() {
}

std::vector<std::string> Transfer::getString() {
    std::vector<std::string> stringArray;
    stringArray.push_back(std::to_string(id));
    stringArray.push_back(std::to_string(employeeId));
    stringArray.push_back(position);
    stringArray.push_back(reason);
    stringArray.push_back(std::to_string(numberOfOrder));
    stringArray.push_back(dateOfOrder);
    return stringArray;
}

void Transfer::print() {
    std::cout << " Position: " << position << " Reason: " << reason << " Order Number: " << numberOfOrder << " Date of Order: " << dateOfOrder << std::endl;
}
