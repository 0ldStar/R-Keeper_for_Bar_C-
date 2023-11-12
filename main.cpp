#include "barMenu.h"

int main() {
    DBConnection dbConnection = DBConnection();
    dbConnection.printInfo();
    DefaultTables defaultTables = DefaultTables(&dbConnection);

    int input = 0;
    while (input != 4) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        std::cout << "R-Keeper for Bar (C)NSTU" << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "1) Bar menu" << std::endl;
        std::cout << "2) Employees menu" << std::endl;
        std::cout << "3) Suppliers menu" << std::endl;
        std::cout << "4) Exit" << std::endl;
        std::cin >> input;
        switch (input) {
            case 1:
                while (input != 7) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << std::endl;
                    std::cout << "Bar menu:" << std::endl;
                    std::cout << "1) Get all menu" << std::endl;
                    std::cout << "2) Get the drink menu" << std::endl;
                    std::cout << "3) Get the food menu" << std::endl;
                    std::cout << "4) Add a product to the menu" << std::endl;
                    std::cout << "5) Remove product from menu" << std::endl;
                    std::cout << "6) Change product from menu" << std::endl;
                    std::cout << "7)Exit" << std::endl;
                    std::cin >> input;
                    // switch (input) {
                    //     case 1:
                    //         getAllMenu(dbConnection);
                    //         break;
                    //     case 2:
                    //         getDrinkMenu(dbConnection);
                    //         break;
                    //     case 3:
                    //         getFoodMenu(dbConnection);
                    //         break;
                    //     case 4:
                    //         addProduct(dbConnection);
                    //         break;
                    //     case 5:
                    //         deleteProduct(dbConnection);
                    //         break;
                    //     case 6:
                    //         changeProduct(dbConnection);
                    //         break;
                    //     default:
                    //         break;
                    // }
                }

                break;
            case 2:
                while (input != 6) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << std::endl;
                    std::cout << "Employees menu:" << std::endl;
                    std::cout << "1) Get a list of employees" << std::endl;
                    std::cout << "2) Hire employee" << std::endl;
                    std::cout << "3) Fire employee" << std::endl;
                    std::cout << "4) Transfer an employee" << std::endl;
                    std::cout << "5) Get employee transfers" << std::endl;
                    std::cout << "6) Exit" << std::endl;
                    std::cin >> input;
                    switch (input) {
                        case 1:
                            getAllEmployee(dbConnection);
                            break;
                        case 2:
                            addNewEmployee(dbConnection);
                            break;
                        case 3:
                            deleteEmployee(dbConnection);
                            break;
                        case 4:
                            moveEmployee(dbConnection);
                            break;
                        case 5:
                            getEmployeeTransfers(dbConnection);
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 3:
                while (input != 8) {
                    std::cout << std::endl;
                    std::cout << "Suppliers menu:" << std::endl;
                    std::cout << "1) Get a list of suppliers" << std::endl;
                    std::cout << "2) Add supplier" << std::endl;
                    std::cout << "3) Remove supplier" << std::endl;
                    std::cout << "4) Change supplier details" << std::endl;
                    std::cout << "5) Get the supplier's assortment" << std::endl;
                    std::cout << "6) Add supplier's assortment" << std::endl;
                    std::cout << "7) Change supplier`s assortment" << std::endl;
                    std::cout << "8)Exit" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> input;
                    switch (input) {
                        case 1:
                            getAllSuppliers(dbConnection);
                            break;
                        case 2:
                            addNewSuppliers(dbConnection);
                            break;
                        case 3:
                            deleteSuppliers(dbConnection);
                            break;
                        case 4:
                            changeSupplier(dbConnection);
                            break;
                        case 5:
                            getSupplierAssortment(dbConnection);
                            break;
                        case 6:
                            addSupplierAssortment(dbConnection);
                            break;
                        case 7:
                            changeSupplierAssortment(dbConnection);
                            break;
                        default:
                            break;
                    }
                }
                break;
            default:
                break;
        }
    }
    return 0;
}