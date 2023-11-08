#include "menu.h"

// void getAllMenu(DBConnection &dbConnection) {
//     MenuMapper menuMapper = MenuMapper(&dbConnection);
//     std::vector<MenuItem> menuItems = menuMapper.getAll();

//     if (menuItems.empty()) {
//         std::cout << "The menu is empty." << std::endl;
//     } else {
//         std::cout << "Menu items:" << std::endl;
//         for (const MenuItem &item : menuItems) {
//             item.print();
//         }
//     }
// }

// void getDrinkMenu(DBConnection &dbConnection) {
//     MenuMapper menuMapper = MenuMapper(&dbConnection);
//     std::vector<MenuItem> drinkMenu = menuMapper.getDrinkMenu();

//     if (drinkMenu.empty()) {
//         std::cout << "No drinks in the menu." << std::endl;
//     } else {
//         std::cout << "Drink menu:" << std::endl;
//         for (const MenuItem &drink : drinkMenu) {
//             drink.print();
//         }
//     }
// }

// void getFoodMenu(DBConnection &dbConnection) {
//     MenuMapper menuMapper = MenuMapper(&dbConnection);
//     std::vector<MenuItem> foodMenu = menuMapper.getFoodMenu();

//     if (foodMenu.empty()) {
//         std::cout << "No food items in the menu." << std::endl;
//     } else {
//         std::cout << "Food menu:" << std::endl;
//         for (const MenuItem &food : foodMenu) {
//             food.print();
//         }
//     }
// }

// void addProduct(DBConnection &dbConnection) {
//     MenuMapper menuMapper = MenuMapper(&dbConnection);

//     std::string name;
//     double price;
//     std::string description;

//     std::cout << "Enter the name of the product: ";
//     std::cin.ignore();
//     std::getline(std::cin, name);
//     std::cout << "Enter the price of the product: ";
//     std::cin >> price;
//     std::cin.ignore();
//     std::cout << "Enter the description of the product: ";
//     std::getline(std::cin, description);

//     MenuItem newProduct(name, price, description);

//     if (menuMapper.save(newProduct)) {
//         std::cout << "Product added to the menu successfully." << std::endl;
//     } else {
//         std::cout << "Failed to add the product." << std::endl;
//     }
// }

// void deleteProduct(DBConnection &dbConnection) {
//     MenuMapper menuMapper = MenuMapper(&dbConnection);

//     std::string name;
//     std::cout << "Enter the name of the product to delete: ";
//     std::cin.ignore();
//     std::getline(std::cin, name);

//     std::vector<MenuItem> menuItems = menuMapper.getByName(name);

//     if (menuItems.empty()) {
//         std::cout << "No products found with that name." << std::endl;
//     } else {
//         std::cout << "Select the product to delete:" << std::endl;
//         for (size_t i = 0; i < menuItems.size(); ++i) {
//             std::cout << i + 1 << ") " << menuItems[i].getName() << std::endl;
//         }

//         int choice;
//         std::cin >> choice;

//         if (choice > 0 && choice <= menuItems.size()) {
//             if (menuMapper.remove(menuItems[choice - 1])) {
//                 std::cout << "Product removed from the menu successfully." << std::endl;
//             } else {
//                 std::cout << "Failed to remove the product." << std::endl;
//             }
//         } else {
//             std::cout << "Invalid choice." << std::endl;
//         }
//     }
// }

// void changeProduct(DBConnection &dbConnection) {
//     MenuMapper menuMapper = MenuMapper(&dbConnection);

//     std::string name;
//     std::cout << "Enter the name of the product to change: ";
//     std::cin.ignore();
//     std::getline(std::cin, name);

//     std::vector<MenuItem> menuItems = menuMapper.getByName(name);

//     if (menuItems.empty()) {
//         std::cout << "No products found with that name." << std::endl;
//     } else {
//         std::cout << "Select the product to change:" << std::endl;
//         for (size_t i = 0; i < menuItems.size(); ++i) {
//             std::cout << i + 1 << ") " << menuItems[i].getName() << std::endl;
//         }

//         int choice;
//         std::cin >> choice;

//         if (choice > 0 && choice <= menuItems.size()) {
//             std::string newName;
//             double newPrice;
//             std::string newDescription;

//             std::cout << "Enter new name: ";
//             std::cin.ignore();
//             std::getline(std::cin, newName);
//             std::cout << "Enter new price: ";
//             std::cin >> newPrice;
//             std::cin.ignore();
//             std::cout << "Enter new description: ";
//             std::getline(std::cin, newDescription);

//             menuItems[choice - 1].setName(newName);
//             menuItems[choice - 1].setPrice(newPrice);
//             menuItems[choice - 1].setDescription(newDescription);

//             if (menuMapper.save(menuItems[choice - 1])) {
//                 std::cout << "Product changed successfully." << std::endl;
//             } else {
//                 std::cout << "Failed to change the product." << std::endl;
//             }
//         } else {
//             std::cout << "Invalid choice." << std::endl;
//         }
//     }
// }