#include "IngredientMapper.h"

IngredientMapper::IngredientMapper(DBConnection* conn, ProductMapper* productMapper) {
    this->conn = conn;
    this->productMapper = productMapper;
}

IngredientMapper::~IngredientMapper() {
}

void putPQResToList(PGresult* res, std::vector<Ingredient>& ingredientList) {
    int ncols = PQnfields(res);
    for (int i = 0; i < ncols; i++) {
        char* name = PQfname(res, i);
        printf("%s ", name);
    }
    printf("\n");

    int nrows = PQntuples(res);
    for (int i = 0; i < nrows; i++) {
        char* id = PQgetvalue(res, i, 0);
        char* productId = PQgetvalue(res, i, 1);
        char* quantity = PQgetvalue(res, i, 2);
        char* unitOfMeasurement = PQgetvalue(res, i, 3);
        ingredientList.push_back(Ingredient(atoi(id), atoi(productId), atoi(quantity), unitOfMeasurement));
    }
}

std::vector<Ingredient> IngredientMapper::getByProductName(std::string name) {
    PGresult* res;
    char query[200];
    std::vector<Ingredient> ingredientList;
    snprintf(query, sizeof(query), "SELECT i.id, i.product_id, i.quantity, i.unit_of_measurement FROM ingredients i JOIN products p ON i.product_id = p.id WHERE p.name = '%s';", name.c_str());
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }
    putPQResToList(res, ingredientList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return ingredientList;
}

std::vector<Ingredient> IngredientMapper::getAll() {
    PGresult* res;
    char query[100];
    std::vector<Ingredient> ingredientList;
    snprintf(query, sizeof(query), "SELECT id, product_id, quantity, unit_of_measurement FROM ingredients;");
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }

    putPQResToList(res, ingredientList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return ingredientList;
}

bool IngredientMapper::save(Ingredient& ingredient) {
    bool ret = true;
    PGresult* res = NULL;
    if (ingredient.getId() != 0) {
        char query[] =
            "UPDATE ingredients SET product_id = $2, quantity = $3, unit_of_measurement = $4"
            " WHERE id = $1;";
        const char* params[4];
        std::vector<std::string> ingredientString = ingredient.getString();
        for (size_t i = 0; i < 4; i++)
            params[i] = ingredientString[i].c_str();
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
            "INSERT INTO ingredients (product_id, quantity, unit_of_measurement)"
            "VALUES ($1, $2, $3);";
        const char* params[3];
        std::vector<std::string> ingredientString = ingredient.getString();
        for (size_t i = 0; i < 3; i++)
            params[i] = ingredientString[i + 1].c_str();
        res = PQexecParams(conn->conn, query, 3, NULL, params, NULL, NULL, 1);

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

bool IngredientMapper::remove(Ingredient& ingredient) {
    bool ret = true;
    PGresult* res = NULL;
    if (ingredient.getId() != 0) {
        char query[100];
        snprintf(query, sizeof(query), "DELETE FROM ingredients WHERE id = %u;", ingredient.getId());
        res = PQexec(conn->conn, query);

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            printf("res != PGRES_COMMAND_OK\n");
        }
    } else {
        ret = false;
    }
    return ret;
}
