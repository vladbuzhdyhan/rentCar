#ifndef RENTCAR_RENT_H
#define RENTCAR_RENT_H

#include <ostream>
#include "Customer.h"
#include "Car.h"

class Rent {
    Car _rentedCar;
    Customer _customer;
    int _amountOfDays;
    static int _amountOfRecords;
public:
    Rent(Car rentedCar, Customer customer);

    Rent(Car rentedCar, Customer customer, int amountOfDays);

    Rent(const Rent &other);

    Rent(Rent &&other) noexcept;

    int getTheIncome() const;

    const Car &getRentedCar() const;

    const Customer &getCustomer() const;

    int getAmountOfDays() const;

    friend std::ostream &operator<<(std::ostream &os, const Rent &rent);

    ~Rent();
};

#endif //RENTCAR_RENT_H
