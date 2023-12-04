#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>

class Inventory
{
    private:
        vector<Item> items;

    public:
        void addItem(const Item &newItem);
        void removeItem(const string &itemName);
        void updateItem(const string &itemName, const Item &updatedItem);
        void displayInventory() const;
        const Item *searchItem(const string &itemName) const;
        void saveInventoryInfo() const;
        void overwriteInventory(const std::vector<Item>& newItems);
        bool isEmpty() const;
};

#endif