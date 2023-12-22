#include "user_declaration.h"
#include "Window.h"

#include <iostream>
#include <string>
#include <fstream>

const int WIDTH = 1920, HEIGHT = 1080;

void userMenu(User& user, Accounts& accounts, bool& login)
{
    int choice;
    std::string name, username, password;
    int verificationCode;

    Window window ("Inventory Management System", WIDTH, HEIGHT);

    while (!login)
    {
        std::cout << std::endl;
        std::cout << "\t\t1. Sign up" << std::endl;
        std::cout << "\t Already have an account?" << std::endl;
        std::cout << "\t\t2. Log in \n" << std::endl;
        std::cout << "3. Change password";
        std::cout << "\t4. Recover username" << std::endl;
        std::cout << "5. Delete account";
        std::cout << "\t6. Exit" << std::endl;
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {
            case 1:
                userSignup(user, accounts, name, username, password, verificationCode);
                break;
            case 2:
                userLogin(user, accounts, username, password, login);
                break;
            case 3:
                changePassword(user, accounts);
                break;
            case 4:
                recoverUsername(user, accounts);
                break;
            case 5:
                deleteAccount(user, accounts, username, verificationCode);
                break;
            case 6:
                std::cout << "Exiting..." << std::endl;
                exit(-1);
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    }
}

void userSignup(User &user, Accounts &accounts, std::string &name, std::string &username, std::string &password, int verificationCode)
{
    Inventory inventory;
    std::cout << "\t\tSign up" << std::endl;
    std::cout << "Name: " << std::endl;
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << "Username: " << std::endl;
    std::cin >> username;
    while (user.getUsername() == username)
    {
        std::cout << "Username already exists!" << std::endl;
        std::cout << "Username: " << std::endl;
        std::cin >> username;
    }
    std::cout << "Password: " << std::endl;
    std::cin >> password;

    while (!accounts.isValidPassword(password))
    {
        std::cout << "Password must be at least 8 characters long and contain at least one uppercase letter, one lowercase letter, and one digit." << std::endl;
        std::cout << "Password: " << std::endl;
        std::cin >> password;
    }

    std::cout << "Verification code: " << std::endl;
    std::cin >> verificationCode;
    std::cout << std::endl;

    accounts.registerUser(user, name, username, password, verificationCode, inventory);
}

void userLogin(User &user, Accounts &accounts, std::string &username, std::string &password, bool &login)
{
    std::cout << "\t\tLog in" << std::endl;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;
    std::cout << std::endl;
    login = accounts.login(user, accounts, username, password);
}

void changePassword(User &user, Accounts &accounts)
{
    std::string username;
    int verificationCode;

    std::cout << "\t\tChange password" << std::endl;
    std::cout << "Enter your username: " << std::endl;
    std::cin >> username;
    std::cout << "Enter your verification code: " << std::endl;
    std::cin >> verificationCode;

    if(!accounts.userExist(username, verificationCode))
    {
        std::cout << "Invalid information!" << std::endl;
    }
    else
    {
        std::string newPassword;
        while(true)
        {
            std::cout << "Enter your new password: " << std::endl;
            std::cin >> newPassword;
            if (!accounts.isValidPassword(newPassword))
            {
                std::cout << "Password must be at least 8 characters long and contain at least one uppercase letter, one lowercase letter, and one digit." << std::endl;
            }
            else
            {
                break;
            }
        }
        accounts.changePassword(user, accounts, username, verificationCode, newPassword);
    }
}

void recoverUsername(User &user, Accounts &accounts)
{
    std::string name;
    int verificationCode;
    
    std::cout << "\t\tRecover username" << std::endl;
    std::cout << "Enter your name: ";
    std::cin >> name;    
    std::cout << "Enter your verification code: ";
    std::cin >> verificationCode;

    accounts.retrieveUsername(user, accounts, name, verificationCode);
}

void deleteAccount(User &user, Accounts &accounts, std::string &username, int verificationCode)
{
    std::cout << "\t\tDelete account" << std::endl;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your verification code: ";
    std::cin >> verificationCode;

    if(!accounts.userExist(username, verificationCode))
    {
        std::cout << "Invalid information!" << std::endl;
    }
    else
    {
        accounts.deleteUser(user, accounts, username, verificationCode);
    }
}


