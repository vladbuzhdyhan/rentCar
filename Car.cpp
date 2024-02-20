#include <iostream>
#include "Car.h"

Car::Car(std::string model)
        : Car{model, 100} {}

Car::Car(std::string model, int priceForADay)
        : _model{model}, _priceForADay{priceForADay} {}

std::string &Car::getModel() { return _model; }

int Car::getPriceForADay() { return _priceForADay; }

void Car::setPriceForADay(int priceForADay) { _priceForADay = priceForADay; }

void Car::printInfo() {
    std::cout << "Model: " << _model << std::endl;
    std::cout << "Price for a day: " << _priceForADay << std::endl;
}