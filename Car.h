#ifndef RENTCAR_CAR_H
#define RENTCAR_CAR_H

#include <string>

class Car {
    std::string _model;
    int _priceForADay;
public:
    Car(std::string model);

    Car(std::string model, int priceForADay);

    std::string &getModel();

    int getPriceForADay();

    void setPriceForADay(int priceForADay);

    void printInfo();
};

#endif //RENTCAR_CAR_H
