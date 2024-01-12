#include "Database.h"
#include "Inventory.h"
#include "User.h"

Database::Database()
:driver(nullptr), con(nullptr), stmt(nullptr), res(nullptr) {}

Database::~Database()
{
	delete res;
	delete stmt;
	delete con;
}

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
    catch (sql::SQLException& e)
    {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Error code: " << e.getErrorCode() << std::endl;
        std::cout << "SQL State: " << e.getSQLState() << std::endl;
	}
}
void Database::disconnect()
{
    delete res;
    delete stmt;
    delete con;
}

void Database::insertData(std::string sqlQuery)
{
    try
    {
        // Create a statement object
        sql::Statement* stmt;
        stmt = con->createStatement();

        sql::ResultSet* res;
        stmt = con->createStatement();

        // Execute the SQL statement
        res = stmt->executeQuery(sqlQuery);
    }
    catch (sql::SQLException& e)
    {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cout << "Error: " << e.what() << std::endl;
		std::cout << "Error code: " << e.getErrorCode() << std::endl;
		std::cout << "SQL State: " << e.getSQLState() << std::endl;
    }

}

void Database::selectData(std::string sqlQuery)
{
    try
    {
        // Create a statement object
        sql::Statement* stmt;
        stmt = con->createStatement();

        sql::ResultSet* countRes;
        // Execute the SQL statement
        countRes = stmt->executeQuery(sqlQuery);
        countRes->next();

        if (countRes->getInt("count") == 0)
        {
            std::cout << "No users found!" << std::endl;
            return;
        }

        std::string firstName, lastName, email, username, password;
        int verificationCode;
        std::vector<User> loadedUsers;
        Inventory inventory;

        while (countRes->next())
        {
            firstName = countRes->getString("first_name");
            lastName = countRes->getString("last_name");
            email = countRes->getString("email");
            username = countRes->getString("username");
            password = countRes->getString("password");
            verificationCode = countRes->getInt("verification_code");

            // Add the user to the vector
            User existingUser(firstName, lastName, email, username, password, verificationCode, inventory);
            loadedUsers.push_back(existingUser);
        }
    }
    catch (sql::SQLException& e)
    {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Error code: " << e.getErrorCode() << std::endl;
        std::cout << "SQL State: " << e.getSQLState() << std::endl;
    }
}

void Database::updateData()
{

}

void Database::deleteData()
{

}
