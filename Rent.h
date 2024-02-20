#ifndef RENTCAR_RENT_H
#define RENTCAR_RENT_H

#include "Customer.h"
#include "Car.h"

class Rent {
    Car _rentedCar;
    Customer _customer;
    int _amountOfDays;
public:
    Rent(Car rentedCar, Customer customer);

    Rent(Car rentedCar, Customer customer, int amountOfDays);

    int getTheIncome();

    Car &getRentedCar();

    Customer &getCustomer();

    int getAmountOfDays();

    void printInfo();
};

#endif //RENTCAR_RENT_H
