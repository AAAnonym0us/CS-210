#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

// Declare ItemToPurchase class
class ItemToPurchase {

private: // private data members
    string itemName; // Holds item name
    int itemPrice; // Holds item price
    int itemQuantity; // Holds item quantity

public: // public class functions
    ItemToPurchase(); // Default constructor

    // Setters and Getters for item variables
    void SetName(string name);
    string GetName() const;
    void SetPrice(int price);
    int GetPrice() const;
    void SetQuantity(int quantity);
    int GetQuantity() const;
};

#endif