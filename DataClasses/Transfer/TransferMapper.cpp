#include "TransferMapper.h"

TransferMapper::TransferMapper(DBConnection* conn) {
    this->conn = conn;
}

TransferMapper::~TransferMapper() {
}

void TransferMapper::saveId(PGresult* res, Transfer& transfer) {
    transfer.id = atoi(PQgetvalue(res, 0, 0));
}

void putPQResToList(PGresult* res, std::vector<Transfer>& transferList) {
    int nrows = PQntuples(res);
    for (int i = 0; i < nrows; i++) {
        char* id = PQgetvalue(res, i, 0);
        char* employeeId = PQgetvalue(res, i, 1);
        char* position = PQgetvalue(res, i, 2);
        char* reason = PQgetvalue(res, i, 3);
        char* numberOfOrder = PQgetvalue(res, i, 4);
        char* dateOfOrder = PQgetvalue(res, i, 5);
        transferList.push_back(Transfer(atoi(id), atoi(employeeId), position, reason, atoi(numberOfOrder), dateOfOrder));
    }
}

std::vector<Transfer> TransferMapper::getByEmployeeID(unsigned employeeId) {
    PGresult* res;
    char query[200];
    std::vector<Transfer> transferList;
    snprintf(query, sizeof(query), "SELECT id, employee_id, position, reason, number_of_order, date_of_order FROM transfers WHERE employee_id = %d;", employeeId);
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }
    putPQResToList(res, transferList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return transferList;
}

std::vector<Transfer> TransferMapper::getAll() {
    PGresult* res;
    char query[100];
    std::vector<Transfer> transferList;
    snprintf(query, sizeof(query), "SELECT id, employee_id, position, reason, number_of_order, date_of_order FROM transfers;");
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }
    putPQResToList(res, transferList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return transferList;
}

bool TransferMapper::save(Transfer& transfer) {
    bool ret = true;
    PGresult* res = NULL;
    if (transfer.id != 0) {
        char query[] =
            "UPDATE transfers SET employeeId = $2, position = $3, reason = $4, number_of_order = $5, date_of_order = TO_DATE($6, 'DD.MM.YYYY')"
            " WHERE id = $1;";
        const char* params[6];
        std::vector<std::string> transferString = transfer.getString();
        for (size_t i = 0; i < 6; i++)
            params[i] = transferString[i].c_str();
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
            "INSERT INTO transfers (employee_id, position, reason, number_of_order, date_of_order)"
            "VALUES ($1, $2, $3, $4, TO_DATE($5, 'DD.MM.YYYY')) RETURNING id;";
        const char* params[5];
        std::vector<std::string> transferString = transfer.getString();
        for (size_t i = 0; i < 5; i++)
            params[i] = transferString[i + 1].c_str();
        res = PQexecParams(conn->conn, query, 5, NULL, params, NULL, NULL, 0);

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            ret = false;
            printf("res != PGRES_TUPLES_OK\n");
            printf("Error message: %s\n", PQerrorMessage(conn->conn));
            PQclear(res);
            res = NULL;
            return ret;
        }
        saveId(res, transfer);
        if (res != NULL) {
            PQclear(res);
            res = NULL;
        }
    }
    return ret;
}

bool TransferMapper::remove(Transfer& transfer) {
    bool ret = true;
    PGresult* res = NULL;
    if (transfer.id != 0) {
        char query[100];
        std::vector<Transfer> transferList;
        snprintf(query, sizeof(query), "DELETE FROM transfers WHERE id = %d;", transfer.id);
        res = PQexec(conn->conn, query);

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            printf("res != PGRES_COMMAND_OK\n");
        }
    } else {
        ret = false;
    }
    return ret;
}
