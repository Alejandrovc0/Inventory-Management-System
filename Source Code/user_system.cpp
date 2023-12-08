#include "user_declaration.h"
#include <iostream>
#include <string>

void userMenu(User &user, Accounts &accounts, Inventory &inventory, bool &login)
{
    int choice;
    std::string name, username, password;
    int verificationCode;

    while (login == false)
    {
        std::cout << std::endl;
        std::cout << "1. Sign up" << std::endl;
        std::cout << "Already have an account?" << std::endl;
        std::cout << "2. Log in" << std::endl;
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
                userLogin(user, accounts, inventory, username, password, login);
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
}

void userRegister(User &user, Accounts &accounts, std::string &name, std::string &username, std::string &password, int verificationCode)
{
    std::cout << "\t\tSign up" << std::endl;
    std::cout << "Name: " << std::endl;
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << "Username: " << std::endl;
    std::cin >> username;
    std::cout << "Password: " << std::endl;
    std::cin >> password;
    std::cout << std::endl;
    std::cout << "Verification code: " << std::endl;
    std::cin >> verificationCode;

    user = User(name, username, password, verificationCode);
    accounts.addUser(user);
}

void userLogin(User &user, Accounts &accounts, Inventory &inventory, std::string &username, std::string &password, bool &login)
{
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;
    std::cout << std::endl;
    accounts.login(user, username, password, login);
    inventory = user.getInventory();
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


