#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "User.h"
#include <vector>

// Forward declaration
class Database;
class Accounts
{
private:
    std::vector<User> users; // Vector to store the users

public:
    void loadAccounts(Database &dataBase, Accounts &accounts); // Load accounts from the database
    void addUser(const User &newUser);                         // Add a new user to the accounts
    void registerUser(Database &dataBase, User &user, const std::string &firstName, const std::string &lastName,
                      const std::string &email, const std::string &username, std::string &password, int verificationCode,
                      Inventory &inventory);            // Register a new user with the system
    bool isValidPassword(const std::string &password);  // Check if a password is valid
    std::string encryptPassword(std::string &password); // Encrypt the user's password
    std::string decryptPassword(std::string &password); // Decrypt the user's password
    bool login(Database &dataBase, User &user, Accounts &accounts, const std::string &enteredUsername,
               std::string &enteredPassword);                                                                  // Log in to the system
    void logout() const;                                                                                       // Log out of the system
    void retrieveUsername(User &user, Accounts &accounts, const std::string name, const int verificationCode); // Retrieve the username
    void changePassword(Database &dataBase, User &user, Accounts &accounts, const std::string &username,
                        const int verificationCode, std::string &updatedPassword); // Change the user's password
    bool userExist(const std::string &username, const int verificationCode);       // Check if a user exists
    void deleteUser(Database &dataBase, User &user, Accounts &accounts, const std::string &username,
                    const int verificationCode); // Delete a user from the system
};

#endif