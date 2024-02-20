#include <iostream>
#include "Rent.h"

Rent::Rent(Car rentedCar, Customer customer)
        : Rent{rentedCar, customer, 1} {}

Rent::Rent(Car rentedCar, Customer customer, int amountOfDays)
        : _rentedCar{rentedCar}, _customer{customer}, _amountOfDays{amountOfDays} {}

int Rent::getTheIncome() { return _amountOfDays * _rentedCar.getPriceForADay(); }

Car &Rent::getRentedCar() { return _rentedCar; }

Customer &Rent::getCustomer() { return _customer; }

int Rent::getAmountOfDays() { return _amountOfDays; }

void Rent::printInfo() {
    std::cout << "--------------------\n";
    std::cout << "Customer: " << _customer.getName() + ' ' + _customer.getSurname() << std::endl;
    std::cout << "Car model: " << _rentedCar.getModel() << std::endl;
    std::cout << "Price for a day: " << _rentedCar.getPriceForADay() << std::endl;
    std::cout << "Amount of days: " << _amountOfDays << std::endl;
    std::cout << "Income: " << _amountOfDays * _rentedCar.getPriceForADay() << std::endl;
    std::cout << "--------------------\n";
}