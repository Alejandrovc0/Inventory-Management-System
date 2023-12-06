#include "User.h"
#include <iostream>

using namespace std;

User::User()
{
    name = "";
    username = "";
    password = "";
    verificationCode = 0;
}

User::User(const string &name, const string &username, const string &password, int verificationCode)
    : name(name), username(username), password(password), verificationCode(verificationCode) {}

string User::getName() const
{
    return name;
}

string User::getUsername() const
{
    return username;
}

string User::getPassword() const
{
    return password;
}

int User::getVerification() const
{
    return verificationCode;
}

void User::setName(const string &newName)
{
    name = newName;
}

void User::setUsername(const string &newUsername)
{
    username = newUsername;
}

void User::setPassword(const string &newPassword)
{
    password = newPassword;
}

void User::setVerification(int newVerificationCode)
{
    verificationCode = newVerificationCode;
}
