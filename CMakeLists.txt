cmake_minimum_required(VERSION 3.10)

project(Inventory_Managment_System)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Include headers
include_directories(include)
include_directories(include\\MySQL)
include_directories(include\\MySQL\\jdbc)

# Add precompiled object files
file(GLOB SOURCES "src/*.cpp")

set(CMAKE_BUILD_TYPE Debug)

# Create executable
add_executable(inventory_system src/main.cpp ${SOURCES})

# Set the path to MySQL Connector/C++ include directory
set(MYSQL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/MySQLConnector/include)

set(WITH_BOOST system|C:\\Program Files\\boost_1_84_0)

# Include MySQL Connector/C++ headers
include_directories(${MYSQL_INCLUDE_DIR})

# Set the path to MySQL Connector/C++ library directory
set(MYSQL_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/MySQLConnector/lib64/vs14)

# Link MySQL Connector/C++
target_link_libraries(inventory_system ${MYSQL_LIBRARY_DIR}/mysqlcppconn.lib)
