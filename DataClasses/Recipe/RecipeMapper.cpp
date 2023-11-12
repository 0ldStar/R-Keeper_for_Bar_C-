#include "RecipeMapper.h"

RecipeMapper::RecipeMapper(DBConnection* conn) {
    this->conn = conn;
}

RecipeMapper::~RecipeMapper() {
}

void putPQResToList(PGresult* res, Recipe::RecipeType type, std::vector<Recipe>& recipeList) {
    std::vector<Ingredient> ingredients;
    int nrows = PQntuples(res);
    if (nrows == 0)
        return;

    char* id;
    for (int i = 0; i < nrows; i++) {
        id = PQgetvalue(res, i, 0);
        char* product_id = PQgetvalue(res, i, 1);
        char* product_name = PQgetvalue(res, i, 2);
        char* ingredient_id = PQgetvalue(res, i, 3);
        char* ingredient_quantuty = PQgetvalue(res, i, 4);
        char* unit_of_measurement = PQgetvalue(res, i, 5);
        Product product = Product(atoi(product_id), product_name);
        ingredients.push_back(Ingredient(product, atoi(ingredient_id), atoi(product_id), atoi(ingredient_quantuty), unit_of_measurement));
    }
    recipeList.push_back(Recipe(atoi(id), type, ingredients));
}

std::vector<Recipe> RecipeMapper::getByPositionId(Recipe::RecipeType type, unsigned id) {
    PGresult* res;
    char query[250];
    std::vector<Recipe> recipeList;
    const char* tableName = (type == Recipe::DRINK) ? "drinks_recipes" : "snacks_recipes";

    snprintf(query, sizeof(query),
             "SELECT dr.drink_id, p.id, p.name, i.id, i.quantity, i.unit_of_measurement FROM products p "
             "INNER JOIN ingredients i ON p.id = i.product_id INNER JOIN  %s dr ON i.id = dr.ingredient_id WHERE dr.drink_id = '%u';",
             tableName, id);
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }
    putPQResToList(res, type, recipeList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return recipeList;
}
