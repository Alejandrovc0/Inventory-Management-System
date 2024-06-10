-- Create the database
CREATE DATABASE userinventory;

-- Use the newly created database
USE userinventory;

-- Create the users table
CREATE TABLE users (
    user_id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    email VARCHAR(100) NOT NULL,
    username VARCHAR(50) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL,
    verification_code VARCHAR(100),
    creation_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    INDEX (username),
    INDEX (email)
);

-- Create the inventory table
CREATE TABLE inventory (
    item_id INT AUTO_INCREMENT PRIMARY KEY,
    item_name VARCHAR(100) NOT NULL,
    item_quantity INT NOT NULL,
    item_price DECIMAL(10, 2) NOT NULL,
    user_id INT,
    FOREIGN KEY (user_id) REFERENCES users(user_id)
);

-- Sample data insertion
-- Insert a sample user
INSERT INTO users (first_name, last_name, email, username, password) VALUES ('John', 'Doe', 'john.doe@example.com', 'johndoe', 'password123');

-- Insert sample inventory items for the user
INSERT INTO inventory (item_name, item_quantity, item_price, user_id) VALUES ('Sample Item 1', 10, 9.99, 1);
INSERT INTO inventory (item_name, item_quantity, item_price, user_id) VALUES ('Sample Item 2', 5, 19.99, 1);
