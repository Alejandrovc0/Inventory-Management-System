#include "Headers.h"


int main(int argc, const char **argv)
{
    bool login = false;
    User user;
    Accounts accounts;
    std::string name;
    int serialNum = 0;
    int quantity = 0;
    double price = 0.0;

    accounts.loadAccounts();

    userMenu(user, accounts, login);

    if (login)
    {
        Inventory inventory;
        inventory = user.getInventory(user);
        std::cout << std::endl
                  << "Welcome to the Inventory Management System " << user.getName() << "!" << std::endl;

        while (true)
        {
            int choice = menu();

            switch (choice)
            {
            case 1:
            {
                getItemInfo(user, serialNum, name, quantity, price);
                break;
            }
            case 2:
            {
                removeItem(user);
                break;
            }
            case 3:
            {
                updateItem(user, serialNum, name, quantity, price);
                break;
            }
            case 4:
            {
                inventory.displayInventory();
                break;
            }
            case 5:
            {
                searchItem(user);
                break;
            }
            case 6:
            {
                save_loadInventory(user);
                break;
            }
            case 7:
            {
                std::cout << "Exiting..." << std::endl;
                accounts.logout();
                break;
            }
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
            }
            if (!returnOption())
            {
                break;
            }
        }
    }
    
    return 0;
}

int menu()
{
    int option;
    std::cout << "Menu" << std::endl;
    std::cout << "1. Add an item to the inventory" << std::endl;
    std::cout << "2. Remove an item from the inventory" << std::endl;
    std::cout << "3. Update an item in the inventory" << std::endl;
    std::cout << "4. Display the inventory" << std::endl;
    std::cout << "5. Search for an item in the inventory" << std::endl;
    std::cout << "6. Save/Load inventory from file" << std::endl;
    std::cout << "7. Log out" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> option;

    return option;
}

void getItemInfo(User &user, int serialNumber, std::string &name, int quantity, double price)
{
    bool valid = false;
    char choice;

    while (!valid)
    {
        std::cout << "Enter the serial number of the item: ";
        std::cin >> serialNumber;
        if (serialNumber < 1000)
        {
            std::cout << "Invalid serial number." << std::endl;
            continue;
        }
        std::cout << "Enter the name of the item: ";
        std::cin >> name;
        try
        {
            std::stod(name);
            std::cout << "Invalid name." << std::endl;
            continue;
        }
        catch (std::invalid_argument)
        {
            // Do nothing
        }
        std::cout << "Enter the quantity of the item: ";
        std::cin >> quantity;
        if (quantity <= 0)
        {
            std::cout << "Invalid quantity." << std::endl;
            continue;
        }
        std::cout << "Enter the price of the item: ";
        std::cin >> price;
        if (price <= 0)
        {
            std::cout << "Invalid price." << std::endl;
            continue;
        }

        Item newItem(serialNumber, name, quantity, price);

        user.addItemToInventory(newItem);
        user.displayInventoryFromInventory();

        std::cout << "Do you want to add another item? (y/n): ";
        std::cin >> choice;
        choice = tolower(choice);

        if (choice == 'n')
        {
            valid = true;
        }
        else
        {
            std::cout << "Invalid choice." << std::endl;
        }
    }
}

void removeItem(User &user)
{
    bool valid = false;
    int choice;
    int serialNumber;

    while (!valid)
    {
        std::cout << "Enter the serial number of the item you want to remove: ";
        std::cin >> serialNumber;
        try 
        {
            user.removeItemFromInventory(serialNumber);
        }
        catch (std::invalid_argument)
        {
            std::cout << "Invalid serial number. Item not found" << std::endl;
            continue;
        }

        user.displayInventoryFromInventory();

        std::cout << "Do you want to remove another item? (y/n): ";
        std::cin >> choice;
        choice = tolower(choice);

        if (choice == 'n')
        {
            valid = true;
        }
    }
}

void updateItem(User &user, int serialNumber, std::string &name, int quantity, double price)
{
    bool valid = false;
    int choice;

    while (!valid)
    {
        std::cout << "Enter the name of the item you want to update: ";
        std::cin >> name;
        try
        {
            std::stod(name);
            std::cout << "Invalid name." << std::endl;
            continue;
        }
        catch (std::invalid_argument)
        {
            // Do nothing
        }
        std::cout << "Enter the new quantity of the item: ";
        std::cin >> quantity;
        if (quantity <= 0)
        {
            std::cout << "Invalid quantity." << std::endl;
            continue;
        }
        std::cout << "Enter the new price of the item: ";
        std::cin >> price;
        if (price <= 0)
        {
            std::cout << "Invalid price." << std::endl;
            continue;
        }

        Item updatedItem(serialNumber, name, quantity, price);

        user.updatedItemFromInventory(name, updatedItem);
        user.displayInventoryFromInventory();

        std::cout << "Do you want to update another item? (y/n): ";
        std::cin >> choice;
        choice = tolower(choice);

        if (choice == 'n')
        {
            valid = true;
        }
    }
}

void searchItem(User &user)
{
    bool valid = false;
    int choice;
    int serialNumber;

    while (!valid)
    {
        std::cout << "Enter the the serial number of the item you want to search for: ";
        std::cin >> serialNumber;
        if (serialNumber < 1000)
        {
            std::cout << "Invalid serial number." << std::endl;
            continue;
        }

        const Item *item = user.searchItemfromInventory(serialNumber);

        if (item != nullptr)
        {
            std::cout << "Item found: " << std::endl;
            item->displayItem();
        }
        else
        {
            std::cout << "Item not found." << std::endl;
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

void save_loadInventory(User &user)
{
    bool valid = false;
    char choice;

    std::cout << "Do you want to save or load the inventory? (s/l): ";
    std::cin >> choice;
    choice = tolower(choice);

    while (!valid)
    {
        if (choice == 's' && (!user.userInventoryisEmpty()))
        {
            user.saveUserInventoryInfo(user);
            valid = true;
        }
        else if (choice == 's' && (user.userInventoryisEmpty()))
        {
            std::cout << "Inventory is empty. Nothing to save." << std::endl;
            valid = true;
        }
        else if (choice == 'l' && user.userInventoryisEmpty())
        {
            user.loadUserInventoryInfo(user);
            valid = true;
        }
        else if (choice == 'l' && !user.userInventoryisEmpty())
        {
            int option;

            std::cout << "Inventory is not empty. Do you want to overwrite it? (y/n): ";
            std::cin >> option;
            option = tolower(option);

            if (option == 'y')
            {
                user.overwriteUserInventory();
                valid = true;
            }
            else
            {
                valid = true;
            }
        }
        else if (choice != 's' || choice != 'l')
        {
            std::cout << "Invalid choice." << std::endl;
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
        std::cout << "Exiting...";
        return false;
    }
}