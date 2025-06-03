#include <iostream>
using namespace std;

#include "ItemToPurchase.h" // Include the class definition

// Implementation of the ItemToPurchase class
// Includes:
// Default constructor
// Public class functions (mutators & accessors)
        // SetName() & GetName()
        // SetPrice() & GetPrice()
        // SetQuantity() & GetQuantity()
// Private data members
        // string itemName - Initialized to "none"
        // int itemPrice - Initialized to 0
        // int itemQuantity - Initialized to 0

// Default constructor
// Initializes itemName to "none", itemPrice & itemQuantity to 0
ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

// Setters for item variables itemName, itemPrice & itemQuantity
// Sets the variable to the provided string or value
void ItemToPurchase::SetName(string name) {
    itemName = name;
}

void ItemToPurchase::SetPrice(int price) {
    itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

// Getters for item variables itemName, itemPrice & itemQuantity
// Returns the value of the respective variable
string ItemToPurchase::GetName() const {
    return itemName;
}

int ItemToPurchase::GetPrice() const {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}
