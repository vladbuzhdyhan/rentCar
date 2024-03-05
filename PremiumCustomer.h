#ifndef RENTCAR_PREMIUMCUSTOMER_H
#define RENTCAR_PREMIUMCUSTOMER_H

#include <ostream>
#include "Customer.h"

class PremiumCustomer : public Customer {
    int _discountPercentage;
public:
    PremiumCustomer(std::string name, std::string surname);

    PremiumCustomer(std::string name, std::string surname, int discountPercentage);

    PremiumCustomer(const PremiumCustomer &other);

    PremiumCustomer(PremiumCustomer &&other) noexcept;

    int getDiscountPercentage() const;

    void setDiscountPercentage(int discountPercentage);

    PremiumCustomer &operator=(const PremiumCustomer &other);

    friend std::ostream &operator<<(std::ostream &os, const PremiumCustomer &customer);

    ~PremiumCustomer() override;
};

#endif //RENTCAR_PREMIUMCUSTOMER_H
