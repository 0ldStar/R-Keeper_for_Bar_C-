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

std::string* Transfer::getString() {
    std::string* stringArray = new std::string[6];
    stringArray[0] = std::to_string(id);
    stringArray[1] = std::to_string(employeeId);
    stringArray[2] = position;
    stringArray[3] = reason;
    stringArray[4] = std::to_string(numberOfOrder);
    stringArray[5] = dateOfOrder;
    return stringArray;
}

void Transfer::print() {
    std::cout << " Position: " << position << " Reason: " << reason << " Order Number: " << numberOfOrder << " Date of Order: " << dateOfOrder << std::endl;
}
