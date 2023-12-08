#include "Accounts.h"
#include <iostream>

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
        encryptedPassword = character += 3;
    }

    return encryptedPassword;
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

void Accounts::retrieveUsername(User& user, Accounts& accounts, const std::string username, const int verificationCode)
{
    if(!accounts.userExist(username, verificationCode))
    {
        std::cout << "Invalid information!" << std::endl;
    }
    else
    {
        std::cout << user.getUsername() << std::endl;
    }
}

void Accounts::changePassword(User& user, Accounts& accounts, const int verificationCode, std::string& updatedPassword)
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
