#include "Accounts.h"
#include <iostream>
#include <fstream>

void Accounts::loadAccounts()
{
    std::ifstream accountFile;
    accountFile.open("C:\\Users\\alejo\\Desktop\\Inventory-Managment-System\\Data\\users.txt");
    
    if (!accountFile.is_open())
    {
        std::cout << "Error opening file." << std::endl;
        exit(1);
    }

    std::string name, username, password;
    int verificationCode;
    std::vector<User> loadedUsers;

    while (accountFile >> name >> username >> password >> verificationCode)
    {
        User existingUser(name, username, password, verificationCode);
        loadedUsers.push_back(existingUser);
    }
    users = loadedUsers;
    accountFile.close();
}

void Accounts::addUser(const User &user)
{
    users.push_back(user);
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

void Accounts::registerUser(User& user, const std::string& name, const std::string& username, std::string& password, int verificationCode)
{
    std::string encryptedPasword;
    encryptedPasword = encryptPassword(password);
    user = User(name, username, encryptedPasword, verificationCode);

    std::ofstream accountFile("C:\\Users\\alejo\\Desktop\\Inventory-Managment-System\\Data\\users.txt", std::ios::app);

    if(!accountFile.is_open())
    {
        std::cout << "Error opening file." << std::endl;
        exit(1);
    }

    accountFile << name << " " << username << " " << encryptedPasword << " " << verificationCode << std::endl;
    accountFile.close();

    addUser(user);
    std::cout << "Account created successfully!" << std::endl;
}

bool Accounts::login(User& user, const std::string& enteredUsername, std::string& enteredPassword)
{
    std::string encryptedPassword = encryptPassword(enteredPassword);
    for(const auto &currentUser : users)
    {
        if (enteredUsername == user.getUsername()  && encryptedPassword == user.getPassword())
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
    return;
}

void Accounts::retrieveUsername(User& user, Accounts& accounts, const std::string name, const int verificationCode)
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

void Accounts::changePassword(User& user, Accounts& accounts, const std::string& username, const int verificationCode, std::string& updatedPassword)
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