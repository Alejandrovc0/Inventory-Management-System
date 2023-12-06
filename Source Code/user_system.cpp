#include "user_declaration.h"
#include <iostream>
#include <string>

using namespace std;

int userMenu(bool &login)
{
    int choice;
    string name, username, password;
    int verificationCode;
    Accounts accounts;
    User user;

    while (login == false)
    {
        cout << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
                userRegister(user, accounts, name, username, password, verificationCode);
                break;
            case 2:
                userLogin(user, accounts, username, password);
                break;
            case 3:
                cout << "Exiting..." << endl;
                exit(-1);
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    return 0;
}

void userRegister(User &user, Accounts &accounts, string &name, string &username, string &password, int verificationCode)
{
    cout << "\t\tSign up" << endl;
    cout << "Name: " << endl;
    getline(cin, name);
    cout << "Username: " << endl;
    cin >> username;
    cout << "Password: " << endl;
    cin >> password;
    cout << endl;

    User newUser(name, username, password, verificationCode);
    accounts.registerUser(newUser);
}

void userLogin(User &user, Accounts &accounts, string &username, string &password)
{
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    cout << endl;
    accounts.login(user, username, password);
}

void changePassword()
{

}

void recoverPassword()
{

}

void recoverUsername()
{

}

void updateUserInfo()
{

}

void deleteUser()
{

}


