#include "barMenu.h"

void getAllMenu(DBConnection &dbConnection) {
    DrinkMapper drinkMapper(&dbConnection);
    SnackMapper snackMapper(&dbConnection);

    std::vector<Drink> drinks = drinkMapper.getAll();
    std::vector<Snack> snacks = snackMapper.getAll();

    std::cout << "Drink Menu:\n";
    for (auto &drink : drinks) {
        drink.print();
    }

    std::cout << "\nSnack Menu:\n";
    for (auto &snack : snacks) {
        snack.print();
    }
}

void getDrinkMenu(DBConnection &dbConnection) {
    DrinkMapper drinkMapper(&dbConnection);
    std::vector<Drink> drinks = drinkMapper.getAll();

    std::cout << "Drink Menu:\n";
    for (auto &drink : drinks) {
        drink.print();
    }
}

void getFoodMenu(DBConnection &dbConnection) {
    SnackMapper snackMapper(&dbConnection);
    std::vector<Snack> snacks = snackMapper.getAll();

    std::cout << "Snack Menu:\n";
    for (auto &snack : snacks) {
        snack.print();
    }
}
void addProduct(DBConnection &dbConnection) {
    int choice;
    std::cout << "1. Add Drink\n2. Add Snack\nEnter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        DrinkMapper drinkMapper(&dbConnection);
        std::string name, capacity;
        unsigned portionSize;

        std::cout << "Enter Drink Name: ";
        std::cin >> name;
        std::cout << "Enter Portion Size: ";
        std::cin >> portionSize;
        std::cout << "Enter Capacity: ";
        std::cin >> capacity;

        Drink newDrink(name, portionSize, capacity);
        drinkMapper.save(newDrink);
    } else if (choice == 2) {
        SnackMapper snackMapper(&dbConnection);
        std::string name;
        unsigned portionSize;

        std::cout << "Enter Snack Name: ";
        std::cin >> name;
        std::cout << "Enter Portion Size: ";
        std::cin >> portionSize;

        Snack newSnack(name, portionSize);
        snackMapper.save(newSnack);
    } else {
        std::cout << "Invalid choice.\n";
    }
}

void deleteProduct(DBConnection &dbConnection) {
    int choice;
    std::cout << "1. Delete Drink\n2. Delete Snack\nEnter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        DrinkMapper drinkMapper(&dbConnection);
        std::vector<Drink> drinks = drinkMapper.getAll();

        for (size_t i = 0; i < drinks.size(); ++i) {
            std::cout << i << ") ";
            drinks[i].print();
        }

        size_t selection;
        std::cout << "Select the index of the drink to delete: ";
        std::cin >> selection;

        if (selection < drinks.size()) {
            if (drinkMapper.remove(drinks[selection])) {
                std::cout << "Drink removed successfully." << std::endl;
            } else {
                std::cout << "Failed to remove drink." << std::endl;
            }
        } else {
            std::cout << "Invalid selection.\n";
        }
    } else if (choice == 2) {
        SnackMapper snackMapper(&dbConnection);
        std::vector<Snack> snacks = snackMapper.getAll();

        for (size_t i = 0; i < snacks.size(); ++i) {
            std::cout << i << ") ";
            snacks[i].print();
        }

        size_t selection;
        std::cout << "Select the index of the snack to delete: ";
        std::cin >> selection;

        if (selection < snacks.size()) {
            if (snackMapper.remove(snacks[selection])) {
                std::cout << "Snack removed successfully." << std::endl;
            } else {
                std::cout << "Failed to remove snack." << std::endl;
            }
        } else {
            std::cout << "Invalid selection.\n";
        }
    } else {
        std::cout << "Invalid choice.\n";
    }
}

void changeProduct(DBConnection &dbConnection) {
    int choice;
    std::cout << "1. Change Drink\n2. Change Snack\nEnter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        DrinkMapper drinkMapper(&dbConnection);
        std::vector<Drink> drinks = drinkMapper.getAll();

        for (size_t i = 0; i < drinks.size(); ++i) {
            std::cout << i << ") ";
            drinks[i].print();
        }

        size_t selection;
        std::cout << "Select the index of the drink to change: ";
        std::cin >> selection;

        if (selection < drinks.size()) {
            std::string name, capacity;
            unsigned portionSize;

            std::cout << "Enter new Drink Name: ";
            std::cin >> name;
            std::cout << "Enter new Portion Size: ";
            std::cin >> portionSize;
            std::cout << "Enter new Capacity: ";
            std::cin >> capacity;

            Drink drink = Drink(drinks[selection].getId(), name, portionSize, capacity);
            drinkMapper.save(drink);
            std::cout << "Drink details updated successfully.\n";
        } else {
            std::cout << "Invalid selection.\n";
        }
    } else if (choice == 2) {
        SnackMapper snackMapper(&dbConnection);
        std::vector<Snack> snacks = snackMapper.getAll();

        for (size_t i = 0; i < snacks.size(); ++i) {
            std::cout << i << ") ";
            snacks[i].print();
        }

        size_t selection;
        std::cout << "Select the index of the drink to change: ";
        std::cin >> selection;

        if (selection < snacks.size()) {
            std::string name, capacity;
            unsigned portionSize;

            std::cout << "Enter new Snack Name: ";
            std::cin >> name;
            std::cout << "Enter new Portion Size: ";
            std::cin >> portionSize;

            Snack snack = Snack(snacks[selection].getId(), name, portionSize);
            snackMapper.save(snack);
            std::cout << "Drink details updated successfully.\n";
        } else {
            std::cout << "Invalid selection.\n";
        }
    } else {
        std::cout << "Invalid choice.\n";
    }
}

void getProductRecipe(DBConnection &dbConnection) {
    int choice;
    std::cout << "1. Get Drink\n2. Get Snack\nEnter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        DrinkMapper drinkMapper(&dbConnection);
        std::vector<Drink> drinks = drinkMapper.getAll();

        for (size_t i = 0; i < drinks.size(); ++i) {
            std::cout << i << ") ";
            drinks[i].print();
        }

        size_t selection;
        std::cout << "Select the index of the drink to change: ";
        std::cin >> selection;

        if (selection < drinks.size()) {
            RecipeMapper recipeMapper(&dbConnection);
            std::vector<Recipe> recipeList = recipeMapper.getByPositionId(Recipe::DRINK, drinks[selection].getId());
            if (recipeList.empty()) {
                std::cout << "No recipes found" << std::endl;
            } else {
                for (auto &i : recipeList) {
                    i.print();
                }
            }
        } else {
            std::cout << "Invalid selection.\n";
        }
    } else if (choice == 2) {
        SnackMapper snackMapper(&dbConnection);
        std::vector<Snack> snacks = snackMapper.getAll();

        for (size_t i = 0; i < snacks.size(); ++i) {
            std::cout << i << ") ";
            snacks[i].print();
        }

        size_t selection;
        std::cout << "Select the index of the drink to change: ";
        std::cin >> selection;

        if (selection < snacks.size()) {
            RecipeMapper recipeMapper(&dbConnection);
            std::vector<Recipe> recipeList = recipeMapper.getByPositionId(Recipe::SNACK, snacks[selection].getId());
            if (recipeList.empty()) {
                std::cout << "No recipes found" << std::endl;
            } else {
                for (auto &i : recipeList) {
                    i.print();
                }
            }
        } else {
            std::cout << "Invalid selection.\n";
        }
    } else {
        std::cout << "Invalid choice.\n";
    }
}
