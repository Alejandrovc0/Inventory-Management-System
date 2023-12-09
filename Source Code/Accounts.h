#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "User.h"
#include <vector>

class Accounts
{
    private:
        std::vector<User> users;
    
    public:
        void loadAccounts(User& user);
        void addUser(const User &newUser);
        bool isValidPassword(const std::string &password);
        std::string encryptPassword(std::string &password);
        std::string decryptPassword(std::string &password);
        void login(User user, const std::string& enteredUsername, std::string& enteredPassword, bool& login);
        void logout() const;
        void retrieveUsername(User& user, Accounts& accounts, const std::string username, const int verificationCode);
        void changePassword(User& user, Accounts& accounts, std::string& updatedPassword);
        bool userExist(const std::string& username, const int verificationCode);
        void deleteUser(User &user, Accounts &accounts, const std::string &username, const int verificationCode);
};


#endif