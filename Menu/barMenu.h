#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "AssortmentMapper.h"
#include "DBConnection.h"
#include "DefaultTables.h"
#include "EmployeeMapper.h"
#include "SupplierMapper.h"
#include "TransferMapper.h"
#include "DrinkMapper.h"
#include "SnackMapper.h"
#include "RecipeMapper.h"

// EMPLOYEE
void getAllEmployee(DBConnection &dbConnection);
void addNewEmployee(DBConnection &dbConnection);
void deleteEmployee(DBConnection &dbConnection);
void moveEmployee(DBConnection &dbConnection);
void getEmployeeTransfers(DBConnection &dbConnection);

// SUPPLIER
void getAllSuppliers(DBConnection &dbConnection);
void addNewSuppliers(DBConnection &dbConnection);
void deleteSuppliers(DBConnection &dbConnection);
void changeSupplier(DBConnection &dbConnection);
void getSupplierAssortment(DBConnection &dbConnection);
void changeSupplierAssortment(DBConnection &dbConnection);
void addSupplierAssortment(DBConnection &dbConnection);

//BAR
void getAllMenu(DBConnection &dbConnection);
void getDrinkMenu(DBConnection &dbConnection);
void getFoodMenu(DBConnection &dbConnection);
void addProduct(DBConnection &dbConnection);
void deleteProduct(DBConnection &dbConnection);
void changeProduct(DBConnection &dbConnection);
void getProductRecipe(DBConnection &dbConnection);


#endif  // MENU_H