#include "Accounts.h"
#include <iostream>
#include <fstream>
#include "mysql_connection.h"
#include <mysql_driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

void Accounts::loadAccounts()
{
    std::string sqlString;

    sqlString = "SELECT * FROM Users;";
    
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "Summersarecold20$");
    con->setSchema("Inventory System");

    sql::Statement *stmt;
    stmt = con->createStatement();

    sql::ResultSet *res;
    res = stmt->executeQuery(sqlString);

    std::string firstName, lastName, email, username, password;
    int verificationCode;
    std::vector<User> loadedUsers;
    Inventory inventory;

    while(res->next())
    {
        firstName = res->getString("first_name");
        lastName = res->getString("last_name");
        email = res->getString("email");
        username = res->getString("username");
        password = res->getString("password");
        verificationCode = res->getInt("verification_code");

        User existingUser(firstName, lastName, email, username, password, verificationCode, inventory);
        loadedUsers.push_back(existingUser);
    }
    
    delete res;
    delete stmt;
    delete con;
}

void Accounts::addUser(const User &user)
{
    users.push_back(user);
}

void Accounts::registerUser(User &user, const std::string &firstName, const std::string &lastName, const std::string &email, const std::string &username, std::string &password, int verificationCode, Inventory &inventory)
{
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    
    // Create a connection
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "Summersarecold20$");

    // Switch to the database
    con->setSchema("Inventory System");

    // Create a statement object
    sql::Statement *stmt;
    stmt = con->createStatement();

    std::string encryptedPasword;
    std::string sqlString;
    encryptedPasword = encryptPassword(password);
    user = User(firstName, lastName, email, username, encryptedPasword, verificationCode, inventory);

    sqlString = "INSERT INTO Users (first_name, last_name, email, username, password, verification_code) VALUES ('" + firstName + "', '" + lastName + "', '" + email + "', '" + username + "', '" + encryptedPasword + "', '" + std::to_string(verificationCode) + "');";

    // Execute the SQL statement
    stmt->executeQuery(sqlString);

    delete stmt;
    delete con;

    addUser(user);
    std::cout << "Account created successfully!" << std::endl;
}

bool Accounts::isValidPassword(const std::string &password)
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

std::string Accounts::encryptPassword(std::string &password)
{
    for (char &character : password)
    {
        character += 3;
    }

    return password;
}

std::string Accounts::decryptPassword(std::string &password)
{
    for (char &character : password)
    {
        character -= 3;
    }

    return password;
}

bool Accounts::login(User &user, Accounts &accounts, const std::string &enteredUsername, std::string &enteredPassword)
{
    std::string encryptedPassword = encryptPassword(enteredPassword);
    for (const auto &currentUser : users)
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

void Accounts::retrieveUsername(User &user, Accounts &accounts, const std::string name, const int verificationCode)
{
    for (auto &user : users)
    {
        if (user.getName() == name && user.getVerification() == verificationCode)
        {
            std::cout << "Your username is: " << user.getUsername() << std::endl;
            return;
        }
    }
    std::cout << "No user found with the provided verification code." << std::endl;
}

void Accounts::changePassword(User &user, Accounts &accounts, const std::string &username, const int verificationCode, std::string &updatedPassword)
{

    for (auto &user : users)
    {
        if (user.getUsername() == username && user.getVerification() == verificationCode)
        {
            user.setPassword(encryptPassword(updatedPassword));
            return;
        }
    }
    std::cout << "User not found!" << std::endl;
}

bool Accounts::userExist(const std::string &username, const int verificationCode)
{
    for (auto &user : users)
    {
        if (user.getUsername() == username && user.getVerification() == verificationCode)
        {
            return true;
        }
    }
    return false;
}

void Accounts::deleteUser(User &user, Accounts &accounts, const std::string &username, const int verificationCode)
{
    int choice;
    std::cout << "Are you sure you want to delete your account? (y/n)" << std::endl;
    std::cin >> choice;
    choice = tolower(choice);

    if (choice == 'y')
    {
        for (auto &user : users)
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