#ifndef USER_DECLARATION_H
#define USER_DECLARATION_H

#include "User.h"
#include "Accounts.h"

using namespace std;

int userMenu(bool &login);
void userRegister(User &user, Accounts &accounts, string &name, string &username, string &password, int verificationCode);
void userLogin(User &user, Accounts &accounts, string &username, string &password);
void changePassword();
void recoverPassword();
void recoverUsername();
void updateUserInfo();
void deleteUser();


#endif