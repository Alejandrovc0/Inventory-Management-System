#ifndef USER_H
#define USER_H

#include "Inventory.h"
#include "Item.h"
#include <string>
#include <vector>


class User
{
    private:
        std::string name;
        std::string username;
        std::string password;
        std::string encryptedPasword;
        int verificationCode;
        Inventory userInventory;

    public:
        User();
        User(const std::string &name, const std::string &username, const std::string &password, int verificationCode);

        std::string getName() const;
        std::string getUsername() const;
        std::string getPassword() const;
        int getVerification() const;
        Inventory& getInventory();

        void setName(const std::string &name);
        void setUsername(const std::string &username);
        void setPassword(const std::string &password);
        void setVerification(int verificationCode);
        void addItemToInventory(const Item &item);
};


#endif