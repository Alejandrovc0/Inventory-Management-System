#include "user_declaration.h"
#include <iostream>
#include <string>

int userMenu(bool &login)
{
    int choice;
    std::string name, username, password;
    int verificationCode;
    User user;
    Accounts accounts;
    Inventory inventory;

    while (login == false)
    {
        std::cout << std::endl;
        std::cout << "1. Register" << std::endl;
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {
            case 1:
                userRegister(user, accounts, name, username, password, verificationCode);
                break;
            case 2:
                userLogin(user, accounts, inventory, username, password);
                break;
            case 3:
                std::cout << "Exiting..." << std::endl;
                exit(-1);
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    }
    return 0;
}

void userRegister(User &user, Accounts &accounts, std::string &name, std::string &username, std::string &password, int verificationCode)
{
    std::cout << "\t\tSign up" << std::endl;
    std::cout << "Name: " << std::endl;
    getline(std::cin, name);
    std::cout << "Username: " << std::endl;
    std::cin >> username;
    std::cout << "Password: " << std::endl;
    std::cin >> password;
    std::cout << std::endl;

    User newUser(name, username, password, verificationCode);
    accounts.registerUser(newUser);
}

void userLogin(User &user, Accounts &accounts, Inventory &inventory, std::string &username, std::string &password)
{
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;
    std::cout << std::endl;
    accounts.login(user, username, password);
    Inventory &inventory = user.getInventory();
}

void changePassword()
{

}

void recoverPassword()
{

}

void recoverUsername()
{

}

void updateUserInfo()
{

}

void deleteUser()
{

}


