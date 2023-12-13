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

void Inventory::loadInventoryInfo(const User &user, int serialNumber, std::string &name, int quantity, double price)
{
    std::ifstream inventoryFile;
    inventoryFile.open("C:\\Users\\alejo\\Desktop\\Inventory-Managment-System\\Data\\" + user.getUsername() + "_inventory_data.txt");

    if (inventoryFile.is_open())
    {
        while (inventoryFile >> serialNumber >> name >> quantity >> price)
        {
            Item loadedItem(serialNumber, name, quantity, price);
            addItem(loadedItem);
            std::cout << "Name: " << name << "\tQuantity: " << quantity << "\tPrice: " << price << std::endl;
        }
        inventoryFile.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }
}

void Inventory::overwriteInventory()
{
    std::ifstream inventoryFile("C:\\Users\\alejo\\Desktop\\Inventory-Managment-System\\Data\\inventory_data.txt");

    if (!inventoryFile.is_open())
    {
        std::cout << "Error opening file." << std::endl;
        exit(1);
    }

    std::vector<Item> newItems;
    int serialNumber;
    std::string name;
    int quantity;
    double price;

    while (inventoryFile >> serialNumber >> name >> quantity >> price)
    {
        Item loadedItem(serialNumber, name, quantity, price);
        newItems.push_back(loadedItem);
    }
    items = newItems;
}

bool Inventory::isEmpty() const
{
    return items.empty();
}