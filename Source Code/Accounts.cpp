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

void Accounts::encryptPassword(User user, std::string &password)
{   
    for (auto &character : password)
    {
        character += 3;
    }
}

void Accounts::login(User user, const std::string& enteredUsername, const std::string& enteredPassword)
{
    if (enteredUsername == user.getUsername()  && enteredPassword == user.getPassword())
    {
        std::cout << "Login successful!" << std::endl;
    }
    else
    {
        std::cout << "Login failed!" << std::endl;
    }
}

void Accounts::logout() const
{
    std::cout << "Logout successful!" << std::endl;
    exit(0);
}

void Accounts::updateAccount(const std::string &user, const User &updatedUser)
{

}

void Accounts::retrieveUsername(const int verificationCode)
{

}

void Accounts::retrievePassword(const int verificationCode)
{

}

void Accounts::changePassword(const std::string &password, const int verificationCode, const User &updatedPassword)
{

}

bool Accounts::userExist(const std::string &username)
{
    for (auto &user : users)
    {
        if (user.getUsername() == username)
        {
            return true;
        }

    }
    return false;
}
