#include "Accounts.h"
#include <iostream>

using namespace std;

void Accounts::addUser(const User &user)
{
    users.push_back(user);
}


void Accounts::encryptPassword(User &user)
{
    string password = user.getPassword();
    string encryptedPassword;

    for (char &c : password)
    {
        encryptedPassword += char(int(c) + 3);
    }

    user.setPassword(encryptedPassword);
}

void Accounts::login(const User &username, const User &password, const User verificationCode)
{

}

void Accounts::logout() const
{

}

void Accounts::updateAccount(const User &user, const User &updatedUser)
{

}

void Accounts::retrieveUsername(const User verificationCode) const
{

}

void Accounts::retrievePassword(const User verificationCode) const
{

}

void Accounts::changePassword(const User &password, const User verificationCode, const User &updatedPassword)
{

}

bool Accounts::userExist() const
{
    return users.empty();
}
