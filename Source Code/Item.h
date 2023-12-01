#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
private: 
    string name;
    int quantity;
    double price;

public:
    Item();
    Item(string name, int quantity, double price);

    string getName();
    int getQuantity();
    double getPrice();

    void setName(string name);
    void setQuantity(int quantity);
    void setPrice(double price);

    void displayItem();
};

#endif