#ifndef CPP_PRODUCTQUANTITY_H
#define CPP_PRODUCTQUANTITY_H


#include "Product.h"

class ProductQuantity {

public:
    ProductQuantity(const Product& product, double quantity);

    Product getProduct() const;

    double getQuantity() const;

private:
    Product product;
    double quantity;

};

ProductQuantity::ProductQuantity(const Product& product, double quantity)
    : product(product), quantity(quantity) {}

Product ProductQuantity::getProduct() const {
    return product;
}

double ProductQuantity::getQuantity() const {
    return quantity;
}

#endif //CPP_PRODUCTQUANTITY_H
