#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include "User.h"
#include <vector>


class Inventory
{
    private:
        std::vector<Item> items;

    public:
        void addItem(const Item &newItem);
        void removeItem(const std::string &itemName);
        void updateItem(const std::string &itemName, const Item &updatedItem);
        void displayInventory() const;
        const Item *searchItem(const std::string &itemName) const;
        void saveInventoryInfo(const User &user);
        void overwriteInventory(const std::vector<Item>& newItems);
        bool isEmpty() const;
};

#endif