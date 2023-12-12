#include "Accounts.h"
#include <iostream>
#include <fstream>

void Accounts::loadAccounts()
{
    std::ifstream accountFile;
    accountFile.open("C:\\Users\\alejo\\Desktop\\Inventory-Managment-System\\Data\\users.txt");
    std::string name, username, password;
    int verificationCode;
    
    if (!accountFile.is_open())
    {
        std::cout << "Error opening file." << std::endl;
        exit(1);
    }

    if (!accountFile.is_open())
    {
        std::cout << "Error opening file." << std::endl;
        exit(1);
    }

    while (accountFile >> name >> username >> password >> verificationCode)
    {
        password = decryptPassword(password);
        User existingUser(name, username, password, verificationCode);
        addUser(existingUser);
    }
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

<<<<<<< HEAD
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
void Accounts::login(User& user, const std::string& enteredUsername, std::string& enteredPassword, bool& login)
{
    std::string encryptedPassword = encryptPassword(enteredPassword);

    for(auto &user : users)
=======
bool Accounts::login(const std::string& enteredUsername, std::string& enteredPassword)
{
    std::string encryptedPassword = encryptPassword(enteredPassword);
    for(const auto &user : users)
>>>>>>> 09a9ecd616a633f2e29869da537625ff9aae24a4
    {
        if (enteredUsername == user.getUsername()  && encryptedPassword == user.getPassword())
        {
            std::cout << "Login successful!" << std::endl;
            login = true;
        }
        else
        {
            std::cout << "Login failed!" << std::endl;
            login = false;
        }
    }
    
}

void Accounts::logout() const
{
    std::cout << "Logout successful!" << std::endl;
    exit(0);
}

void Accounts::retrieveUsername(User& user, Accounts& accounts, const int verificationCode)
{
<<<<<<< HEAD
    for(auto &user : users)
    {    if(!(user.getPassword() == password && user.getVerification() == verificationCode))
        {
            std::cout << "Invalid information!" << std::endl;
        }
        else
        {
            std::cout << user.getUsername() << std::endl;
=======
    for (auto &user : users)
    {
        if (user.getVerification() == verificationCode)
        {
            std::cout << "Your username is: " << user.getUsername() << std::endl;
            return;
>>>>>>> 09a9ecd616a633f2e29869da537625ff9aae24a4
        }
    }
    std::cout << "No user found with the provided verification code." << std::endl;
}

void Accounts::changePassword(User& user, Accounts& accounts, std::string& updatedPassword)
{
    updatedPassword = accounts.encryptPassword(updatedPassword);
    user.setPassword(updatedPassword);
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