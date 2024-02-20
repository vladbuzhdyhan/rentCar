#include <iostream>
#include "Customer.h"

Customer::Customer(std::string name, std::string surname)
        : _name{name}, _surname{surname} {}

std::string &Customer::getName() { return _name; }

std::string &Customer::getSurname() { return _surname; }

void Customer::printInfo() {
    std::cout << "Customer`s name: " << _name + ' ' + _surname << std::endl;
}