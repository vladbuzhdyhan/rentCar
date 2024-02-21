#include <iostream>
#include "Rent.h"

int Rent::_amountOfRecords = 0;

Rent::Rent(Car rentedCar, Customer customer)
        : Rent{rentedCar, customer, 1} {}

Rent::Rent(Car rentedCar, Customer customer, int amountOfDays)
        : _rentedCar{rentedCar}, _customer{customer}, _amountOfDays{amountOfDays} { _amountOfRecords++; }

Rent::Rent(const Rent &other)
        : _rentedCar{other._rentedCar}, _customer{other._customer},
          _amountOfDays{other._amountOfDays} { _amountOfRecords++; }

Rent::Rent(Rent &&other) noexcept
        : _rentedCar{other._rentedCar}, _customer{other._customer},
          _amountOfDays{other._amountOfDays} { _amountOfRecords++; }

int Rent::getTheIncome() const { return _amountOfDays * _rentedCar.getPriceForADay(); }

const Car &Rent::getRentedCar() const { return _rentedCar; }

const Customer &Rent::getCustomer() const { return _customer; }

int Rent::getAmountOfDays() const { return _amountOfDays; }

std::ostream &operator<<(std::ostream &os, const Rent &rent) {
    os << "--------------------\n";
    os << "Customer: " << rent._customer.getName() + ' ' + rent._customer.getSurname() << std::endl;
    os << "Car model: " << rent._rentedCar.getModel() << std::endl;
    os << "Price for a day: " << rent._rentedCar.getPriceForADay() << std::endl;
    os << "Amount of days: " << rent._amountOfDays << std::endl;
    os << "Income: " << rent.getTheIncome() << std::endl;
    os << "--------------------\n";
    return os;
}

Rent::~Rent() {
    _amountOfRecords--;
}