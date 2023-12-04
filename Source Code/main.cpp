#include "Item.h"
#include "Inventory.h"
#include <iostream>
#include <cctype>
#include <fstream>


int menu(int choice);
void getItemInfo(Inventory &inventory, string &name, int quantity, double price);
void removeItem(Inventory &inventory, string &name);
void updateItem(Inventory &inventory, string &name, int quantity, double price);
void searchItem(Inventory &inventory, string &name);
void save_loadInventory(Inventory &inventory, string &name, int quantity, double price);
bool returnOption();

int main()
{
    Inventory inventory;
    string name;
    int quantity;
    double price;

    while(true)
    {
        int choice = menu(choice);

        switch (choice)
        {
            case 1:
            {
                getItemInfo(inventory, name, quantity, price);
                break;
            }
            case 2:
            {
                removeItem(inventory, name);
                break;
            }
            case 3:
            {
                updateItem(inventory, name, quantity, price); 
                break;
            }
            case 4:
            {
                inventory.displayInventory();
                break;
            }
            case 5:
            {
                searchItem(inventory, name);
                break;
            }
            case 6:
            {
                save_loadInventory(inventory, name, quantity, price);
                break;
            }
            case 7:
            {
                cout << "Exiting...";
                exit(0);
                break;
            }
        }
        if (!returnOption())
        {
            break;
        }
    }

    return 0;
}

int menu(int choice)
{
    std::cout << "Menu" << endl;
    std::cout << "1. Add an item to the inventory" << endl;
    std::cout << "2. Remove an item from the inventory" << endl;
    std::cout << "3. Update an item in the inventory" << endl;
    std::cout << "4. Display the inventory" << endl;
    std::cout << "5. Search for an item in the inventory" << endl;
    std::cout << "6. Save/Load inventory from file" << endl;
    std::cout << "7. Exit" << endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    while (choice < 1 || choice > 7)
    {
        std::cout << "Invalid choice. Please enter a number between 1 and 7: ";
        std::cin >> choice;
    }

    return choice;
}

void getItemInfo(Inventory &inventory, string &name, int quantity, double price)
{
    bool valid = false;
    char choice;

    while (!valid)
    {
        std::cout << "Enter the name of the item: ";
        std::cin >> name;
        std::cout << "Enter the quantity of the item: ";
        std::cin >> quantity;
        std::cout << "Enter the price of the item: ";
        std::cin >> price;

        Item newItem(name, quantity, price);

        inventory.addItem(newItem);
        inventory.displayInventory();

        std::cout << "Do you want to add another item? (y/n): ";
        std::cin >> choice;
        choice = tolower(choice);

        if (choice == 'n')
        {  
            valid = true;
        }
    }
}

void removeItem(Inventory &inventory, string &name)
{
    bool valid = false;
    int choice;

    while (!valid)
    {
        std::cout << "Enter the name of the item you want to remove: ";
        std::cin >> name;

        inventory.removeItem(name);
        inventory.displayInventory();

        std::cout << "Do you want to remove another item? (y/n): ";
        std::cin >> choice;
        choice = tolower(choice);

        if (choice == 'n')
        {
            valid = true;
        }
    }
}

void updateItem(Inventory &inventory, string &name, int quantity, double price)
{
    bool valid = false;
    int choice;

    while (!valid)
    {
        std::cout << "Enter the name of the item you want to update: ";
        std::cin >> name;
        std::cout << "Enter the new quantity of the item: ";
        std::cin >> quantity;
        std::cout << "Enter the new price of the item: ";
        std::cin >> price;

        Item updatedItem(name, quantity, price);

        inventory.updateItem(name, updatedItem);
        inventory.displayInventory();

        std::cout << "Do you want to update another item? (y/n): ";
        std::cin >> choice;
        choice = tolower(choice);

        if (choice == 'n')
        {
            valid = true;
        }
    }
}

void searchItem(Inventory &inventory, string &name)
{
    bool valid = false;
    int choice;

    while (!valid)
    {
        std::cout << "Enter the name of the item you want to search for: ";
        std::cin >> name;

        const Item *item = inventory.searchItem(name);

        if (item != nullptr)
        {
            std::cout << "Item found: " << endl;
            item->displayItem();
        }
        else
        {
            std::cout << "Item not found." << endl;
        }

        std::cout << "Do you want to search for another item? (y/n): ";
        std::cin >> choice;
        choice = tolower(choice);

        if (choice == 'n')
        {
            valid = true;
        }
    }
}

void save_loadInventory(Inventory &inventory, string &name, int quantity, double price)
{
    bool valid = false;
    char choice;
    
    std::cout << "Do you want to save or load the inventory? (s/l): ";
    std::cin >> choice;
    choice = tolower(choice);

    while (!valid)
    {    
        if (choice == 's' && !is_empty(inventory))
        {
            inventory.saveInventoryInfo();
            valid = true;
        }
        else if (choice == 's' && is_empty(inventory))
        {
            std::cout << "Inventory is empty. Nothing to save." << endl;
            valid = true;            
        }
        else if (choice == 'l' && is_empty(inventory))        
        {
            ifstream inventoryFile("C:\\Users\\alejo\\Desktop\\Inventory-Managment-System\\Data\\inventory_data.txt");

            if (inventoryFile.is_open())
            {
                while (inventoryFile >> name >> quantity >> price)
                {
                    Item loadedItem(name, quantity, price);
                    inventory.addItem(loadedItem);
                    cout << "Name: " << name << "\tQuantity: " << quantity << "\tPrice: " << price << endl;
                }

                inventoryFile.close();
                valid = true;
            }
            else
            {
                std::cout << "Unable to open file." << endl;
            }
        }
        else if (choice == 'l' && !is_empty(inventory))
        {
            std::cout << "Inventory is not empty. Do you want to overwrite it? (y/n): ";
            std::cin >> choice;
            choice = tolower(choice);

            if (choice == 'y')
            {
                while (inventoryFile >> name >> quantity >> price)
                {
                    Item newItem(name, quantity, price);
                    inventory.addItem(newItem);
                }
            }
            else
            {
                valid = true;
            }
        }
        else if (choice != 's' || choice != 'l')
        {
            std::cout << "Invalid choice." << endl;
        }
    }
}

bool returnOption()
{
    char option;

    std::cout << "Do you want to return to the main menu? (y/n): ";
    std::cin >> option;
    option = tolower(option);

    if (option == 'y')
    {
        return true;
    }
    else
    {
        cout << "Exiting...";
        return false;
    }
}