#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "User.h"
#include <vector>

class Accounts
{
    private:
        vector<User> users;

    public:
        void registerUser(const User &newUser);
        bool isValidPassword(const string &password);
        void encryptPassword(User user, string &password);
        void login(User user, const string& enteredUsername, const string& enteredPassword);
        void logout() const;
        void updateAccount(const string &user, const User &updatedUser);
        void retrieveUsername(const int verificationCode);
        void retrievePassword(const int verificationCode);
        void changePassword(const string &password, const int verificationCode, const User &updatedPassword);
        bool userExist(const string &username);
};


#endif