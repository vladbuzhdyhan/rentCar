#ifndef RENTCAR_CUSTOMER_H
#define RENTCAR_CUSTOMER_H

#include <string>
#include <ostream>

class Customer {
    std::string _name;
    std::string _surname;
public:
    Customer(std::string name, std::string surname);

    Customer(const Customer &other);

    Customer(Customer &&other) noexcept;

    const std::string &getName() const;

    const std::string &getSurname() const;

    friend std::ostream &operator<<(std::ostream &os, const Customer &customer);
};

#endif //RENTCAR_CUSTOMER_H
