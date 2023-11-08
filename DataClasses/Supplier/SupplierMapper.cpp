#include "SupplierMapper.h"

SupplierMapper::SupplierMapper(DBConnection* conn) {
    this->conn = conn;
}

SupplierMapper::~SupplierMapper() {
}

void putPQResToList(PGresult* res, std::vector<Supplier>& supplierList) {
    int ncols = PQnfields(res);
    for (int i = 0; i < ncols; i++) {
        char* name = PQfname(res, i);
        printf("%s ", name);
    }
    printf("\n");

    int nrows = PQntuples(res);
    for (int i = 0; i < nrows; i++) {
        char* id = PQgetvalue(res, i, 0);
        char* name = PQgetvalue(res, i, 1);
        char* postAddress = PQgetvalue(res, i, 2);
        char* phoneNumber = PQgetvalue(res, i, 3);
        char* faxNumber = PQgetvalue(res, i, 4);
        char* email = PQgetvalue(res, i, 5);
        supplierList.push_back(Supplier(atoi(id), name, postAddress, phoneNumber, faxNumber, email));
    }
}

std::vector<Supplier> SupplierMapper::getByName(std::string name) {
    PGresult* res;
    char query[200];
    std::vector<Supplier> supplierList;
    snprintf(query, sizeof(query), "SELECT s.id, s.name, s.post_address, s.phone_number, s.fax_number, s.email FROM suppliers s WHERE s.name = '%s';", name.c_str());
    res = PQexec(conn->conn, query);
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }
    putPQResToList(res, supplierList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return supplierList;
}

std::vector<Supplier> SupplierMapper::getAll() {
    PGresult* res;
    char query[100];
    std::vector<Supplier> supplierList;
    snprintf(query, sizeof(query), "SELECT id, name, post_address, phone_number, fax_number, email FROM suppliers;");
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }

    putPQResToList(res, supplierList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return supplierList;
}

bool SupplierMapper::save(Supplier& supplier) {
    bool ret = true;
    PGresult* res = NULL;
    if (supplier.getId() != 0) {
        char query[] =
            "UPDATE suppliers SET name = $2, post_address = $3, phone_number = $4, fax_number = $5, email = $6"
            " WHERE id = $1;";
        const char* params[6];
        std::string* supplierString = supplier.getString();
        for (size_t i = 0; i < 6; i++)
            params[i] = supplierString[i].c_str();
        res = PQexecParams(conn->conn, query, 6, NULL, params, NULL, NULL, 0);
        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            ret = false;
            printf("res != PGRES_COMMAND_OK\n");
            printf("Error message: %s\n", PQerrorMessage(conn->conn));
        }
        if (res != NULL) {
            PQclear(res);
            res = NULL;
        }
        if (supplierString)
            delete supplierString;
    } else {
        char query[] =
            "INSERT INTO suppliers (name, post_address, phone_number, fax_number, email)"
            "VALUES ($1, $2, $3, $4, $5);";
        const char* params[5];
        std::string* supplierString = supplier.getString();
        for (size_t i = 0; i < 5; i++)
            params[i] = supplierString[i + 1].c_str();
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
        if (supplierString)
            delete supplierString;
    }
    return ret;
}

bool SupplierMapper::remove(Supplier& supplier) {
    bool ret = true;
    PGresult* res = NULL;
    if (supplier.getId() != 0) {
        char query[100];
        snprintf(query, sizeof(query), "DELETE FROM suppliers WHERE id = %u;", supplier.getId());
        res = PQexec(conn->conn, query);

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            printf("res != PGRES_COMMAND_OK\n");
        }
    } else {
        ret = false;
    }
    return ret;
}
