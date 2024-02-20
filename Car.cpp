#include <iostream>
#include "Car.h"

int Car::_amountOfCars = 0;

Car::Car(std::string model)
        : Car{model, 100} {}

Car::Car(std::string model, int priceForADay)
        : _model{model}, _priceForADay{priceForADay} { _amountOfCars++; }

Car::Car(const Car &other)
        : _model{other._model}, _priceForADay(other._priceForADay) { _amountOfCars++; }

Car::Car(Car &&other) noexcept
        : _model(other._model), _priceForADay(other._priceForADay) { _amountOfCars++; }

const std::string &Car::getModel() const { return _model; }

int Car::getPriceForADay() const { return _priceForADay; }

void Car::setPriceForADay(int priceForADay) { _priceForADay = priceForADay; }

int Car::getAmountOfCars() { return _amountOfCars; }

Car Car::operator+(int num) {
    _priceForADay += num;
    return *this;
}

Car Car::operator-(int num) {
    _priceForADay -= num;
    return *this;
}

Car Car::operator+=(int num) {
    _priceForADay += num;
    return *this;
}

Car Car::operator-=(int num) {
    _priceForADay -= num;
    return *this;
}

Car &Car::operator=(const Car &other) {
    _priceForADay = other._priceForADay;
    _model = other._model;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Car &car) {
    os << "Model: " << car._model << std::endl;
    os << "Price for a day: " << car._priceForADay << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Car &car) {
    is >> car._priceForADay;
    return is;
}

Car::~Car() {
    _amountOfCars--;
}