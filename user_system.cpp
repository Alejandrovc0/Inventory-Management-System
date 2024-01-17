#include "user_system.h"

#include <iostream>
#include <string>

void userMenu(Database& dataBase, User& user, Accounts& accounts, bool& login)
{
    int choice;
    std::string firstName, lastName, email, username, password;

    int verificationCode = 0;

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
            userSignup(dataBase, user, accounts, firstName, lastName, email, username, password, verificationCode);
            break;
        case 2:
            userLogin(dataBase, user, accounts, username, password, login);
            break;
        case 3:
            changePassword(dataBase, user, accounts);
            break;
        case 4:
            recoverUsername(user, accounts);
            break;
        case 5:
            deleteAccount(dataBase, user, accounts, username, verificationCode);
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

void userSignup(Database& dataBase, User& user, Accounts& accounts, std::string& firstName, std::string& lastName, std::string& email, std::string& username, std::string& password, int verificationCode)
{
    Inventory inventory;
    std::cout << "\t\tSign up" << std::endl;
    std::cout << "First name: " << std::endl;
    std::cin >> firstName;
    std::cout << "Last name: " << std::endl;
    std::cin >> lastName;
    std::cout << "Email: " << std::endl;
    std::cin >> email;
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

    accounts.registerUser(dataBase, user, firstName, lastName, email, username, password, verificationCode, inventory);
}

void userLogin(Database& dataBase, User& user, Accounts& accounts, std::string& username, std::string& password, bool& login)
{
    std::cout << "\t\tLog in" << std::endl;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;
    std::cout << std::endl;
    login = accounts.login(dataBase, user, accounts, username, password);
}

void changePassword(Database& dataBase, User& user, Accounts& accounts)
{
    std::string username;
    int verificationCode;

    std::cout << "\t\tChange password" << std::endl;
    std::cout << "Enter your username: " << std::endl;
    std::cin >> username;
    std::cout << "Enter your verification code: " << std::endl;
    std::cin >> verificationCode;

    if (!accounts.userExist(username, verificationCode))
    {
        std::cout << "Invalid information!" << std::endl;
    }
    else
    {
        std::string newPassword;
        while (true)
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
        accounts.changePassword(dataBase, user, accounts, username, verificationCode, newPassword);
    }
}

void recoverUsername(User& user, Accounts& accounts)
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

void deleteAccount(Database& dataBase, User& user, Accounts& accounts, std::string& username, int verificationCode)
{
    std::cout << "\t\tDelete account" << std::endl;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your verification code: ";
    std::cin >> verificationCode;

    if (!accounts.userExist(username, verificationCode))
    {
        std::cout << "Invalid information!" << std::endl; 
    }
    else
    {
        accounts.deleteUser(dataBase, user, accounts, username, verificationCode);
    }
}


