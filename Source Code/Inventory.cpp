#include "Inventory.h"
#include "User.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <array>

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

void Inventory::saveInventoryInfo(const User &user)
{
    ofstream inventoryFile;
    inventoryFile.open("C:\\Users\\alejo\\Desktop\\Inventory-Managment-System\\Data\\" + user.getUsername() + "_inventory_data.txt");

    if (inventoryFile.is_open())
    {
        for (const auto &item : items)
        {
            inventoryFile << item.getName() << " " << item.getQuantity() << " " << item.getPrice() << endl;
        }
        inventoryFile.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}

void Inventory::overwriteInventory(const std::vector<Item>& newItems) 
{
    items = newItems;
}

bool Inventory::isEmpty() const 
{
    return items.empty();
}