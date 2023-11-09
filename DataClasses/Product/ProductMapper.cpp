#include "ProductMapper.h"

ProductMapper::ProductMapper(DBConnection* conn) {
    this->conn = conn;
}

ProductMapper::~ProductMapper() {
}

void putPQResToList(PGresult* res, std::vector<Product>& productList) {
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
        productList.push_back(Product(atoi(id), name));
    }
}

std::vector<Product> ProductMapper::getByAssortmentId(unsigned assortmentId) {
    PGresult* res;
    char query[100];
    std::vector<Product> productList;
    snprintf(query, sizeof(query), "SELECT p.id, p.name FROM products p JOIN product_assortment pa ON p.id = pa.product_id WHERE pa.assortment_id = %u;", assortmentId);
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }
    putPQResToList(res, productList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return productList;
}

std::vector<Product> ProductMapper::getAll() {
    PGresult* res;
    char query[100];
    std::vector<Product> productList;
    snprintf(query, sizeof(query), "SELECT id, name FROM products;");
    res = PQexec(conn->conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("res != PGRES_TUPLES_OK\n");
        printf("Error message: %s\n", PQerrorMessage(conn->conn));
    }

    putPQResToList(res, productList);
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
    return productList;
}

bool ProductMapper::save(Product& product) {
    bool ret = true;
    PGresult* res = NULL;
    if (product.getId() != 0) {
        char query[] = "UPDATE products SET name = $2 WHERE id = $1;";
        const char* params[2];
        std::vector<std::string> productString = product.getString();
        for (size_t i = 0; i < 2; i++)
            params[i] = productString[i].c_str();
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
    } else {
        char query[] = "INSERT INTO products (name) VALUES ($1);";
        const char* params[1];
        std::vector<std::string> productString = product.getString();
        params[0] = productString[1].c_str();
        res = PQexecParams(conn->conn, query, 1, NULL, params, NULL, NULL, 0);

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

bool ProductMapper::remove(Product& product) {
    bool ret = true;
    PGresult* res = NULL;
    if (product.getId() != 0) {
        char query[100];
        snprintf(query, sizeof(query), "DELETE FROM products WHERE id = %u;", product.getId());
        res = PQexec(conn->conn, query);

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            printf("res != PGRES_COMMAND_OK\n");
        }
    } else {
        ret = false;
    }
    return ret;
}
