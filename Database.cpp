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

void Database::selectData(std::string sqlQuery, std::vector<User>& loadedUsers, Accounts& accounts)
{
    try
    {
        // Create a statement object
        stmt = con->createStatement();

        // Execute the SQL statement
        res = stmt->executeQuery(sqlQuery);
        while (res->next())
        {
            if (res->getInt("count") == 0)
            {
                std::cout << "No users found!" << std::endl;
                return;
            }
        

            std::string firstName, lastName, email, username, password;
            int verificationCode;
            Inventory inventory;
        
            // Get the data from the database
            firstName = res->getString("first_name");
            lastName = res->getString("last_name");
            email = res->getString("email");
            password = res->getString("password");
            username = res->getString("username");
            verificationCode = res->getInt("verification_code");

            // Add the user to the vector
            User user(firstName, lastName, email, username, password, verificationCode, inventory);
            loadedUsers.push_back(user);
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
