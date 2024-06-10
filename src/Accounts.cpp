#include <iostream>
#include <fstream>
#include "Accounts.h"
#include "Database.h"
#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

// Load accounts from the database
void Accounts::loadAccounts(Database &dataBase, Accounts &accounts)
{
    // Create a vector to store the accounts
    std::vector<User> loadedUsers;

    // Create a SQL statement to retrieve the accounts from the database
    std::string sqlQuery;
    sqlQuery = "SELECT COUNT(*) AS count FROM users";

    // Retrieve the data from the database and store it in the accounts vector
    dataBase.selectData(sqlQuery, accounts);
}

// Add a new user to the accounts
void Accounts::addUser(const User &user)
{
    // Add the user to the users vector
    users.push_back(user);
}

// Register a new user with the system
void Accounts::registerUser(Database &dataBase, User &user, const std::string &firstName, const std::string &lastName, const std::string &email, const std::string &username, std::string &password, int verificationCode, Inventory &inventory)
{
    // Encrypt the user's password
    std::string encryptedPasword;
    encryptedPasword = encryptPassword(password);

    // Create a SQL statement to insert the new user into the database
    std::string sqlString;
    sqlString = "CALL add_users ('" + firstName + "', '" + lastName + "', '" + email + "', '" + username + "', '" + encryptedPasword + "', '" + std::to_string(verificationCode) + "')";

    // Insert the data into the database
    const_cast<Database &>(dataBase).insertData(sqlString);

    // Add the new user to the users vector
    user = User(firstName, lastName, email, username, encryptedPasword, verificationCode, inventory);
    addUser(user);

    // Print successful message to the user
    std::cout << "Account created successfully!" << std::endl;
}

// Check if a password is valid
bool Accounts::isValidPassword(const std::string &password)
{
    // Check if the password has at least 8 characters, an uppercase letter, a lowercase letter, a number, and a special character
    bool hasUppercase = false, hasLowercase = false, hasNumber = false, hasSpecialChar = false;
    for (auto c : password)
    {
        if (isupper(c)) // Check if the character is uppercase
        {
            hasUppercase = true;
        }
        else if (islower(c)) // Check if the character is lowercase
        {
            hasLowercase = true;
        }
        else if (isdigit(c)) // Check if the character is a number
        {
            hasNumber = true;
        }
        else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '*' || c == '/') // Check if the character is a special character
        {
            hasSpecialChar = true;
        }
    }
    // Return true if the password is valid
    return password.length() >= 8 && hasUppercase && hasLowercase && hasNumber && hasSpecialChar;
}

// Encrypt a password
std::string Accounts::encryptPassword(std::string &password)
{
    // Encrypt the password
    for (char &character : password)
    {
        character += 3;
    }

    return password;
}

// Decrypt a password
std::string Accounts::decryptPassword(std::string &password)
{
    // Decrypt the password
    for (char &character : password)
    {
        character -= 3;
    }

    return password;
}

// Login to the system
bool Accounts::login(Database &dataBase, User &user, Accounts &accounts, const std::string &enteredUsername, std::string &enteredPassword)
{
    // Encrypt the entered password
    std::string encryptedPassword = encryptPassword(enteredPassword);
    for (const auto &currentUser : users) // Check if the entered username and password match the user's credentials
    {
        // If the entered username and password match the user's credentials, log the user in
        if (enteredUsername == currentUser.getUsername() && encryptedPassword == currentUser.getPassword())
        {
            user = currentUser;
            std::cout << "Login successful!" << std::endl;
            return true;
        }
    }

    // If the entered username and password do not match the user's credentials, display an error message
    std::cout << "Login failed!" << std::endl;
    return false;
}

// Logout of the system
void Accounts::logout() const
{
    std::cout << "Logout successful!" << std::endl;
    exit(0);
}

// Retrieve the username based on name and verification code
void Accounts::retrieveUsername(User &user, Accounts &accounts, const std::string name, const int verificationCode)
{
    // Loop through the users and retrieve the username of the user
    for (auto &user : users)
    {
        // If the name and verification code match the user's credentials, display the username
        if (user.getName() == name && user.getVerification() == verificationCode)
        {
            std::cout << "Your username is: " << user.getUsername() << std::endl;
            return;
        }
    }
    // Else, display an error message
    std::cout << "No user found with the provided verification code." << std::endl;
}

// Change the password of a user
void Accounts::changePassword(Database &dataBase, User &user, Accounts &accounts, const std::string &username, const int verificationCode, std::string &updatedPassword)
{
    // Loop through the users and change the password of the user
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

// Check if a user exists
bool Accounts::userExist(const std::string &username, const int verificationCode)
{
    // Loop through the users and check if the user exists
    for (auto &user : users)
    {
        if (user.getUsername() == username && user.getVerification() == verificationCode)
        {
            return true; // Return true if the user exists
        }
    }
    return false; // Return false if the user does not exist
}

// Delete a user from the system
void Accounts::deleteUser(Database &dataBase, User &user, Accounts &accounts, const std::string &username, const int verificationCode)
{
    int choice; // Variable to store the user's choice

    // Ask for confirmation before deleting the account
    std::cout << "Are you sure you want to delete your account? (y/n)" << std::endl;
    std::cin >> choice;
    choice = tolower(choice); // Convert the choice to lowercase

    // If the user confirms the deletion, delete the account
    if (choice == 'y')
    {
        // Create a SQL statement to delete the user from the database
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
    // Else, display an error message
    else
    {
        std::cout << "Account not deleted!" << std::endl;
    }
}