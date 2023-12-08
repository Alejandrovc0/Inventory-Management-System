#ifndef USER_DECLARATION_H
#define USER_DECLARATION_H

#include "User.h"
#include "Accounts.h"

void userMenu(User &user, Accounts &accounts, Inventory &inventory, bool &login);
void userRegister(User &user, Accounts &accounts, std::string &name, std::string &username, std::string &password, int verificationCode);
void userLogin(User &user, Accounts &accounts, Inventory &inventory, std::string &username, std::string &password, bool &login);
void changePassword(User &user, Accounts &accounts);
void recoverUsername(User &user, Accounts &accounts);
void deleteUser(User &user, Accounts &accounts, std::string &username, int verificationCode);


#endif