#include "Item.h"
#include <iostream>

using namespace std;

Item::Item() : quantity(0), price(0.0) {}

Item::Item(string name, int quantity, double price)
    : name(name), quantity(quantity), price(price) {}