#pragma once

#ifndef USER_SYSTEM_H
#define USER_SYSTEM_H

#include "User.h"
#include "Accounts.h"
#include "Database.h"

void userMenu(Database& dataBase, User& user, Accounts& accounts, bool& login);
void userSignup(Database& dataBase, User& user, Accounts& accounts, std::string& firstName, std::string& lastName, std::string& email, std::string& username, std::string& password, int verificationCode);
void userLogin(Database& dataBase, User& user, Accounts& accounts, std::string& username, std::string& password, bool& login);
void changePassword(Database& dataBase, User& user, Accounts& accounts);
void recoverUsername(User& user, Accounts& accounts);
void deleteAccount(Database& dataBase, User& user, Accounts& accounts, std::string& username, int verificationCode);

#endif

