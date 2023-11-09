#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <iostream>
#include <string>

class Supplier {
   public:
    Supplier(unsigned id, std::string name, std::string postAddress, std::string phoneNumber, std::string faxNumber, std::string email);
    Supplier(std::string name, std::string postAddress, std::string phoneNumber, std::string faxNumber, std::string email);
    ~Supplier();

    std::vector<std::string> getString();
    void print();
    unsigned getId() const;
    std::string getName() const;
    std::string getPostAddress() const;
    std::string getPhoneNumber() const;
    std::string getFaxNumber() const;
    std::string getEmail() const;
    void setPostAddress(const std::string& postAddress);
    void setPhoneNumber(const std::string& phoneNumber);
    void setFaxNumber(const std::string& faxNumber);
    void setEmail(const std::string& email);

   private:
    unsigned id;
    std::string name;
    std::string postAddress;
    std::string phoneNumber;
    std::string faxNumber;
    std::string email;
};

#endif  // SUPPLIER_H
