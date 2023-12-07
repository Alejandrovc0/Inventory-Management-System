#include "Item.h"
#include <iostream>

Item::Item()
{
    quantity = 0;
    price = 0.0;
}

Item::Item(const std::string &name, int quantity, double price)
    : name(name), quantity(quantity), price(price) {}

std::string Item::getName() const
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

void Item::setName(const std::string &newName)
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
    std::cout << "Name: " << name << "\tQuantity: " << quantity << "\tPrice: " << price << std::endl;
}