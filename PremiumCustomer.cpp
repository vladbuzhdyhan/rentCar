#include "PremiumCustomer.h"

PremiumCustomer::PremiumCustomer(std::string name, std::string surname)
        : PremiumCustomer(name, surname, 5) {}

PremiumCustomer::PremiumCustomer(std::string name, std::string surname, int discountPercentage)
        : Customer(name, surname), _discountPercentage{discountPercentage} {}

PremiumCustomer::PremiumCustomer(const PremiumCustomer &other)
        : Customer(other), _discountPercentage{other._discountPercentage} {}

PremiumCustomer::PremiumCustomer(PremiumCustomer &&other) noexcept
        : Customer(other), _discountPercentage{other._discountPercentage} {}

int PremiumCustomer::getDiscountPercentage() const {
    return _discountPercentage;
}

void PremiumCustomer::setDiscountPercentage(int discountPercentage) {
    _discountPercentage = discountPercentage;
}

PremiumCustomer &PremiumCustomer::operator=(const PremiumCustomer &other) {
    Customer::operator=(other);
    _discountPercentage = other._discountPercentage;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const PremiumCustomer &customer) {
    os << "Customer`s name: " << customer._name + ' ' + customer._surname << std::endl;
    os << "Customer`s discount: " << customer._discountPercentage << std::endl;
    return os;
}

PremiumCustomer::~PremiumCustomer() {

}