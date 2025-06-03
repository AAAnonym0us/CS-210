#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {

    // Declare two objects of the ItemToPurchase class and store user inputs
    ItemToPurchase userItem1;
    ItemToPurchase userItem2;
    // Declares variables to temporarily hold input values
    string itemName;
    int itemPrice;
    int itemQuantity;

    // Prompt and collect Item 1 information
    cout << "Item 1" << endl;

    cout << "Enter the item name:" << endl;
    getline(cin, itemName); // Enter item 1 name, read full line
    userItem1.SetName(itemName); // Set item name

    cout << "Enter the item price:" << endl;
    cin >> itemPrice; // Enter item 1 price
    userItem1.SetPrice(itemPrice); // Set item price

    cout << "Enter the item quantity:" << endl;
    cin >> itemQuantity; // Enter item 1 quantity
    userItem1.SetQuantity(itemQuantity); // Set item quantity

    // Before prompting for the second item, 
    // call cin.ignore() to allow the user to input a new string.
    cin.ignore();

    // Prompt and collect Item 2 information
    cout << endl << "Item 2" << endl;

    cout << "Enter the item name:" << endl;
    getline(cin, itemName); // Enter item 2 name, read full line
    userItem2.SetName(itemName); // Set item name

    cout << "Enter the item price:" << endl;
    cin >> itemPrice; // Enter item 2 price
    userItem2.SetPrice(itemPrice); // Set item price

    cout << "Enter the item quantity:" << endl;
    cin >> itemQuantity; // Enter item 2 quantity
    userItem2.SetQuantity(itemQuantity); // Set item quantity

    // Output each item information
    cout << endl << "TOTAL COST" << endl;

    // Print desired output for item 1
    cout << userItem1.GetName() << " " << userItem1.GetQuantity()
        << " @ $" << userItem1.GetPrice() << " = $"
        << userItem1.GetQuantity() * userItem1.GetPrice() << endl; // Get total with quantity * price

    // Print desired output for item 2
    cout << userItem2.GetName() << " " << userItem2.GetQuantity()
        << " @ $" << userItem2.GetPrice() << " = $"
        << userItem2.GetQuantity() * userItem2.GetPrice() << endl; // Get total with quantity * price

    // Declare variable to hold total cost
    int totalItemCost = (userItem1.GetQuantity() * userItem1.GetPrice())
        + (userItem2.GetQuantity() * userItem2.GetPrice());

    // Display total cost
    cout << endl << "Total: $" << totalItemCost << endl;

    return 0;
}