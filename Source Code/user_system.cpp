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
        std::cout << "3. Change password" << std::endl;
        std::cout << "4. Recover username" << std::endl;
        std::cout << "5. Exit" << std::endl;
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
                changePassword(user, accounts);
                break;
            case 4:
                recoverUsername(user, accounts);
                break;
            case 5:
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
    while (!accounts.isValidPassword(password))
    {
        std::cout << "Password must be at least 8 characters long and contain at least one uppercase letter, one lowercase letter, and one digit." << std::endl;
        std::cout << "Password: " << std::endl;
        std::cin >> password;
    }
    std::cout << std::endl;
    std::cout << "Verification code: " << std::endl;
    std::cin >> verificationCode;

    std::string encryptedPasword;
    encryptedPasword = accounts.encryptPassword(password);

    user = User(name, username, encryptedPasword, verificationCode);
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

void changePassword(User &user, Accounts &accounts)
{
    std::string username;
    int verificationCode;

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
        while(false)
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

        accounts.changePassword(user, accounts, verificationCode, newPassword);
    }

}

void recoverUsername(User &user, Accounts &accounts)
{
    std::string username;
    int verificationCode;
    
    std::cout << "Enter your username: ";
    std::cin >> username;    
    std::cout << "Enter your verification code: ";
    std::cin >> verificationCode;

    accounts.retrieveUsername(user, accounts, username, verificationCode);

}

void deleteUser(User &user, Accounts &accounts, std::string &username, int verificationCode)
{
    std::cout << "Enter your username: ";
}


