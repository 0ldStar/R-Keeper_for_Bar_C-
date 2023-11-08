#include "DefaultTables.h"

DefaultTables::DefaultTables(DBConnection* dbConnnection_) {
    this->dbConnection = dbConnnection_;
    char emloyeesTable[] =
        "CREATE TABLE IF NOT EXISTS employees ("
        "  id SERIAL PRIMARY KEY,"
        "  name text,"
        "  address text,"
        "  date_of_birth date,"
        "  position text,"
        "  salary numeric);";
    char transfersTable[] =
        "CREATE TABLE IF NOT EXISTS transfers ("
        "  id SERIAL PRIMARY KEY,"
        "  employee_id integer,"
        "  position text,"
        "  reason text,"
        "  number_of_order integer,"
        "  date_of_order date);";
    char drinksTable[] =
        "CREATE TABLE IF NOT EXISTS drinks ("
        "  id SERIAL PRIMARY KEY,"
        "  name text,"
        "  portion_size integer,"
        "  capacity capacity_enum);";
    char ingredientsTable[] =
        "CREATE TABLE IF NOT EXISTS ingredients ("
        "  id SERIAL PRIMARY KEY,"
        "  product_id integer,"
        "  quantity integer,"
        "  unit_of_measurement text);";
    char drinksResipes[] =
        "CREATE TABLE IF NOT EXISTS drinks_recipes ("
        "  drink_id integer,"
        "  ingredient_id integer,"
        "  PRIMARY KEY (drink_id, ingredient_id));";
    char snacksRecipes[] =
        "CREATE TABLE IF NOT EXISTS snacks_recipes ("
        "  snack_id integer,"
        "  ingredient_id integer,"
        "  PRIMARY KEY (snack_id, ingredient_id));";
    char snacksTable[] =
        "CREATE TABLE IF NOT EXISTS snacks ("
        "  id SERIAL PRIMARY KEY,"
        "  name text,"
        "  size_of_portions integer);";
    char suppliersTable[] =
        "CREATE TABLE IF NOT EXISTS suppliers ("
        "  id serial PRIMARY KEY,"
        "  name text,"
        "  post_address text,"
        "  phone_number text,"
        "  fax_number text,"
        "  email text);";
    char bankDetailsTable[] =
        "CREATE TABLE IF NOT EXISTS bank_details ("
        "  id serial PRIMARY KEY,"
        "  supplier_id integer,"
        "  name text,"
        "  city text,"
        "  tin text,"
        "  settlement_account text);";
    char assortmentsTable[] =
        "CREATE TABLE IF NOT EXISTS assortments ("
        "  id serial PRIMARY KEY,"
        "  supplier_id integer,"
        "  wholesale_price numeric,"
        "  delivery_terms text,"
        "  payment_terms text);";
    char productsTable[] =
        "CREATE TABLE IF NOT EXISTS products ("
        "  id SERIAL PRIMARY KEY,"
        "  name text);";
    char productAssortmentTable[] =
        "CREATE TABLE IF NOT EXISTS product_assortment ("
        "  assortment_id integer,"
        "  product_id integer,"
        "  PRIMARY KEY (assortment_id, product_id));";
    char foreignKeys[] =
        "ALTER TABLE transfers ADD FOREIGN KEY (employee_id) REFERENCES employees (id);"
        "ALTER TABLE drinks_recipes ADD FOREIGN KEY (drink_id) REFERENCES drinks (id);"
        "ALTER TABLE snacks_recipes ADD FOREIGN KEY (snack_id) REFERENCES snacks (id);"
        "ALTER TABLE drinks_recipes ADD FOREIGN KEY (ingredient_id) REFERENCES ingredients (id);"
        "ALTER TABLE snacks_recipes ADD FOREIGN KEY (ingredient_id) REFERENCES ingredients (id);"
        "ALTER TABLE ingredients ADD FOREIGN KEY (product_id) REFERENCES products (id);"
        "ALTER TABLE product_assortment ADD FOREIGN KEY (product_id) REFERENCES products (id);"
        "ALTER TABLE product_assortment ADD FOREIGN KEY (assortment_id) REFERENCES assortments (id);"
        "ALTER TABLE bank_details ADD FOREIGN KEY (supplier_id) REFERENCES suppliers (id);"
        "ALTER TABLE assortments ADD FOREIGN KEY (supplier_id) REFERENCES suppliers (id);";
    char capacityEnum[] =
        "DO $$ BEGIN"
        "    CREATE TYPE capacity_enum AS ENUM ('glass', 'glass for wine', 'glass for beer', 'shot');"
        "EXCEPTION"
        "    WHEN duplicate_object THEN null;"
        "END $$;";
    dbConnection->executeCreateTables(capacityEnum);
    dbConnection->executeCreateTables(emloyeesTable);
    dbConnection->executeCreateTables(transfersTable);
    dbConnection->executeCreateTables(drinksTable);
    dbConnection->executeCreateTables(ingredientsTable);
    dbConnection->executeCreateTables(drinksResipes);
    dbConnection->executeCreateTables(snacksRecipes);
    dbConnection->executeCreateTables(snacksTable);
    dbConnection->executeCreateTables(suppliersTable);
    dbConnection->executeCreateTables(bankDetailsTable);
    dbConnection->executeCreateTables(assortmentsTable);
    dbConnection->executeCreateTables(productsTable);
    dbConnection->executeCreateTables(productAssortmentTable);
    dbConnection->executeCreateTables(foreignKeys);
}

DefaultTables::~DefaultTables() {
}
