cmake_minimum_required(VERSION 3.10)

project(Inventory_Managment_System)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Include headers
include_directories(include)
include_directories(include\\MySQL)
include_directories(include\\MySQL\\cppconn)

# Add precompiled object files
file(GLOB SOURCES "src/*.cpp")

set(CMAKE_BUILD_TYPE Debug)

# Create executable
add_executable(inventory_system src/main.cpp ${SOURCES})

# Link MySQL Connector/C++
target_link_libraries(inventory_system PRIVATE ${CMAKE_SOURCE_DIR}/lib64/vs14/mysqlcppconn.lib)
# Link MySQL Connector/C++
target_link_libraries(inventory_system PRIVATE mysqlcppconn.lib)
