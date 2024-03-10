#ifndef RENTCAR_CAR_H
#define RENTCAR_CAR_H

#include <string>
#include "Vehicle.h"

class Car : public Vehicle{
    int _wheelDiameter;
public:
    Car(std::string model, int wheelDiameter);

    Car(std::string model, int priceForADay, int wheelDiameter);

    int getPriceForADay() const final;

    void printInfo() final;

    int getWheelDiameter() const;

    Car &operator=(const Car &other);

    ~Car() override;
};

#endif //RENTCAR_CAR_H
