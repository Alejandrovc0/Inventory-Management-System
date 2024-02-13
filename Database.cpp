#include <iostream>
#include <fstream>
#include "Database.h"
#include "Inventory.h"
#include "User.h"
#include "Accounts.h"

Database::Database() // Constructor
:driver(nullptr), con(nullptr), stmt(nullptr), res(nullptr) {} // Initialize the pointers to nullptr

Database::~Database() // Destructor
{
	delete res;
	delete stmt;
	delete con;
}

// Connect to the database
void Database::connect()
{
    try
    {
        // Create a connection
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "Summersarecold20$");
        std::cout << "Connection stablished" << std::endl;

        // Switch to the database
        con->setSchema("userInventory");
        std::cout << "Switched to database" << std::endl;
    }
    catch (sql::SQLException& e) // Catch any SQL exceptions
    {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Error code: " << e.getErrorCode() << std::endl;
        std::cout << "SQL State: " << e.getSQLState() << std::endl;
	}
}

// Disconnect from the database
void Database::disconnect()
{
    delete res;
    delete stmt;
    delete con;
}

// Insert data into the database with a SQL query
void Database::insertData(std::string sqlQuery)
{
    try
    {
        // Create a statement object
        stmt = con->createStatement();

        // Execute the SQL statement
        res = stmt->executeQuery(sqlQuery);
    }
    catch (sql::SQLException& e) // Catch any SQL exceptions
    {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cout << "Error: " << e.what() << std::endl;
		std::cout << "Error code: " << e.getErrorCode() << std::endl;
		std::cout << "SQL State: " << e.getSQLState() << std::endl;
    }
}

// Select data from the database with a SQL query
void Database::selectData(std::string sqlQuery, Accounts& accounts)
{
    try
    {
        // Create a statement object
        stmt = con->createStatement();

        // Execute the SQL statement
        res = stmt->executeQuery(sqlQuery);

        while (res->next()) // Loop through the result set
        {
            if (res->getInt("count") == 0) // Check if there are no users in the database
            {
                std::cout << "No users found!" << std::endl; // Print a message to the user
                return;
            }

            std::string firstName, lastName, email, username, password; // Variables to store the user's data
            int verificationCode; // Variable to store the user's verification code
            Inventory inventory; // Create an inventory object
        
            // Get the data from the database
            firstName = res->getString("first_name");
            lastName = res->getString("last_name");
            email = res->getString("email");
            password = res->getString("password");
            username = res->getString("username");
            verificationCode = res->getInt("verification_code");

            // Add the user to the vector
            User user(firstName, lastName, email, username, password, verificationCode, inventory);
            accounts.addUser(user);
        }
    }
    catch (sql::SQLException& e) // Catch any SQL exceptions
    {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Error code: " << e.getErrorCode() << std::endl;
        std::cout << "SQL State: " << e.getSQLState() << std::endl;
    }
}

// Update data in the database
void Database::updateData()
{

}

// Delete data from the database
void Database::deleteData()
{

}
