#include "DBConnection.h"

#define UNUSED(x) (void)(x)

void DBConnection::clearRes() {
    if (res != NULL) {
        PQclear(res);
        res = NULL;
    }
}

void processNotice(void *arg, const char *message) {
    UNUSED(arg);
    UNUSED(message);
    // do nothing
}
void DBConnection::terminate(int code) {
    if (code != 0)
        fprintf(stderr, "%s\n", PQerrorMessage(conn));

    if (res != NULL)
        PQclear(res);

    if (conn != NULL)
        PQfinish(conn);

    exit(code);
}
void DBConnection::printInfo() {
    int server_ver = PQserverVersion(conn);
    char *user = PQuser(conn);
    char *db_name = PQdb(conn);
    int libpq_ver = PQlibVersion();

    printf("Version of libpq: %d\n", libpq_ver);
    printf("Server version: %d\n", server_ver);
    printf("User: %s\n", user);
    printf("Database name: %s\n", db_name);
}
DBConnection::DBConnection() {
    conn = PQconnectdb("dbname=rpbd_lab1 host=localhost user=db_admin password=password");  // move to config file
    res = NULL;
    if (PQstatus(conn) == CONNECTION_BAD) {
        puts("We were unable to connect to the database");
        terminate(1);
    }
    // PQsetNoticeProcessor(conn, processNotice, NULL);  // disable NOTICE
}

DBConnection::~DBConnection() {
    if (res != NULL)
        PQclear(res);

    if (conn != NULL)
        PQfinish(conn);
}

void DBConnection::executeCreateTables(char *query) {
    res = PQexec(conn, query);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        // printf("res %d != PGRES_COMMAND_OK\n", *res);
        terminate(1);
    }
    clearRes();
}
