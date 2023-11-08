#ifndef EMPLOYEE_MAPPER
#define EMPLOYEE_MAPPER

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
    DBConnection* conn;
    /* data */
};

#endif  // EMPLOYEE_MAPPER