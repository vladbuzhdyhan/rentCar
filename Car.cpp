#include <iostream>
#include "Car.h"

Car::Car(std::string model, int wheelDiameter)
        : Car(model, 100, wheelDiameter) {}

Car::Car(std::string model, int priceForADay, int wheelDiameter)
        : Vehicle(model, priceForADay), _wheelDiameter{wheelDiameter} {}

int Car::getPriceForADay() const { return this->_priceForADay * _wheelDiameter / 2; }

void Car::printInfo() {
    Vehicle::printInfo();
    std::cout << "Wheel diameter: " << _wheelDiameter << std::endl;
}

int Car::getWheelDiameter() const { return _wheelDiameter; }

Car &Car::operator=(const Car &other) {
    Vehicle::operator=(other);
    _wheelDiameter = other._wheelDiameter;
    return *this;
}

Car::~Car() {}