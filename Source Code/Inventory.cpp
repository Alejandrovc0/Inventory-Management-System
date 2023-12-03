#include "Inventory.h"
#include <algorithm>
#include <iostream>

using namespace std;

void Inventory::addItem(const Item &item)
{
    items.push_back(item);
}

void Inventory::removeItem(const string &itemName)
{
    auto item = remove_if(items.begin(), items.end(), [itemName](const Item &item)
                          { return item.getName() == itemName; });

    items.erase(item, items.end());
}

void Inventory::updateItem(const string &itemName, const Item &updatedItem)
{
    auto item = find_if(items.begin(), items.end(), [itemName](const Item &item)
                        { return item.getName() == itemName; });

    if (item != items.end())
    {
        *item = updatedItem;
    }
}

void Inventory::displayInventory() const
{
    cout << "Inventory: " << endl;
    for (const auto &item : items)
    {
        item.displayItem();
    }
}

const Item *Inventory::searchItem(const string &itemName) const
{
    auto item = find_if(items.begin(), items.end(), [itemName](const Item &item)
                        { return item.getName() == itemName; });

    if (item != items.end())
    {
        return &(*item);
    }

    return nullptr;
}