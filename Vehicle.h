#ifndef RENTCAR_VEHICLE_H
#define RENTCAR_VEHICLE_H

#include <string>
#include <ostream>

class Vehicle {
protected:
    std::string _model;
    int _priceForADay;
public:
    Vehicle(std::string model);

    Vehicle(std::string model, int priceForADay);

    const std::string &getModel() const;

    virtual int getPriceForADay() const = 0;

    void setPriceForADay(int priceForADay);

    virtual void printInfo();

    Vehicle &operator=(const Vehicle &other);

    virtual ~Vehicle() = 0;
};

#endif //RENTCAR_VEHICLE_H
