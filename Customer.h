#ifndef RENTCAR_CUSTOMER_H
#define RENTCAR_CUSTOMER_H

#include <string>
#include <ostream>

class Customer {
protected:
    std::string _name;
    std::string _surname;
public:
    Customer(std::string name, std::string surname);

    Customer(const Customer &other);

    Customer(Customer &&other) noexcept;

    const std::string &getName() const;

    const std::string &getSurname() const;

    Customer &operator=(const Customer &other);

    friend std::ostream &operator<<(std::ostream &os, const Customer &customer);

    virtual ~Customer();
};

#endif //RENTCAR_CUSTOMER_H
