#ifndef EMPLOYEE_MAPPER_H
#define EMPLOYEE_MAPPER_H

#include "DBConnection.h"
#include "Employee.h"
#include "vector"

class EmployeeMapper {
   public:
    EmployeeMapper(DBConnection* conn);
    ~EmployeeMapper();
    std::vector<Employee> getByName(std::string name);
    std::vector<Employee> getAll();
    bool save(Employee& employee);
    bool remove(Employee& employee);

   private:
    void saveId(PGresult* res, Employee& employee);
    DBConnection* conn;
    /* data */
};

#endif  // EMPLOYEE_MAPPER_H