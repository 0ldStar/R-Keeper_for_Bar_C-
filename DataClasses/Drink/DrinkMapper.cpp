#include "DrinkMapper.h"

DrinkMapper::DrinkMapper(DBConnection* conn) {
    this->conn = conn;
}

DrinkMapper::~DrinkMapper() {
}

void putPQResToList(PGresult* res, std::vector<Drink>& drinkList) {
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
        char* portion_size = PQgetvalue(res, i, 2);
        char* capacity = PQgetvalue(res, i, 3);
        drinkList.push_back(Drink(atoi(id), name, atoi(portion_size), capacity));
    }
}

std::vector<Drink> DrinkMapper::getByName(std::string name) {
    PGresult* res;
    char query[100];
    std::vector<Drink> drinkList;
    snprintf(query, sizeof(query), "SELECT id, name, portion_size, capacity FROM drinks WHERE name = '%s';", name.c_str());
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }
    putPQResToList(res, drinkList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return drinkList;
}

std::vector<Drink> DrinkMapper::getAll() {
    PGresult* res;
    char query[100];
    std::vector<Drink> drinkList;
    snprintf(query, sizeof(query), "SELECT id, name, portion_size, capacity FROM drinks;");
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }
    putPQResToList(res, drinkList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return drinkList;
}

bool DrinkMapper::save(Drink& drink) {
    bool ret = true;
    PGresult* res = NULL;
    if (drink.id != 0) {
        char query[] =
            "UPDATE drinks SET name = $2, portion_size = $3, capacity = $4"
            " WHERE id = $1;";
        const char* params[4];
        std::vector<std::string> drinkString = drink.getString();
        for (size_t i = 0; i < 4; i++)
            params[i] = drinkString[i].c_str();
        res = PQexecParams(conn->conn, query, 4, NULL, params, NULL, NULL, 0);
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
            "INSERT INTO drinks (name, portion_size, capacity)"
            "VALUES ($1, $2, $3);";
        const char* params[3];
        std::vector<std::string> drinkString = drink.getString();
        for (size_t i = 0; i < 3; i++)
            params[i] = drinkString[i + 1].c_str();
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
    }
    return ret;
}

bool DrinkMapper::remove(Drink& drink) {
    bool ret = true;
    PGresult* res = NULL;
    if (drink.id != 0) {
        char query[100];
        std::vector<Drink> drinkList;
        snprintf(query, sizeof(query), "DELETE FROM drinks WHERE id = %d;", drink.id);
        res = PQexec(conn->conn, query);

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            printf("res != PGRES_COMMAND_OK\n");
        }
    } else {
        ret = false;
    }
    return ret;
}
