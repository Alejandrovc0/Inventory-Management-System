#include "Item.h"
#include "Inventory.h"
#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;

int menu(int choice);
void getItemInfo(string &name, int &quantity, double &price);
void removeItem(string &name);
void updateItem(string &name, int &quantity, double &price);
void searchItem(string &name);
void save_loadInventory();

int main()
{
    Inventory inventory;
    string name;
    int quantity;
    double price;
    int choice = menu(choice);

    switch (choice)
    {
        case 1:
        {
            getItemInfo(name, quantity, price);
            break;
        }
        case 2:
        {
            removeItem(name);
            break;
        }
        case 3:
        {
            updateItem(name, quantity, price);
            break;
        }
        case 4:
        {
            inventory.displayInventory();
            break;
        }
        case 5:
        {
            searchItem(name);
            break;
        }
        case 6:
        {
            save_loadInventory();
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
    cout << "Menu" << endl;
    cout << "1. Add an item to the inventory" << endl;
    cout << "2. Remove an item from the inventory" << endl;
    cout << "3. Update an item in the inventory" << endl;
    cout << "4. Display the inventory" << endl;
    cout << "5. Search for an item in the inventory" << endl;
    cout << "6. Save/Load inventory from file" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice < 1 || choice > 7)
    {
        cout << "Invalid choice. Please enter a number between 1 and 7: ";
        cin >> choice;
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
        cout << "Enter the name of the item: ";
        cin >> name;
        cout << "Enter the quantity of the item: ";
        cin >> quantity;
        cout << "Enter the price of the item: ";
        cin >> price;

        Item newItem(name, quantity, price);

        inventory.addItem(newItem);
        inventory.displayInventory();

        cout << "Do you want to add another item? (y/n): ";
        cin >> choice;
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
        cout << "Enter the name of the item you want to remove: ";
        cin >> name;

        inventory.removeItem(name);
        inventory.displayInventory();

        cout << "Do you want to remove another item? (y/n): ";
        cin >> choice;
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
        cout << "Enter the name of the item you want to update: ";
        cin >> name;
        cout << "Enter the new quantity of the item: ";
        cin >> quantity;
        cout << "Enter the new price of the item: ";
        cin >> price;

        Item updatedItem(name, quantity, price);

        inventory.updateItem(name, updatedItem);
        inventory.displayInventory();

        cout << "Do you want to update another item? (y/n): ";
        cin >> choice;
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
        cout << "Enter the name of the item you want to search for: ";
        cin >> name;

        const Item *item = inventory.searchItem(name);

        if (item != nullptr)
        {
            cout << "Item found: " << endl;
            item->displayItem();
        }
        else
        {
            cout << "Item not found." << endl;
        }

        cout << "Do you want to search for another item? (y/n): ";
        cin >> choice;
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
    int choice;

    cout << "Do you want to save or load the inventory? (s/l): ";
    cin >> choice;
    choice = tolower(choice);

    if (choice == 's')
    {
        inventory.saveInventoryInfo();
    }
    
    else if (choice == 'l')
    {
        ifstream inventoryFile("Data/inventory_data.txt");

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
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
    }
}