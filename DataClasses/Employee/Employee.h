#ifndef EMPLOYEER_H
#define EMPLOYEER_H

#include <iostream>
#include <string>
#include <vector>

class Employee {
    friend class EmployeeMapper;

   public:
    Employee(unsigned id, std::string name, std::string address, std::string dateOfBirth, std::string position, unsigned salary);
    Employee(std::string name, std::string address, std::string dateOfBirth, std::string position, unsigned salary);
    ~Employee();

    std::vector<std::string> getString();
    void print();
    unsigned getId();

   private:
    unsigned id;
    std::string name;
    std::string address;
    std::string dateOfBirth;
    std::string position;
    unsigned salary;
};

#endif  // EMPLOYEER_H