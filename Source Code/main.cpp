#include "Item.h"
#include "Inventory.h"
#include <iostream>
#include <cctype>
#include <fstream>


int menu(int choice);
void getItemInfo(string &name, int &quantity, double &price);
void removeItem(string &name);
void updateItem(string &name, int &quantity, double &price);
void searchItem(string &name);
void save_loadInventory();
void returnOption();

int main()
{
    Inventory inventory;
    string name;
    int quantity;
    double price;
    int choice = menu(choice);
    bool valid = false;

    switch (choice)
    {
        case 1:
        {
            getItemInfo(name, quantity, price);
            returnOption();
            break;
        }
        case 2:
        {
            removeItem(name);
            returnOption();
            break;
        }
        case 3:
        {
            updateItem(name, quantity, price); 
            returnOption();
            break;
        }
        case 4:
        {
            inventory.displayInventory();
            returnOption();
            break;

        }
        case 5:
        {
            searchItem(name);
            returnOption();
            break;
        }
        case 6:
        {
            save_loadInventory();
            returnOption();
            break;
        }
        case 7:
        {
            exit(0);
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

void getItemInfo(string &name, int &quantity, double &price)
{
    Inventory inventory;
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

void removeItem(string &name)
{
    Inventory inventory;
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

void updateItem(string &name, int &quantity, double &price)
{
    Inventory inventory;
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

void searchItem(string &name)
{
    Inventory inventory;
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

void save_loadInventory()
{
    Inventory inventory;
    bool valid = false;
    char choice;

    std::cout << "Do you want to save or load the inventory? (s/l): ";
    std::cin >> choice;
    choice = tolower(choice);
    inventory.displayInventory();
    while (!valid)
    {    
        if (choice == 's')
        {
            inventory.saveInventoryInfo();
            valid = true;
        }

        else if (choice == 'l')
        {
            ifstream inventoryFile("C:\\Users\\alejo\\Desktop\\Inventory-Managment-System\\Data\\inventory_data.txt");

            if (inventoryFile.is_open())
            {
                string name;
                int quantity;
                double price;

                while (inventoryFile >> name >> quantity >> price)
                {
                    Item newItem(name, quantity, price);
                    inventory.addItem(newItem);
                }

                inventoryFile.close();
                inventory.displayInventory();
                valid = true;
            }
            else
            {
                std::cout << "Unable to open file." << endl;
            }
        }
        else if (choice != 's' || choice != 'l')
        {
            std::cout << "Invalid choice." << endl;
        }
    }
}

void returnOption()
{
    char option;

    std::cout << "Do you want to return to the main menu? (y/n): ";
    std::cin >> option;
    option = tolower(option);

    if (option == 'y')
    {
        main();
    }
    else
    {
        exit(0);
    }
}