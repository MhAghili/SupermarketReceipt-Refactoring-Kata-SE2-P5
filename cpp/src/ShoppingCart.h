#ifndef CPP_SHOPPINGCART_H
#define CPP_SHOPPINGCART_H


#include <vector>
#include <map>
#include "ProductQuantity.h"
#include "Offer.h"
#include "Receipt.h"
#include "SupermarketCatalog.h"

// ShoppingCart
//Represents a shopping cart that stores the items added by the user.

class ShoppingCart {
public:

     // Get the list of items in the shopping cart.
     //A vector of ProductQuantity objects representing the items.
    std::vector<ProductQuantity> getItems() const;

   // Get the quantities of products in the shopping cart.

     // A map with Product as key and double as the quantity.

    std::map<Product, double> getProductQuantities() const;


    // Add a single item to the shopping cart.
    // product The product to add.

    void addItem(const Product& product);


     //Add a specific quantity of an item to the shopping cart.
    // product The product to add.
   // quantity The quantity of the product to add.

    void addItemQuantity(const Product& product, double quantity);

     // Apply offers to the items in the shopping cart and update the receipt.
     // receipt The receipt object to update with discounts.
     // offers A map of offers to be applied.
   

    void handleOffers(Receipt& receipt, std::map<Product, Offer> offers, SupermarketCatalog* catalog);

private:
    std::vector<ProductQuantity> items;
    std::map<Product, double> productQuantities;
};


#endif //CPP_SHOPPINGCART_H
