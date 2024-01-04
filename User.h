#pragma once
#ifndef USER_H
#define USER_H

#include "Inventory.h"
#include "Item.h"
#include <string>
#include <vector>

class User
{
private:
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string username;
    std::string password;
    int verificationCode;
    Inventory inventory;

public:
    User();
    User(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& username, const std::string& password, int verificationCode, Inventory& inventory);

    std::string getName() const;
    std::string getEmail() const;
    std::string getUsername() const;
    std::string getPassword() const;
    int getVerification() const;
    Inventory& getInventory(User& user);

    void setName(const std::string& name);
    void setEmail(const std::string& email);
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setVerification(int verificationCode);
    void addItemToInventory(const Item& item);
    void removeItemFromInventory(const int& serialNumber);
    void updatedItemFromInventory(const std::string& itemName, const Item& updatedItem);
    void displayInventoryFromInventory() const;
    const Item* searchItemfromInventory(const int& serialNumber) const;
    void saveUserInventoryInfo(const User& user);
    void loadUserInventoryInfo(const User& user);
    void overwriteUserInventory();
    bool userInventoryisEmpty() const;
};

#endif 