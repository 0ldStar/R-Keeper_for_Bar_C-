#ifndef BANKDETAILS_H
#define BANKDETAILS_H

#include <iostream>
#include <string>

class BankDetails {
public:
    BankDetails(unsigned id, unsigned supplierId, std::string name, std::string city, std::string TIN, std::string settlementAccount);
    BankDetails(unsigned supplierId, std::string name, std::string city, std::string TIN, std::string settlementAccount);
    ~BankDetails();

    std::string* getString();
    void print();
    unsigned getId() const;
    unsigned getSupplierId() const;
    std::string getName() const;
    std::string getCity() const;
    std::string getTIN() const;
    std::string getSettlementAccount() const;

private:
    unsigned id;
    unsigned supplierId;
    std::string name;
    std::string city;
    std::string TIN;
    std::string settlementAccount;
};

#endif  // BANKDETAILS_H
