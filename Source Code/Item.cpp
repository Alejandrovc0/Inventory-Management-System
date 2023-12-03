#include "Item.h"
#include <iostream>

using namespace std;

Item::Item() : quantity(0), price(0.0) {}

Item::Item(const string &name, int quantity, double price)
{
    this->setName(name);
    this->setQuantity(quantity);
    this->setPrice(price);
};

string Item::getName() const
{
    return name;
}

int Item::getQuantity() const
{
    return quantity;
}

double Item::getPrice() const
{
    return price;
}

void Item::setName(const string &newName)
{
    name = newName;
}

void Item::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}

void Item::setPrice(double newPrice)
{
    price = newPrice;
}

void Item::displayItem() const
{
    cout << "Name: " << name << "\tQuantity: " << quantity << "\tPrice: " << price << endl;
}