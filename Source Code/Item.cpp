#include "Item.h"
#include <iostream>

Item::Item()
{
    serialNumber = 0;
    quantity = 0;
    price = 0.0;
}

Item::Item(int serialNumber, const std::string &name, int quantity, double price)
    : serialNumber(serialNumber), name(name), quantity(quantity), price(price) {}

int Item::getSerialNumber() const
{
    return serialNumber;
}

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

void Item::setSerialNumber(int newSerialNumber)
{
    serialNumber = newSerialNumber;
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
    std::cout << "Serial number: " << serialNumber << "\tName: " << name << "\tQuantity: " << quantity << "\tPrice: " << price << std::endl;
}