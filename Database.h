#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include "Accounts.h"
#include "User.h"
#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

class Database
{
private:
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::ResultSet* res;

public:
	Database();
	~Database();

	void connect();
	void disconnect();
	void insertData(std::string sqlQuery);
<<<<<<< HEAD
	void selectData(std::string sqlQuery, std::vector<User>& loadedUsers, Accounts& accounts);
=======
	void selectData(std::string sqlQuery, User& loadedUser, Accounts& accounts);
>>>>>>> b2191dd69aa669f8dfba4bca12c85f825d828625
	void updateData();
	void deleteData();

};

#endif
