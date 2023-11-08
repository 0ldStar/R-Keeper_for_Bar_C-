#ifndef DRINK
#define DRINK

#include <iostream>
#include <string>

class Drink {
    friend class DrinkMapper;

   public:
    Drink(unsigned id, std::string name, unsigned portion_size, std::string capacity);
    Drink(std::string name, unsigned portion_size, std::string capacity);
    ~Drink();

    std::string* getString();
    void print();

   private:
    unsigned id;
    std::string name;
    unsigned portion_size;
    std::string capacity;
};

#endif  // DRINK
