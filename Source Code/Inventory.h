#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>


class User;
class Inventory
{
    private:
        std::vector<Item> items;

    public:
        void addItem(const Item &newItem);
        void removeItem(const int &serialNumber);
        void updateItem(const std::string &itemName, const Item &updatedItem);
        void displayInventory() const;
        const Item *searchItem(const int &serialNumber) const;
        void saveInventoryInfo(const User &user);
        void overwriteInventory(const std::vector<Item>& newItems);
        bool isEmpty() const;
};

#endif