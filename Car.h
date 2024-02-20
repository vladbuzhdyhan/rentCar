#ifndef RENTCAR_CAR_H
#define RENTCAR_CAR_H

#include <string>

class Car {
    std::string _model;
    int _priceForADay;
    static int _amountOfCars;
public:
    Car(std::string model);

    Car(std::string model, int priceForADay);

    Car(const Car &other);

    Car(Car &&other) noexcept;

    const std::string &getModel() const;

    int getPriceForADay() const;

    void setPriceForADay(int priceForADay);

    static int getAmountOfCars();

    Car operator+(int num);

    Car operator-(int num);

    Car operator+=(int num);

    Car operator-=(int num);

    Car &operator=(const Car &other);

    friend std::ostream &operator<<(std::ostream &os, const Car &car);

    friend std::istream &operator>>(std::istream &is, Car &car);

    ~Car();
};

#endif //RENTCAR_CAR_H
