cmake_minimum_required(VERSION 3.10)

project(Inventory_Management_System)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Include headers
include_directories(include)
include_directories(include/MySQL)
include_directories(include/MySQL/jdbc)

# Add precompiled object files
file(GLOB SOURCES "src/*.cpp")

# Set build type
set(CMAKE_BUILD_TYPE Debug)

# Create executable
add_executable(inventory_system ${SOURCES})

# Set the path to MySQL Connector/C++ include directory
set(MYSQL_CONNECT_INCLUDE_DIR "C:/Program Files/MySQL/MySQL Connector C++ 8.2/include")

set(MYSQL_INCLUDE_DIR "C:/Program Files/MySQL/MySQL Server 8.0/include")

# Include MySQL Connector/C++ headers
include_directories(${MYSQL_CONNECT_INCLUDE_DIR}, ${MYSQL_INCLUDE_DIR})

# Set the path to MySQL Connector/C++ library directory
set(MYSQL_CONNECT_LIBRARY_DIR "C:/Program Files/MySQL/MySQL Connector C++ 8.2/lib64/vs14")

set(MYSQL_LIBRARY_DIR "C:/Program Files/MySQL/MySQL Server 8.0/lib")

link_directories(${MYSQL_CONNECT_LIBRARY_DIR}, ${MYSQL_LIBRARY_DIR})

# Link MySQL Connector/C++
target_link_libraries(inventory_system mysqlcppconn.lib libmysql.lib)
