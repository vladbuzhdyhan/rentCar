#include <iostream>
#include "Motorcycle.h"

Motorcycle::Motorcycle(std::string model, int horsePower)
        : Motorcycle(model, 100, horsePower) {}

Motorcycle::Motorcycle(std::string model, int priceForADay, int horsePower)
        : Vehicle(model, priceForADay), _horsePower(horsePower) {}

int Motorcycle::getPriceForADay() const { return this->_priceForADay * _horsePower / 20; }

void Motorcycle::printInfo() {
    Vehicle::printInfo();
    std::cout << "Horsepower: " << _horsePower << std::endl;
}

int Motorcycle::getHorsePower() const { return _horsePower; }

Motorcycle &Motorcycle::operator=(const Motorcycle &other) {
    Vehicle::operator=(other);
    _horsePower = other._horsePower;
    return *this;
}

Motorcycle::~Motorcycle() {}