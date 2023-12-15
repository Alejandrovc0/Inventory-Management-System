#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "User.h"
#include <vector>

class Accounts
{
private:
    std::vector<User> users;

public:
    void loadAccounts();
    void addUser(const User &newUser);
    void registerUser(User &user, const std::string &name, const std::string &username, std::string &password, int verificationCode, Inventory &inventory);
    bool isValidPassword(const std::string &password);
    std::string encryptPassword(std::string &password);
    std::string decryptPassword(std::string &password);
    bool login(User &user, Accounts &accounts, const std::string &enteredUsername, std::string &enteredPassword);
    void logout() const;
    void retrieveUsername(User &user, Accounts &accounts, const std::string name, const int verificationCode);
    void changePassword(User &user, Accounts &accounts, const std::string &username, const int verificationCode, std::string &updatedPassword);
    bool userExist(const std::string &username, const int verificationCode);
    void deleteUser(User &user, Accounts &accounts, const std::string &username, const int verificationCode);
};

#endif