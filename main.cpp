#include "Headers.h"

int menu();
void getItemInfo(User &user, int serialNumber, std::string &name, int quantity, double price);
void removeItem(User &user);
void updateItem(User &user, int serialNumber, std::string &name, int quantity, double price);
void searchItem(User &user);
void save_loadInventory(User &user);
bool returnOption();

// Main function
int main(int argc, const char **argv)
{
    bool login = false; // Flag to check if the user is logged in
    User user;          // User object
    Accounts accounts;  // Accounts object
    Database dataBase;  // Database object
    std::string name;   // Name of the item
    int serialNum = 0;  // Serial number of the item
    int quantity = 0;   // Quantity of the item
    double price = 0.0; // Price of the item

    dataBase.connect(); // Connect to the database

    accounts.loadAccounts(dataBase, accounts); // Load the accounts from the database

    userMenu(dataBase, user, accounts, login); // Display the user menu

    if (login) // If the user is logged in, display the inventory management system
    {
        Inventory inventory;                 // Inventory object
        inventory = user.getInventory(user); // Get the user's inventory
        std::cout << std::endl
                  << "Welcome to the Inventory Management System " << user.getName() << "!" << std::endl;

        while (true) // Display the inventory management system menu
        {
            int choice = menu(); // Get the user's choice

            switch (choice) // Perform the corresponding action based on the user's choice
            {
            case 1: // Add an item to the inventory
            {
                getItemInfo(user, serialNum, name, quantity, price);
                break;
            }
            case 2: // Remove an item from the inventory
            {
                removeItem(user);
                break;
            }
            case 3: // Update an item in the inventory
            {
                updateItem(user, serialNum, name, quantity, price);
                break;
            }
            case 4: // Display the inventory
            {
                inventory.displayInventory();
                break;
            }
            case 5: // Search for an item in the inventory
            {
                searchItem(user);
                break;
            }
            case 6: // Save/Load inventory from file
            {
                save_loadInventory(user);
                break;
            }
            case 7: // Log out
            {
                std::cout << "Exiting..." << std::endl;
                accounts.logout();
                dataBase.disconnect();
                break;
            }
            default: // Invalid choice
                std::cout << "Invalid choice!" << std::endl;
                break;
            }
            if (!returnOption()) // Check if the user wants to return to the main menu
            {
                break;
            }
        }
    }

    dataBase.disconnect(); // Disconnect from the database
    return 0;
}

// Function to display the menu and get the user's choice
int menu()
{
    int usrChoice; // User's choice

    // Display the menu
    std::cout << "Menu" << std::endl;
    std::cout << "1. Add an item to the inventory" << std::endl;
    std::cout << "2. Remove an item from the inventory" << std::endl;
    std::cout << "3. Update an item in the inventory" << std::endl;
    std::cout << "4. Display the inventory" << std::endl;
    std::cout << "5. Search for an item in the inventory" << std::endl;
    std::cout << "6. Save/Load inventory from file" << std::endl;
    std::cout << "7. Log out" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> usrChoice; // Get the user's choice

    return usrChoice; // Return the user's choice
}

