#include <iostream>
#include <fstream>
#include "Accounts.h"
#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

void Accounts::loadAccounts(Database& dataBase, User& user, Accounts& accounts)
{
    std::string sqlQuery;
    sqlQuery = "SELECT COUNT(*) AS count FROM users";

    dataBase.selectData(sqlQuery, user, accounts);

    dataBase.disconnect();
    
}

void Accounts::addUser(const User& user)
{
    users.push_back(user);
}

void Accounts::registerUser(Database& dataBase, User& user, const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& username, std::string& password, int verificationCode, Inventory& inventory)
{
    // Encrypt the password
    std::string encryptedPasword;
    encryptedPasword = encryptPassword(password);

    // Create a string for the SQL query
    std::string sqlString;
    sqlString = "CALL add_users ('" + firstName + "', '" + lastName + "', '" + email + "', '" + username + "', '" + encryptedPasword + "', '" + std::to_string(verificationCode) + "')";

    // Insert the data into the database
    dataBase.insertData(sqlString);
 
    // Add the user to the vector
    user = User(firstName, lastName, email, username, encryptedPasword, verificationCode, inventory);
    addUser(user);

    // Close the connection
    dataBase.disconnect();

    std::cout << "Account created successfully!" << std::endl;
}

bool Accounts::isValidPassword(const std::string& password)
{
    bool hasUppercase = false, hasLowercase = false, hasNumber = false, hasSpecialChar = false;
    for (auto c : password)
    {
        if (isupper(c))
        {
            hasUppercase = true;
        }
        else if (islower(c))
        {
            hasLowercase = true;
        }
        else if (isdigit(c))
        {
            hasNumber = true;
        }
        else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '*' || c == '/')
        {
            hasSpecialChar = true;
        }
    }
    return password.length() >= 8 && hasUppercase && hasLowercase && hasNumber && hasSpecialChar;
}

std::string Accounts::encryptPassword(std::string& password)
{
    for (char& character : password)
    {
        character += 3;
    }

    return password;
}

std::string Accounts::decryptPassword(std::string& password)
{
    for (char& character : password)
    {
        character -= 3;
    }

    return password;
}

bool Accounts::login(Database& dataBase, User& user, Accounts& accounts, const std::string& enteredUsername, std::string& enteredPassword)
{
    std::string encryptedPassword = encryptPassword(enteredPassword);
    for (const auto& currentUser : users)
    {
        if (enteredUsername == currentUser.getUsername() && encryptedPassword == currentUser.getPassword())
        {
            user = currentUser;
            std::cout << "Login successful!" << std::endl;
            return true;
        }
    }
    
    std::cout << "Login failed!" << std::endl;
    return false;
}

void Accounts::logout() const
{
    std::cout << "Logout successful!" << std::endl;
    exit(0);
}

void Accounts::retrieveUsername(User& user, Accounts& accounts, const std::string name, const int verificationCode)
{
    for (auto& user : users)
    {
        if (user.getName() == name && user.getVerification() == verificationCode)
        {
            std::cout << "Your username is: " << user.getUsername() << std::endl;
            return;
        }
    }
    std::cout << "No user found with the provided verification code." << std::endl;
}

void Accounts::changePassword(Database& dataBase, User& user, Accounts& accounts, const std::string& username, const int verificationCode, std::string& updatedPassword)
{

    for (auto& user : users)
    {
        if (user.getUsername() == username && user.getVerification() == verificationCode)
        {
            user.setPassword(encryptPassword(updatedPassword));
            return;
        }
    }
    std::cout << "User not found!" << std::endl;
}

bool Accounts::userExist(const std::string& username, const int verificationCode)
{
    for (auto& user : users)
    {
        if (user.getUsername() == username && user.getVerification() == verificationCode)
        {
            return true;
        }
    }
    return false;
}

void Accounts::deleteUser(Database& dataBase, User& user, Accounts& accounts, const std::string& username, const int verificationCode)
{
    int choice;
    std::cout << "Are you sure you want to delete your account? (y/n)" << std::endl;
    std::cin >> choice;
    choice = tolower(choice);

    if (choice == 'y')
    {
        for (auto& user : users)
        {
            if (user.getUsername() == username && user.getVerification() == verificationCode)
            {
                users.erase(users.begin());
            }
        }
        std::cout << "Account deleted!" << std::endl;
        accounts.logout();
    }
    else
    {
        std::cout << "Account not deleted!" << std::endl;
    }
}