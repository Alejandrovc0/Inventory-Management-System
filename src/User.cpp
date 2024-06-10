#include "User.h"
#include <iostream>
#include <fstream>

User::User()
{
    firstName = "";
    lastName = "";
    email = "";
    username = "";
    password = "";
    verificationCode = 0;
    inventory;
}

User::User(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& username, const std::string& password, int verificationCode, Inventory& inventory)
    : firstName(firstName), lastName(lastName), email(email), username(username), password(password), verificationCode(verificationCode), inventory(inventory) {}

std::string User::getName() const
{
    return firstName + " " + lastName;
}

std::string User::getEmail() const
{
    return email;
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

Inventory& User::getInventory(User& user)
{
    inventory.loadInventoryInfo(user);
    return inventory;
}

void User::setName(const std::string& newName)
{
    firstName, lastName = newName;
}

void User::setEmail(const std::string& newEmail)
{
    email = newEmail;
}

void User::setUsername(const std::string& newUsername)
{
    username = newUsername;
}

void User::setPassword(const std::string& newPassword)
{
    password = newPassword;
}

void User::setVerification(int newVerificationCode)
{
    verificationCode = newVerificationCode;
}

void User::addItemToInventory(const Item& item)
{
    inventory.addItem(item);
}

void User::removeItemFromInventory(const int& serialNumber)
{
    inventory.removeItem(serialNumber);
}

void User::updatedItemFromInventory(const std::string& itemName, const Item& updatedItem)
{
    inventory.updateItem(itemName, updatedItem);
}

void User::displayInventoryFromInventory() const
{
    inventory.displayInventory();
}

const Item* User::searchItemfromInventory(const int& serialNumber) const
{
    return inventory.searchItem(serialNumber);
}

void User::saveUserInventoryInfo(const User& user)
{
    inventory.saveInventoryInfo(user);
}

void User::loadUserInventoryInfo(const User& user)
{
    inventory.loadInventoryInfo(user);
}

void User::overwriteUserInventory()
{
    inventory.overwriteInventory();
}

bool User::userInventoryisEmpty() const
{
    return inventory.isEmpty();
}