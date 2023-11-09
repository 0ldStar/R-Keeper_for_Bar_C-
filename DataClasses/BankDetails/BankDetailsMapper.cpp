#include "BankDetailsMapper.h"
#include <iostream>

BankDetailsMapper::BankDetailsMapper(DBConnection* conn) {
    this->conn = conn;
}

BankDetailsMapper::~BankDetailsMapper() {
}

void putPQResToList(PGresult* res, std::vector<BankDetails>& bankDetailsList) {
    int ncols = PQnfields(res);
    for (int i = 0; i < ncols; i++) {
        char* name = PQfname(res, i);
        printf("%s ", name);
    }
    printf("\n");

    int nrows = PQntuples(res);
    for (int i = 0; i < nrows; i++) {
        char* id = PQgetvalue(res, i, 0);
        char* supplierId = PQgetvalue(res, i, 1);
        char* name = PQgetvalue(res, i, 2);
        char* city = PQgetvalue(res, i, 3);
        char* TIN = PQgetvalue(res, i, 4);
        char* settlementAccount = PQgetvalue(res, i, 5);
        bankDetailsList.push_back(BankDetails(atoi(id), atoi(supplierId), name, city, TIN, settlementAccount));
    }
}

std::vector<BankDetails> BankDetailsMapper::getBySupplierName(std::string name) {
    PGresult* res;
    char query[200];
    std::vector<BankDetails> bankDetailsList;
    snprintf(query, sizeof(query), "SELECT bd.id, bd.supplier_id, bd.name, bd.city, bd.TIN, bd.settlement_account FROM bank_details bd JOIN suppliers s ON bd.supplier_id = s.id WHERE s.name = '%s';", name.c_str());
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }
    putPQResToList(res, bankDetailsList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return bankDetailsList;
}

std::vector<BankDetails> BankDetailsMapper::getAll() {
    PGresult* res;
    char query[100];
    std::vector<BankDetails> bankDetailsList;
    snprintf(query, sizeof(query), "SELECT id, supplier_id, name, city, TIN, settlement_account FROM bank_details;");
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }

    putPQResToList(res, bankDetailsList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return bankDetailsList;
}

bool BankDetailsMapper::save(BankDetails& bankDetails) {
    bool ret = true;
    PGresult* res = NULL;
    if (bankDetails.getId() != 0) {
        char query[] =
            "UPDATE bank_details SET supplier_id = $2, name = $3, city = $4, TIN = $5, settlement_account = $6"
            " WHERE id = $1;";
        const char* params[6];
        std::vector<std::string> bankDetailsString = bankDetails.getString();
        for (size_t i = 0; i < 6; i++)
            params[i] = bankDetailsString[i].c_str();
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
    } else {
        char query[] =
            "INSERT INTO bank_details (supplier_id, name, city, TIN, settlement_account)"
            "VALUES ($1, $2, $3, $4, $5);";
        const char* params[5];
        std::vector<std::string> bankDetailsString = bankDetails.getString();
        for (size_t i = 0; i < 5; i++)
            params[i] = bankDetailsString[i + 1].c_str();
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
    }
    return ret;
}

bool BankDetailsMapper::remove(BankDetails& bankDetails) {
    bool ret = true;
    PGresult* res = NULL;
    if (bankDetails.getId() != 0) {
        char query[100];
        snprintf(query, sizeof(query), "DELETE FROM bank_details WHERE id = %u;", bankDetails.getId());
        res = PQexec(conn->conn, query);

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            printf("res != PGRES_COMMAND_OK\n");
        }
    } else {
        ret = false;
    }
    return ret;
}
