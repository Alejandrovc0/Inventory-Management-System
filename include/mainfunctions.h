#pragma once
#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#include "Item.h"
#include "Inventory.h"
#include "User.h"

int menu();
void getItemInfo(User& user, int serialNumber, std::string& name, int quantity, double price);
void removeItem(User& user);
void updateItem(User& user, int serialNumber, std::string& name, int quantity, double price);
void searchItem(User& user);
void save_loadInventory(User& user);
bool returnOption();

#endif // MAINFUNCTIONS_H