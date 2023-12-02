#include "Item.h"
#include <iostream>

using namespace std;

Item::Item() : quantity(0), price(0.0) {}

Item::Item(string name, int quantity, double price)
{
    this->setName(name);
    this->setQuantity(quantity);
    this->setPrice(price);
};

string Item::getName()
{
    return name;
}

int Item::getQuantity()
{
    return quantity;
}

double Item::getPrice()
{
    return price;
}

void Item::setName(string& Newname)
{
    name = Newname;
}

void Item::setQuantity(int newQuantity)
{
    quantity = Newquantity;
}

void Item::setPrice(double newPrice)
{
    price = Newprice;
}

void Item::displayItem()
{
    cout << "Name: " << name << "\tQuantity: " << quantity << "\tPrice: " << price << endl;
}