// Function to get the item information from the user
void getItemInfo(User &user, int serialNumber, std::string &name, int quantity, double price)
{
    bool valid = false; // Flag to check if the input is valid
    char choice;        // User's choice

    // Get the item information from the user
    while (!valid)
    {
        std::cout << "Enter the serial number of the item: ";
        std::cin >> serialNumber;
        if (serialNumber < 1000) // Check if the serial number is valid
        {
            std::cout << "Invalid serial number." << std::endl;
            continue;
        }
        std::cout << "Enter the name of the item: ";
        std::cin >> name;
        try // Try to convert the name to a double
        {
            std::stod(name);
            std::cout << "Invalid name." << std::endl;
            continue;
        }
        catch (std::invalid_argument) // Catch invalid argument exception
        {
            // Do nothing
        }
        std::cout << "Enter the quantity of the item: ";
        std::cin >> quantity;
        if (quantity <= 0) // Check if the quantity is valid
        {
            std::cout << "Invalid quantity." << std::endl;
            continue;
        }
        std::cout << "Enter the price of the item: ";
        std::cin >> price;
        if (price <= 0) // Check if the price is valid
        {
            std::cout << "Invalid price." << std::endl;
            continue;
        }

        Item newItem(serialNumber, name, quantity, price); // Create a new item

        user.addItemToInventory(newItem); // Add the new item to the inventory
        user.displayInventoryFromInventory(); // Display the inventory

        // Ask the user if they want to add another item
        std::cout << "Do you want to add another item? (y/n): ";
        std::cin >> choice; 
        choice = tolower(choice); // Convert the choice to lowercase

        if (choice == 'n') // If the user does not want to add another item, set the flag to true
        {
            valid = true;
        }
        else if (choice != 'y' && choice != 'n') // If the user enters an invalid choice, display an error message
        {
            std::cout << "Invalid choice." << std::endl;
        }
    }
}

// Function to remove an item from the inventory
void removeItem(User &user)
{
    bool valid = false; // Flag to check if the input is valid
    int choice;        // User's choice
    int serialNumber; // Serial number of the item

    // Remove the item from the inventory based on the serial number
    while (!valid)
    {
        std::cout << "Enter the serial number of the item you want to remove: ";
        std::cin >> serialNumber;
        try // Try to remove the item from the inventory
        {
            user.removeItemFromInventory(serialNumber);
        }
        catch (std::invalid_argument) // Catch invalid argument exception
        {
            std::cout << "Invalid serial number. Item not found" << std::endl;
            continue;
        }

        user.displayInventoryFromInventory(); // Display the inventory

        // Ask the user if they want to remove another item
        std::cout << "Do you want to remove another item? (y/n): "; 
        std::cin >> choice;
        choice = tolower(choice);

        if (choice == 'n') // If the user does not want to remove another item, set the flag to true
        {
            valid = true;
        }
        else if (choice != 'y' && choice != 'n') // If the user enters an invalid choice, display an error message
        {
            std::cout << "Invalid choice." << std::endl;
        }
    }
}

// Function to update an item in the inventory
void updateItem(User &user, int serialNumber, std::string &name, int quantity, double price)
{
    bool valid = false; // Flag to check if the input is valid
    int choice;       // User's choice

    // Update the item in the inventory
    while (!valid)
    {
        std::cout << "Enter the name of the item you want to update: ";
        std::cin >> name;
        try // Try to convert the name to a double
        {
            std::stod(name);
            std::cout << "Invalid name." << std::endl;
            continue;
        }
        catch (std::invalid_argument) // Catch invalid argument exception
        {
            // Do nothing
        }
        std::cout << "Enter the new quantity of the item: ";
        std::cin >> quantity;
        if (quantity <= 0) // Check if the quantity is valid
        {
            std::cout << "Invalid quantity." << std::endl;
            continue;
        }
        std::cout << "Enter the new price of the item: ";
        std::cin >> price;
        if (price <= 0) // Check if the price is valid
        {
            std::cout << "Invalid price." << std::endl;
            continue;
        }

        Item updatedItem(serialNumber, name, quantity, price); // Create an updated item

        user.updatedItemFromInventory(name, updatedItem); // Update the item in the inventory
        user.displayInventoryFromInventory(); // Display the inventory

        // Ask the user if they want to update another item
        std::cout << "Do you want to update another item? (y/n): ";
        std::cin >> choice;
        choice = tolower(choice);

        if (choice == 'n') // If the user does not want to update another item, set the flag to true
        {
            valid = true;
        }
        else if (choice != 'y' && choice != 'n') // If the user enters an invalid choice, display an error message
        {
            std::cout << "Invalid choice." << std::endl;
        }
    }
}

