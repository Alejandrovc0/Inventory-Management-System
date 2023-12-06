#include "Accounts.h"
#include <iostream>

using namespace std;

void Accounts::registerUser(const User &user)
{
    users.push_back(user);
}

bool Accounts::isValidPassword(const string &password)
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

void Accounts::encryptPassword(User user, string &password)
{   
    for (auto &character : password)
    {
        character += 3;
    }
}

void Accounts::login(User user, const string& enteredUsername, const string& enteredPassword)
{
    if (enteredUsername == user.getUsername()  && enteredPassword == user.getPassword())
    {
        cout << "Login successful!" << endl;
    }
    else
    {
        cout << "Login failed!" << endl;
    }
}

void Accounts::logout() const
{
    cout << "Logout successful!" << endl;
    exit(0);
}

void Accounts::updateAccount(const string &user, const User &updatedUser)
{

}

void Accounts::retrieveUsername(const int verificationCode)
{

}

void Accounts::retrievePassword(const int verificationCode)
{

}

void Accounts::changePassword(const string &password, const int verificationCode, const User &updatedPassword)
{

}

bool Accounts::userExist(const string &username)
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
