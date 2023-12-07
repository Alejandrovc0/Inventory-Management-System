#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "User.h"
#include <vector>

class Accounts
{
    private:
        std::vector<User> users;
    
    public:
        void registerUser(const User &newUser);
        bool isValidPassword(const std::string &password);
        void encryptPassword(User user, std::string &password);
        void login(User user, const std::string& enteredUsername, const std::string& enteredPassword);
        void logout() const;
        void updateAccount(const std::string &user, const User &updatedUser);
        void retrieveUsername(const int verificationCode);
        void retrievePassword(const int verificationCode);
        void changePassword(const std::string &password, const int verificationCode, const User &updatedPassword);
        bool userExist(const std::string &username);
};


#endif