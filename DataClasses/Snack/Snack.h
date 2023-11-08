#ifndef SNACK
#define SNACK

#include <iostream>
#include <string>

class Snack {
    friend class SnackMapper;

public:
    Snack(unsigned id, std::string name, unsigned size_of_portions);
    Snack(std::string name, unsigned size_of_portions);
    ~Snack();

    std::string* getString();
    void print();

private:
    unsigned id;
    std::string name;
    unsigned size_of_portions;
};

#endif  // SNACK
