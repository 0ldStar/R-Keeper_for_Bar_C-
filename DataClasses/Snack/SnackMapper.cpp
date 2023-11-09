#include "SnackMapper.h"

SnackMapper::SnackMapper(DBConnection* conn) {
    this->conn = conn;
}

SnackMapper::~SnackMapper() {
}

void putPQResToList(PGresult* res, std::vector<Snack>& snackList) {
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
        char* size_of_portions = PQgetvalue(res, i, 2);
        snackList.push_back(Snack(atoi(id), name, atoi(size_of_portions)));
    }
}

std::vector<Snack> SnackMapper::getByName(std::string name) {
    PGresult* res;
    char query[100];
    std::vector<Snack> snackList;
    snprintf(query, sizeof(query), "SELECT id, name, size_of_portions FROM snacks WHERE name = '%s';", name.c_str());
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }
    putPQResToList(res, snackList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return snackList;
}

std::vector<Snack> SnackMapper::getAll() {
    PGresult* res;
    char query[100];
    std::vector<Snack> snackList;
    snprintf(query, sizeof(query), "SELECT id, name, size_of_portions FROM snacks;");
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }
    putPQResToList(res, snackList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return snackList;
}

bool SnackMapper::save(Snack& snack) {
    bool ret = true;
    PGresult* res = NULL;
    if (snack.id != 0) {
        char query[] =
            "UPDATE snacks SET name = $2, size_of_portions = $3"
            " WHERE id = $1;";
        const char* params[3];
        std::vector<std::string> snackString = snack.getString();
        for (size_t i = 0; i < 3; i++)
            params[i] = snackString[i].c_str();
        res = PQexecParams(conn->conn, query, 3, NULL, params, NULL, NULL, 0);
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
            "INSERT INTO snacks (name, size_of_portions)"
            "VALUES ($1, $2);";
        const char* params[2];
        std::vector<std::string> snackString = snack.getString();
        for (size_t i = 0; i < 2; i++)
            params[i] = snackString[i + 1].c_str();
        res = PQexecParams(conn->conn, query, 2, NULL, params, NULL, NULL, 0);

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

bool SnackMapper::remove(Snack& snack) {
    bool ret = true;
    PGresult* res = NULL;
    if (snack.id != 0) {
        char query[100];
        std::vector<Snack> snackList;
        snprintf(query, sizeof(query), "DELETE FROM snacks WHERE id = %d;", snack.id);
        res = PQexec(conn->conn, query);

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            printf("res != PGRES_COMMAND_OK\n");
        }
    } else {
        ret = false;
    }
    return ret;
}
