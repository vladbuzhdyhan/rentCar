#include <iostream>
#include "Customer.h"

Customer::Customer(std::string name, std::string surname)
        : _name{name}, _surname{surname} {}

Customer::Customer(const Customer &other)
        : _name{other._name}, _surname{other._surname} {}

Customer::Customer(Customer &&other) noexcept
        : _name{other._name}, _surname{other._surname} {}

const std::string &Customer::getName() const { return _name; }

const std::string &Customer::getSurname() const { return _surname; }

Customer &Customer::operator=(const Customer &other) {
    _name = other._name;
    _surname = other._surname;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Customer &customer) {
    os << "Customer`s name: " << customer._name + ' ' + customer._surname << std::endl;
    return os;
}

Customer::~Customer() {

}