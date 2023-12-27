cmake_minimum_required(VERSION 3.10)

project(Inventory_Managment_System)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Include headers
include_directories(include)

# Add precompiled object files
file(GLOB SOURCES "src/*.cpp")

set(CMAKE_BUILD_TYPE Debug)

# Create executable
add_executable(inventory_system src/main.cpp ${SOURCES})


