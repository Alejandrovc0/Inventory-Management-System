# Inventory Management System

## Overview

This console-based Inventory Management System is designed to help users manage their inventory efficiently. It provides essential features such as adding, removing, updating, viewing items, and more. The system allows users to interact with their inventory through a user-friendly command-line interface. All user and inventory data is managed through a MySQL database.

## Table of Contents

- [Features](#features)
- [Bonus Features](#bonus-features)
- [Skills Practiced](#skills-practiced)
- [Getting Started](#getting-started)
- [Project Structure](#project-structure)
- [Test Files](#additional-test-files)
- [Contributing](#contributing)
- [License](#license)

## Features

### 1. Add Item

Users can add new items to the inventory by providing details such as item name, quantity, price, and additional relevant information. 

### 2. Remove Item

Remove items from the inventory based on the item name or a unique identifier.

### 3. Update Item

Allow users to update information about existing items, such as changing quantity or updating the price.

### 4. View Inventory

Display a comprehensive list of all items in the inventory, including their details.

### 5. Search Item

Implement a search functionality to find specific items in the inventory.

### 6. Save/Load Data

Functionality to save the inventory data to a file and load it back when the program starts.

## Bonus Features

### 1. Transaction History

Keep a log of transactions (additions, removals, updates) with timestamps. The transaction history is stored in the MySQL database.

### 2. User Authentication

A simple login system to restrict access to authorized users. User credentials are managed in the MySQL database.

### 3. Data Validation

Implement validation for user inputs to ensure data integrity. 

## Skills Practiced

- File handling
- Object-oriented programming (using classes for items, inventory, etc.)
- User input and validation
- Basic data structures and algorithms for searching and updating items.
- MySQL for database management
- Visual Studio for project building and debugging

## Getting Started

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/Inventory-Management-System.git
    ```

2. Set up the MySQL database:
    - Create a new MySQL database and run the provided [SQL script](SQL-script) to set up the necessary tables and sample data.
    - You can use a MySQL database management tool like MySQL Workbench, or the MySQL command line interface to execute the script. Save the [script](SQL-script) to a file, e.g., setup_database.sql.
    - Execute the script using a MySQL client:
      
    ```bash
    mysql -u your_username -p < setup_database.sql
    ```
      
3. Configure the database connection:
    - Update the database connection settings in the Database.h file.

4. Open the project in Visual Studio:
    - Launch Visual Studio.
    - Select "Open a project or solution".
    - Navigate to the cloned repository directory and select the `.sln` file.

5. Build the project:
    - In Visual Studio, select "Build" from the top menu.
    - Choose "Build Solution" (or press `Ctrl+Shift+B`).

6. Run the project:
    - Press `F5` to start debugging or `Ctrl+F5` to run without debugging.

## Project Structure

Inventory-Management-System/
```
|-- include/
|   |-- headers.h            # Header file containing necessary includes
|   |-- user_system.h        # Header file for user system functions
|   |-- user.h               # Header file for user class
|   |-- accounts.h           # Header file for account class
|   |-- inventory.h          # Header file for inventory class
|   |-- item.h               # Header file for item class
|
|-- src/
|   |-- main.cpp             # Main program file containing the entry point and core logic
|   |-- user_system.cpp      # Implementation file for user system functions
|   |-- user.cpp             # Implementation file for user class
|   |-- accounts.cpp         # Implementation file for account class
|   |-- inventory.cpp        # Implementation file for inventory class
|   |-- item.cpp             # Implementation file for item class
|
|-- InventoryManagementSystem.sln # Visual Studio solution file
```

## Additional Test Files
  
The repository includes test files to validate the functionality of the inventory system - see the [Data](Data) file:
- `users.txt`: Contains a list to store the users created.
- `username_inventory_data.txt`: Contains the sample inventory for a user.

## Contributions

Contributions are welcome! If you have ideas for improvements or want to add new features, feel free to fork the repository and submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

---
