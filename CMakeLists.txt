cmake_minimum_required(VERSION 3.10)

project(Inventory_Management_System)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Include headers
include_directories(include)
include_directories(include/MySQL)
include_directories(include/MySQL/jdbc)

# Add precompiled object files
file(GLOB OBJECTS "src/*.o")

# Set build type
set(CMAKE_BUILD_TYPE Debug)

# Create executable
add_executable(inventory_system src/main.cpp ${OBJECTS})

# Set the path to MySQL Connector/C++ include directory
set(MYSQL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/MySQLConnector/include)

# Include MySQL Connector/C++ headers
include_directories(${MYSQL_INCLUDE_DIR})

# Set the path to MySQL Connector/C++ library directory
set(MYSQL_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/MySQLConnector/lib64/vs14)

# Link MySQL Connector/C++
target_link_libraries(inventory_system "${MYSQL_LIBRARY_DIR}/mysqlcppconn.lib")
