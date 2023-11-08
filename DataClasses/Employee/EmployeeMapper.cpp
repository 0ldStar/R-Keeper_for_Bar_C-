#include "EmployeeMapper.h"

EmployeeMapper::EmployeeMapper(DBConnection* conn) {
    this->conn = conn;
}

EmployeeMapper::~EmployeeMapper() {
}

void putPQResToList(PGresult* res, std::vector<Employee>& employeeList) {
    // int ncols = PQnfields(res);
    // for (int i = 1; i < ncols; i++) {
    //     char* name = PQfname(res, i);
    //     printf("%s ", name);
    // }
    // printf("\n");

    int nrows = PQntuples(res);
    for (int i = 0; i < nrows; i++) {
        char* id = PQgetvalue(res, i, 0);
        char* name = PQgetvalue(res, i, 1);
        char* address = PQgetvalue(res, i, 2);
        char* dateOfBirth = PQgetvalue(res, i, 3);
        char* position = PQgetvalue(res, i, 4);
        char* salary = PQgetvalue(res, i, 5);
        employeeList.push_back(Employee(atoi(id), name, address, dateOfBirth, position, strtoul(salary, NULL, 10)));
    }

    // printf("Total: %d rows\n", nrows);
}

std::vector<Employee> EmployeeMapper::getByName(std::string name) {
    PGresult* res;
    char query[100];
    std::vector<Employee> employeeList;
    snprintf(query, sizeof(query), "SELECT id, name, address, date_of_birth, position, salary FROM employees WHERE name = '%s';", name.c_str());
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }
    putPQResToList(res, employeeList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return employeeList;
}

std::vector<Employee> EmployeeMapper::getAll() {
    PGresult* res;
    char query[100];
    std::vector<Employee> employeeList;
    snprintf(query, sizeof(query), "SELECT id, name, address, date_of_birth, position, salary FROM employees;");
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }

    putPQResToList(res, employeeList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return employeeList;
}

bool EmployeeMapper::save(Employee& employee) {
    bool ret = true;
    if (PQstatus(conn->conn) == ConnStatusType::CONNECTION_OK) {
        PGresult* res = NULL;
        if (employee.id != 0) {
            char query[] =
                "UPDATE employees SET name = $2, address = $3, date_of_birth = TO_DATE($4, 'DD.MM.YYYY'), position = $5, salary = $6"
                " WHERE id = $1;";
            const char* params[6];
            std::string* employeeString = employee.getString();
            for (size_t i = 0; i < 6; i++)
                params[i] = employeeString[i].c_str();
            res = PQexecParams(conn->conn, query, 6, NULL, params,
                               NULL, NULL, 0);
            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                ret = false;
                printf("res != PGRES_COMMAND_OK\n");
                printf("Error message: %s\n", PQerrorMessage(conn->conn));
            }
            if (res != NULL) {
                PQclear(res);
                res = NULL;
            }
            if (employeeString)
                delete employeeString;
        } else {
            char query[] =
                "INSERT INTO employees (name, address, date_of_birth, position, salary)"
                "VALUES ($1, $2, TO_DATE($3, 'DD.MM.YYYY'), $4, $5);";
            const char* params[5];
            std::string* employeeString = employee.getString();
            for (size_t i = 0; i < 5; i++)
                params[i] = employeeString[i + 1].c_str();

            res = PQexecParams(conn->conn, query, 5, NULL, params, NULL, NULL, 1);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                ret = false;
                printf("res != PGRES_COMMAND_OK\n");
                printf("Error message: %s\n", PQerrorMessage(conn->conn));
            }
            if (res != NULL) {
                PQclear(res);
                res = NULL;
            }
            if (employeeString)
                delete employeeString;
        }
    } else {
        ret = false;
    }
    return ret;
}

bool EmployeeMapper::remove(Employee& employee) {
    bool ret = true;
    PGresult* res = NULL;
    if (employee.id != 0) {
        char query[100];
        std::vector<Employee> employeeList;
        snprintf(query, sizeof(query), "DELETE FROM employees WHERE id = %d;", employee.id);
        res = PQexec(conn->conn, query);

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            printf("res != PGRES_COMMAND_OK\n");
        }
    } else {
        ret = false;
    }
    return ret;
}
