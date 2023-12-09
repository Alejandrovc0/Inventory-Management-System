#include "Accounts.h"
#include <iostream>
#include <fstream>

void Accounts::loadAccounts(User& user)
{
    std::ifstream accountFile("C:\\Users\\alejo\\Desktop\\Inventory-Managment-System\\Data\\users.txt");
    std::string name, username, password;
    int verificationCode;

    while (accountFile >> name >> username >> password >> verificationCode)
    {
        password = decryptPassword(password);
        user = User(name, username, password, verificationCode);
        addUser(user);
    }
    accountFile.close();
}

void Accounts::addUser(const User &user)
{
    users.push_back(user);
}

bool Accounts::isValidPassword(const std::string &password)
{
    bool hasUppercase = false, hasLowercase = false, hasNumber = false, hasSpecialChar = false;
    for (auto c : password)
    {
        if (isupper(c))
        {
            hasUppercase = true;
        }
        else if (islower(c))
        {
            hasLowercase = true;
        }
        else if (isdigit(c))
        {
            hasNumber = true;
        }
        else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '*' || c == '/')
        {
            hasSpecialChar = true;
        }
    }
    return password.length() >= 8 && hasUppercase && hasLowercase && hasNumber && hasSpecialChar;
}

std::string Accounts::encryptPassword(std::string &password)
{   
    std::string encryptedPassword;

    for (auto &character : password)
    {
        encryptedPassword += char(int(character) + 3);
    }

    return encryptedPassword;
}

std::string Accounts::decryptPassword(std::string &password)
{   
    std::string decryptedPassword;

    for (auto &character : password)
    {
        decryptedPassword += char(int(character) - 3);
    }

    return decryptedPassword;
}

void Accounts::login(User user, const std::string& enteredUsername, std::string& enteredPassword, bool& login)
{
    std::string encryptedPassword = encryptPassword(enteredPassword);
    if (enteredUsername == user.getUsername()  && encryptedPassword == user.getPassword())
    {
        std::cout << "Login successful!" << std::endl;
        login = true;
    }
    else
    {
        std::cout << "Login failed!" << std::endl;
        login = false;
    }
}

void Accounts::logout() const
{
    std::cout << "Logout successful!" << std::endl;
    exit(0);
}

void Accounts::retrieveUsername(User& user, Accounts& accounts, const std::string password, const int verificationCode)
{
    if(!(user.getPassword() == password && user.getVerification() == verificationCode))
    {
        std::cout << "Invalid information!" << std::endl;
    }
    else
    {
        std::cout << user.getUsername() << std::endl;
    }
}

void Accounts::changePassword(User& user, Accounts& accounts, std::string& updatedPassword)
{
    updatedPassword = accounts.encryptPassword(updatedPassword);
    user.setPassword(updatedPassword);
}

bool Accounts::userExist(const std::string& username, const int verificationCode)
{
    for (auto &user : users)
    {
        if (user.getUsername() == username && user.getVerification() == verificationCode)
        {
            return true;
        }
    }
    return false;
}

void Accounts::deleteUser(User &user, Accounts &accounts, const std::string &username, const int verificationCode)
{
    int choice;
    std::cout << "Are you sure you want to delete your account? (y/n)" << std::endl;
    std::cin >> choice;
    choice = tolower(choice);

    if (choice == 'y')
    {
        for (auto &user : users)
        {
            if (user.getUsername() == username && user.getVerification() == verificationCode)
            {
                users.erase(users.begin());
            }
        }
        std::cout << "Account deleted!" << std::endl;
        accounts.logout();
    }
    else
    {
        std::cout << "Account not deleted!" << std::endl;
    }
    
}
