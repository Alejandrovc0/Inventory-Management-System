#include "User.h"
#include <iostream>
#include <fstream>

User::User()
{
    name = "";
    username = "";
    password = "";
    verificationCode = 0;
    inventory = getInventory();
}

User::User(const std::string &name, const std::string &username, const std::string &password, int verificationCode, Inventory &inventory)
    : name(name), username(username), password(password), verificationCode(verificationCode), inventory(inventory) {}

std::string User::getName() const
{
    return name;
}

std::string User::getUsername() const
{
    return username;
}

std::string User::getPassword() const
{
    return password;
}

int User::getVerification() const
{
    return verificationCode;
}

Inventory &User::getInventory()
{
    return inventory;
}

void User::setName(const std::string &newName)
{
    name = newName;
}

void User::setUsername(const std::string &newUsername)
{
    username = newUsername;
}

void User::setPassword(const std::string &newPassword)
{
    password = newPassword;
}

void User::setVerification(int newVerificationCode)
{
    verificationCode = newVerificationCode;
}

void User::addItemToInventory(const Item &item)
{
    inventory.addItem(item);
}
