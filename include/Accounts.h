#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "User.h"
#include "Database.h"
#include <vector>

class Accounts
{
private:
    std::vector<User> users;

public:
    void loadAccounts(Database& dataBase, std::vector<User>& loadUsers, Accounts& accounts);
    void addUser(const User& newUser);
    void registerUser(Database& dataBase, User& user, const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& username, std::string& password, int verificationCode, Inventory& inventory);
    bool isValidPassword(const std::string& password);
    std::string encryptPassword(std::string& password);
    std::string decryptPassword(std::string& password);
    bool login(Database& dataBase, User& user, Accounts& accounts, const std::string& enteredUsername, std::string& enteredPassword);
    void logout() const;
    void retrieveUsername(User& user, Accounts& accounts, const std::string name, const int verificationCode);
    void changePassword(Database& dataBase, User& user, Accounts& accounts, const std::string& username, const int verificationCode, std::string& updatedPassword);
    bool userExist(const std::string& username, const int verificationCode);
    void deleteUser(Database& dataBase, User& user, Accounts& accounts, const std::string& username, const int verificationCode);
};

#endif