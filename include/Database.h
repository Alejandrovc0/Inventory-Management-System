#ifndef DATABASE_H
#define DATABASE_H

#include "User.h"
#include "Accounts.h"
#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <vector>

// Forward declaration
class Database
{
private:
	sql::Driver *driver;  // MySQL driver
	sql::Connection *con; // MySQL connection
	sql::Statement *stmt; // MySQL statement
	sql::ResultSet *res;  // MySQL result set

public:
	Database();	 // Constructor
	~Database(); // Destructor

	void connect();											   // Connect to the database
	void disconnect();										   // Disconnect from the database
	void insertData(std::string sqlQuery);					   // Insert data into the database
	void selectData(std::string sqlQuery, Accounts &accounts); // Select data from the database
	void updateData();										   // Update data in the database
	void deleteData();										   // Delete data from the database
};

#endif
