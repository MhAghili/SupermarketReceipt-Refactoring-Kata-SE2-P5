#include "ShoppingCart.h"

void addItemQuantity(const Product& product, double quantity);

std::vector<ProductQuantity> ShoppingCart::getItems() const {
    return items;
}

std::map<Product, double> ShoppingCart::getProductQuantities() const {
    return productQuantities;
}

void ShoppingCart::addItem(const Product& product) {
    addItemQuantity(product, 1.0);
}

void ShoppingCart::addItemQuantity(const Product& product, double quantity) {
    items.emplace_back(product, quantity);
    if (productQuantities.find(product) != productQuantities.end()) {
        productQuantities[product] += quantity;
    } else {
        productQuantities[product] = quantity;
    }
}

void ShoppingCart::handleOffers(Receipt& receipt, std::map<Product, Offer> offers, SupermarketCatalog* catalog) {
   for (const auto& item : items) {
        const Product& product = item.getProduct();
        double quantity = item.getQuantity();
        if (offers.count(product) > 0) {
            const Offer& offer = offers.at(product);
            double unitPrice = catalog->getUnitPrice(product);
            int requiredQuantity = offer.getRequiredQuantity();

            if (quantity >= requiredQuantity) {
                double discountAmount = offer.calculateDiscount(quantity, unitPrice);
                Discount discount(offer.getDescription(), -discountAmount, product);
                receipt.addDiscount(discount);
            }
        }
    }
}
