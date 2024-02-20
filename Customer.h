#ifndef RENTCAR_CUSTOMER_H
#define RENTCAR_CUSTOMER_H

#include <string>

class Customer {
    std::string _name;
    std::string _surname;
public:
    Customer(std::string name, std::string surname);

    std::string &getName();

    std::string &getSurname();

    void printInfo();
};

#endif //RENTCAR_CUSTOMER_H
