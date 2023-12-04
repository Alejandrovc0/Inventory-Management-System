#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "User.h"
#include <vector>

class Accounts
{
    private:
        vector<User> users;

    public:
        void addUser(const User &newUser);
        void encryptPassword(User &user);
        void login(const User &username, const User &password, const User verificationCode);
        void logout() const;
        void updateAccount(const User &user, const User &updatedUser);
        void retrieveUsername(const User verificationCode) const;
        void retrievePassword(const User verificationCode) const;
        void changePassword(const User &password, const User verificationCode, const User &updatedPassword);
        bool isEmpty() const;
};


#endif