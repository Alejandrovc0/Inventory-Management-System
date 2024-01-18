#ifndef DATABASE_H
#define DATABASE_H

#include "Accounts.h"
#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <iostream>

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
	void selectData(std::string sqlQuery, std::vector<User>& loadedUsers, Accounts& accounts);
	void updateData();
	void deleteData();

};

#endif
