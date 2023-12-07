#include "Inventory.h"
#include "User.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <array>

void Inventory::addItem(const Item &item)
{
    items.push_back(item);
}

void Inventory::removeItem(const int &serialNumber)
{
    auto item = remove_if(items.begin(), items.end(), [serialNumber](const Item &item)
                          { return item.getSerialNumber() == serialNumber; });

    items.erase(item, items.end());
}

void Inventory::updateItem(const std::string &itemName, const Item &updatedItem)
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
    std::cout << "Inventory: " << std::endl;
    for (const auto &item : items)
    {
        item.displayItem();
    }
}

const Item *Inventory::searchItem(const int &serialNumber) const
{
    auto item = find_if(items.begin(), items.end(), [serialNumber](const Item &item)
                        { return item.getSerialNumber() == serialNumber; });

    if (item != items.end())
    {
        return &(*item);
    }

    return nullptr;
}

void Inventory::saveInventoryInfo(const User &user)
{
    std::ofstream inventoryFile;
    inventoryFile.open("C:\\Users\\alejo\\Desktop\\Inventory-Managment-System\\Data\\" + user.getUsername() + "_inventory_data.txt");

    if (inventoryFile.is_open())
    {
        for (const auto &item : items)
        {
            inventoryFile << item.getSerialNumber() << " " << item.getName() << " " << item.getQuantity() << " " << item.getPrice() << std::endl;
        }
        inventoryFile.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
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