// Function to search for an item in the inventory
void searchItem(User &user)
{
    bool valid = false; // Flag to check if the input is valid
    int choice;      // User's choice
    int serialNumber; // Serial number of the item

    // Search for the item in the inventory based on the serial number
    while (!valid)
    {
        std::cout << "Enter the the serial number of the item you want to search for: ";
        std::cin >> serialNumber;
        if (serialNumber < 1000) // Check if the serial number is valid
        {
            std::cout << "Invalid serial number." << std::endl;
            continue;
        }

        const Item *item = user.searchItemfromInventory(serialNumber); // Search for the item in the inventory

        if (item != nullptr) // If the item is found, display the item
        {
            std::cout << "Item found: " << std::endl;
            item->displayItem();
        }
        else // If the item is not found, display an error message
        {
            std::cout << "Item not found." << std::endl;
        }

        // Ask the user if they want to search for another item
        std::cout << "Do you want to search for another item? (y/n): ";
        std::cin >> choice;
        choice = tolower(choice);

        if (choice == 'n') // If not, set the flag to true
        {
            valid = true;
        }
        else if (choice != 'y' && choice != 'n') // If the user enters an invalid choice, display an error message
        {
            std::cout << "Invalid choice." << std::endl;
        }
    }
}

// Function to save or load the inventory from a file
void save_loadInventory(User &user)
{
    bool valid = false; // Flag to check if the input is valid
    char choice;      // User's choice

    // Ask the user if they want to save or load the inventory
    std::cout << "Do you want to save or load the inventory? (s/l): ";
    std::cin >> choice;
    choice = tolower(choice); // Convert the choice to lowercase

    // Save or load the inventory based on the user's choice
    while (!valid)
    {
        if (choice == 's' && (!user.userInventoryisEmpty())) // If the user wants to save the inventory and it's not empty, save the inventory
        {
            user.saveUserInventoryInfo(user);
            valid = true;
        }
        else if (choice == 's' && (user.userInventoryisEmpty())) // If the user wants to save the inventory and is empty, display an error message
        {
            std::cout << "Inventory is empty. Nothing to save." << std::endl;
            valid = true;
        }
        else if (choice == 'l' && user.userInventoryisEmpty()) // If the user wants to load the inventory and the it's empty, load the inventory
        {
            user.loadUserInventoryInfo(user);
            valid = true;
        }
        else if (choice == 'l' && !user.userInventoryisEmpty()) // If the user wants to load the inventory and it's not empty, ask for confirmation
        {
            int option;
            
            // Ask for confirmation before overwriting the inventory
            std::cout << "Inventory is not empty. Do you want to overwrite it? (y/n): "; 
            std::cin >> option;
            option = tolower(option);

            if (option == 'y') // If the user confirms, overwrite the inventory
            {
                user.overwriteUserInventory();
                valid = true;
            }
            else if (option == 'n') // If the user does not confirm, do not overwrite the inventory
            {
                valid = true;
            }
            else if (option != 'y' && option != 'n') // If the user enters an invalid choice, display an error message
            {
                std::cout << "Invalid choice." << std::endl;
            }
        }
        else if (choice != 's' && choice != 'l') // If the user enters an invalid choice, display an error message
        {
            std::cout << "Invalid choice." << std::endl;
        }
    }
}

// Function to ask the user if they want to return to the main menu
bool returnOption()
{
    char option; // User's choice

    // Ask the user if they want to return to the main menu
    std::cout << "Do you want to return to the main menu? (y/n): ";
    std::cin >> option;
    option = tolower(option);

    if (option == 'y') // If the user wants to return to the main menu, return true
    {
        return true;
    }
    else if (option == 'n') // If the user does not want to return to the main menu, return false
    {
        std::cout << "Exiting...";
        return false;
    }
    else // If the user enters an invalid choice, display an error message
    {
        std::cout << "Invalid choice." << std::endl;
        return false;
    }
}