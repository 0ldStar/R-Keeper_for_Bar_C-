#include "RecipeMapper.h"

RecipeMapper::RecipeMapper(DBConnection* conn) {
    this->conn = conn;
}

RecipeMapper::~RecipeMapper() {
}

void putPQResToList(PGresult* res, std::vector<Recipe>& recipeList, Recipe::RecipeType type) {
    int ncols = PQnfields(res);
    for (int i = 0; i < ncols; i++) {
        char* name = PQfname(res, i);
        printf("%s ", name);
    }
    printf("\n");

    int nrows = PQntuples(res);
    for (int i = 0; i < nrows; i++) {
        char* id = PQgetvalue(res, i, 0);
        char* ingredient_id = PQgetvalue(res, i, 1);
        recipeList.push_back(Recipe(atoi(id), atoi(ingredient_id), type));
    }
}

std::vector<Recipe> RecipeMapper::getByType(Recipe::RecipeType type) {
    PGresult* res;
    char query[100];
    std::vector<Recipe> recipeList;
    const char* tableName = (type == Recipe::DRINK) ? "drinks_recipes" : "snacks_recipes";

    snprintf(query, sizeof(query), "SELECT id, ingredient_id FROM %s;", tableName);
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }
    putPQResToList(res, recipeList, type);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return recipeList;
}

std::vector<Recipe> RecipeMapper::getAll() {
    std::vector<Recipe> allRecipes;

    std::vector<Recipe> drinkRecipes = getByType(Recipe::DRINK);
    allRecipes.insert(allRecipes.end(), drinkRecipes.begin(), drinkRecipes.end());

    std::vector<Recipe> snackRecipes = getByType(Recipe::SNACK);
    allRecipes.insert(allRecipes.end(), snackRecipes.begin(), snackRecipes.end());

    return allRecipes;
}

bool RecipeMapper::save(Recipe& recipe) {
    bool ret = true;
    PGresult* res = NULL;
    const char* tableName = (recipe.getType() == Recipe::DRINK) ? "drinks_recipes" : "snacks_recipes";

    if (recipe.id != 0) {
        char query[] =
            "UPDATE %s SET ingredient_id = $2"
            " WHERE id = $1;";
        const char* params[2];
        std::string* recipeString = recipe.getString();
        for (size_t i = 0; i < 2; i++)
            params[i] = recipeString[i].c_str();
        snprintf(query, sizeof(query), query, tableName);
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
        if (recipeString)
            delete recipeString;
    } else {
        char query[] =
            "INSERT INTO %s (ingredient_id)"
            "VALUES ($1);";
        const char* params[1];
        std::string* recipeString = recipe.getString();
        params[0] = recipeString[1].c_str();
        snprintf(query, sizeof(query), query, tableName);
        res = PQexecParams(conn->conn, query, 1, NULL, params, NULL, NULL, 1);

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            ret = false;
            printf("res != PGRES_COMMAND_OK\n");
            printf("Error message: %s\n", PQerrorMessage(conn->conn));
        }
        if (res != NULL) {
            PQclear(res);
            res = NULL;
        }
        if (recipeString)
            delete recipeString;
    }
    return ret;
}

bool RecipeMapper::remove(Recipe& recipe) {
    bool ret = true;
    PGresult* res = NULL;
    const char* tableName = (recipe.getType() == Recipe::DRINK) ? "drinks_recipes" : "snacks_recipes";

    if (recipe.id != 0) {
        char query[100];
        snprintf(query, sizeof(query), "DELETE FROM %s WHERE id = %d;", tableName, recipe.id);
        res = PQexec(conn->conn, query);

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            printf("res != PGRES_COMMAND_OK\n");
        }
    } else {
        ret = false;
    }
    return ret;
}
