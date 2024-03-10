#ifndef RENTCAR_MOTORCYCLE_H
#define RENTCAR_MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {
    int _horsePower;
public:
    Motorcycle(std::string model, int horsePower);

    Motorcycle(std::string model, int priceForADay, int horsePower);

    int getPriceForADay() const final;

    void printInfo() final;

    int getHorsePower() const;

    Motorcycle &operator=(const Motorcycle &other);

    ~Motorcycle() override;
};

#endif //RENTCAR_MOTORCYCLE_H
