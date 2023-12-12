#include "Headers.h"

int menu(int choice);
void getItemInfo(User& user, Inventory &inventory, int serialNumber, std::string &name, int quantity, double price);
void removeItem(Inventory &inventory);
void updateItem(Inventory &inventory, int serialNumber, std::string &name, int quantity, double price);
void searchItem(Inventory &inventory);
void save_loadInventory(User &user, Inventory &inventory, int serialNumber, std::string &name, int quantity, double price);
bool returnOption();

int main()
{
    bool login = false;
    User user;
    Accounts accounts;
    Inventory inventory;
    std::string name;
    int serialNum, quantity;
    double price;

    accounts.loadAccounts();
    userMenu(user, accounts, inventory, login);

    if (login)
    {
        std::cout << std::endl << "Welcome to the Inventory Management System " << user.getName() << "!" << std::endl;
    
        while(true)
        {
            int choice = menu(choice);

            switch (choice)
            {
                case 1:
                {
                    getItemInfo(user, inventory, serialNum, name, quantity, price);
                    break;
                }
                case 2:
                {
                    removeItem(inventory);
                    break;
                }
                case 3:
                {
                    updateItem(inventory, serialNum, name, quantity, price); 
                    break;
                }
                case 4:
                {
                    inventory.displayInventory();
                    break;
                }
                case 5:
                {
                    searchItem(inventory);
                    break;
                }
                case 6:
                {
                    save_loadInventory(user, inventory, serialNum, name, quantity, price);
                    break;
                }
                case 7:
                {
                    std::cout << "Exiting...";
                    exit(0);
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

int menu(int choice)
{
    std::cout << "Menu" << std::endl;
    std::cout << "1. Add an item to the inventory" << std::endl;
    std::cout << "2. Remove an item from the inventory" << std::endl;
    std::cout << "3. Update an item in the inventory" << std::endl;
    std::cout << "4. Display the inventory" << std::endl;
    std::cout << "5. Search for an item in the inventory" << std::endl;
    std::cout << "6. Save/Load inventory from file" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    return choice;
}

void getItemInfo(User& user, Inventory &inventory, int serialNumber, std::string &name, int quantity, double price)
{
    bool valid = false;
    char choice;

    while (!valid)
    {
        std::cout << "Enter the serial number of the item: ";
        std::cin >> serialNumber;
        std::cout << "Enter the name of the item: ";
        std::cin >> name;
        std::cout << "Enter the quantity of the item: ";
        std::cin >> quantity;
        std::cout << "Enter the price of the item: ";
        std::cin >> price;

        Item newItem(serialNumber, name, quantity, price);

        user.addItemToInventory(inventory, newItem);
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

void removeItem(Inventory &inventory)
{
    bool valid = false;
    int choice;
    int serialNumber;

    while (!valid)
    {
        std::cout << "Enter the serial number of the item you want to remove: ";
        std::cin >> serialNumber;

        inventory.removeItem(serialNumber);
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

void updateItem(Inventory &inventory, int serialNumber, std::string &name, int quantity, double price)
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

        Item updatedItem(serialNumber, name, quantity, price);

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

void searchItem(Inventory &inventory)
{
    bool valid = false;
    int choice;
    int serialNumber;

    while (!valid)
    {
        std::cout << "Enter the name of the item you want to search for: ";
        std::cin >> serialNumber;

        const Item *item = inventory.searchItem(serialNumber);

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

void save_loadInventory(User &user, Inventory &inventory, int serialNumber, std::string &name, int quantity, double price)
{
    bool valid = false;
    char choice;
    
    std::cout << "Do you want to save or load the inventory? (s/l): ";
    std::cin >> choice;
    choice = tolower(choice);

    while (!valid)
    {    
        if (choice == 's' && (!inventory.isEmpty()))
        {
            inventory.saveInventoryInfo(user);
            valid = true;
        }
        else if (choice == 's' && (inventory.isEmpty()))
        {
            std::cout << "Inventory is empty. Nothing to save." << std::endl;
            valid = true;            
        }
        else if (choice == 'l' && inventory.isEmpty())        
        {
            std::ifstream inventoryFile("C:\\Users\\alejo\\Desktop\\Inventory-Managment-System\\Data\\" + user.getUsername() + "_inventory_data.txt");

            if (inventoryFile.is_open())
            {
                while (inventoryFile >> serialNumber >> name >> quantity >> price)
                {
                    Item loadedItem(serialNumber, name, quantity, price);
                    inventory.addItem(loadedItem);
                    std::cout << "Name: " << name << "\tQuantity: " << quantity << "\tPrice: " << price << std::endl;
                }

                inventoryFile.close();
                valid = true;
            }
            else
            {
                std::cout << "Unable to open file." << std::endl;
            }
        }
        else if (choice == 'l' && !inventory.isEmpty())
        {
            int option;

            std::cout << "Inventory is not empty. Do you want to overwrite it? (y/n): ";
            std::cin >> option;
            option = tolower(option);
            
            if (option == 'y')
            {
                std::ifstream inventoryFile("C:\\Users\\alejo\\Desktop\\Inventory-Managment-System\\Data\\inventory_data.txt");

                std::vector<Item> newItems;
                while (inventoryFile >> serialNumber >> name >> quantity >> price)
                {
                    Item loadedItem(serialNumber, name, quantity, price);
                    newItems.push_back(loadedItem);
                    inventory.overwriteInventory(newItems);
                    
                }
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