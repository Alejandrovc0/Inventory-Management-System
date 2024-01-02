cmake_minimum_required(VERSION 3.10)

project(Inventory_Management_System)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add precompiled object files
file(GLOB SOURCES "src/*.cpp")

# Set build type
set(CMAKE_BUILD_TYPE Debug)

# Create executable
add_executable(inventory_system ${SOURCES})

# Set the path to MySQL Connector/C++ include directory
set(MYSQL_CONNECT_INCLUDE_DIR "C:/Program Files/MySQL/MySQL Connector C++ 8.2/include/jdbc")

set(MYSQL_INCLUDE_DIR "C:/Program Files/MySQL/MySQL Server 8.0/include")

# Include headers
set(HEADERS_DIR "C:/Users/alejo/Desktop/Inventory-Managment-System/include")

# Include MySQL Connector/C++ headers
target_include_directories(inventory_system PRIVATE ${MYSQL_CONNECT_INCLUDE_DIR} ${MYSQL_INCLUDE_DIR} ${HEADERS_DIR})

# Set the path to MySQL Connector/C++ library directory
set(MYSQL_CONNECT_LIBRARY_DIR "C:/Program Files/MySQL/MySQL Connector C++ 8.2/lib64/vs14")

set(MYSQL_LIBRARY_DIR "C:/Program Files/MySQL/MySQL Server 8.0/lib")

# Link MySQL Connector/C++
target_link_libraries(inventory_system PRIVATE ${MYSQL_CONNECT_LIBRARY_DIR}/mysqlcppconn.lib ${MYSQL_LIBRARY_DIR}/libmysql.lib)