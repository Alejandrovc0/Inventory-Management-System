#include "user_declaration.h"
#include <iostream>

using namespace std;

int userMenu(bool &login)
{
    int choice;
    string username, password;
    int verificationCode;
    Accounts accounts;
    User user;

    while (login == false)
    {
        cout << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
                userLogin(user, accounts, username, password, verificationCode);
                break;
            case 2:
                userRegister();
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

void userLogin(User user, Accounts accounts, string &username, string &password, int verificationCode)
{
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    cout << endl;
    accounts.login(user, username, password, user.getVerification());
}

void userRegister()
{
    
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


