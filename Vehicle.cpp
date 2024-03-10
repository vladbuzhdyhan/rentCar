#include <iostream>
#include "Vehicle.h"

Vehicle::Vehicle(std::string model) : Vehicle(model, 100) {}

Vehicle::Vehicle(std::string model, int priceForADay) : _model(model), _priceForADay(priceForADay) {}

const std::string &Vehicle::getModel() const { return _model; }

void Vehicle::setPriceForADay(int priceForADay) { _priceForADay = priceForADay; }

void Vehicle::printInfo() {
    std::cout << "Model: " << _model << std::endl;
    std::cout << "Price for a day: " << _priceForADay << std::endl;
}

Vehicle &Vehicle::operator=(const Vehicle &other) {
    _model = other._model;
    _priceForADay = other._priceForADay;
    return *this;
}

Vehicle::~Vehicle() {}