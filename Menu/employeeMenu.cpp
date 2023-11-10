#include "barMenu.h"

void getAllEmployee(DBConnection &dbConnection) {
    EmployeeMapper emplMapper = EmployeeMapper(&dbConnection);
    std::vector<Employee> employeeVector = emplMapper.getAll();
    if (employeeVector.size() == 0) {
        std::cout << "No employee is stored in the database" << std::endl;
        return;
    }
    std::cout << std::endl;
    for (auto i : employeeVector) {
        i.print();
    }
}
void addNewEmployee(DBConnection &dbConnection) {
    EmployeeMapper emplMapper = EmployeeMapper(&dbConnection);
    std::string name, address, dateOfBirth, position;
    unsigned salary;

    std::cout << std::endl;
    std::cout << "Input name" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    std::cout << "Input address" << std::endl;
    std::getline(std::cin, address);
    std::cout << "Input date of birth (DD.MM.YYY)" << std::endl;
    std::cin >> dateOfBirth;
    std::cout << "Input position" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, position);
    std::cout << "Input salary" << std::endl;
    std::cin >> salary;
    Employee employee = Employee(name, address, dateOfBirth, position, salary);
    if (emplMapper.save(employee) != true) {
        std::cout << "Invalid input!" << std::endl;
    }
}

void deleteEmployee(DBConnection &dbConnection) {
    EmployeeMapper emplMapper = EmployeeMapper(&dbConnection);
    std::string name;
    size_t j = 0;
    char input;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Input name" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    std::cout << "Do you really want to fire " << name << "? (y/n)" << std::endl;
    std::cin >> input;
    if (input != 'y')
        return;
    std::vector<Employee> employeeVector = emplMapper.getByName(name);
    if (employeeVector.size() == 0) {
        std::cout << "Employee with name '" << name << "' not found" << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << "Select index for delete" << std::endl;
    for (auto i : employeeVector) {
        std::cout << j << ") ";
        i.print();
        j++;
    }
    std::cin >> j;
    if (j > employeeVector.size()) {
        std::cout << "Invalid input!" << std::endl;
        return;
    }

    emplMapper.remove(employeeVector[j]);
}
void moveEmployee(DBConnection &dbConnection) {
    EmployeeMapper emplMapper = EmployeeMapper(&dbConnection);
    TransferMapper transferMapper = TransferMapper(&dbConnection);
    std::string name;
    size_t j = 0;

    std::cout << std::endl;
    std::cout << "Input name" << std::endl;
    std::cin >> name;
    std::vector<Employee> employeeVector = emplMapper.getByName(name);
    if (employeeVector.size() == 0) {
        std::cout << "Employee with name '" << name << "' not found" << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << "Select index for move" << std::endl;
    for (auto i : employeeVector) {
        std::cout << j << ") ";
        i.print();
        j++;
    }
    std::cin >> j;
    if (j > employeeVector.size()) {
        std::cout << "Invalid input!" << std::endl;
        return;
    }
    std::string position, reason, dateOfOrder;
    unsigned numberOfOrder;
    std::cout << std::endl;
    std::cout << "Input position" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, position);
    std::cout << "Input reason" << std::endl;
    std::getline(std::cin, reason );
    std::cout << "Input number of order" << std::endl;
    std::cin >> numberOfOrder;
    std::cout << "Input date of order (DD.MM.YYY)" << std::endl;
    std::cin >> dateOfOrder;

    Transfer transfer = Transfer(employeeVector[j].getId(), position, reason, numberOfOrder, dateOfOrder);
    std::cout << "Transfer id " << transfer.getID() << std::endl;
    if (transferMapper.save(transfer) != true) {
        std::cout << "Invalid input!" << std::endl;
    }
    std::cout << "Transfer id " << transfer.getID() << std::endl;
}

void getEmployeeTransfers(DBConnection &dbConnection) {
    EmployeeMapper emplMapper = EmployeeMapper(&dbConnection);
    TransferMapper transferMapper = TransferMapper(&dbConnection);
    std::string name;
    size_t j = 0;

    std::cout << std::endl;
    std::cout << "Input name" << std::endl;
    std::cin >> name;
    std::vector<Employee> employeeVector = emplMapper.getByName(name);
    if (employeeVector.size() == 0) {
        std::cout << "Employee with name-" << name << " not found" << std::endl;
        return;
    }
    std::cout << "Select target Employee's index" << std::endl;
    for (auto i : employeeVector) {
        std::cout << j << ") ";
        i.print();
        j++;
    }
    std::cin >> j;
    if (j > employeeVector.size()) {
        std::cout << "Invalid input!" << std::endl;
        return;
    }
    std::vector<Transfer> transferVector = transferMapper.getByEmployeeID(employeeVector[j].getId());
    if (transferVector.size() == 0) {
        std::cout << "Employee with name-" << name << " has no transfers" << std::endl;
        return;
    }
    j = 0;

    std::cout << std::endl;
    for (auto i : transferVector) {
        std::cout << j << ") ";
        i.print();
        j++;
    }
}