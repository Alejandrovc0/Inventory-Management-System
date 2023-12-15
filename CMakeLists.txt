cmake_minimum_required(VERSION 3.10)

project(Inventory Managment System)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include headers
include_directories(include ${SDL2_INCLUDE_DIRS})

# Add source files
file(GLOB SOURCES "Src/*.cpp")

# Add the object files
set(OBJECTS "Item.o" "Inventory.o" "User.o" "Accounts.o" "user_system.o")

# Add the executable
add_executable(inventory_system ${SOURCES} ${OBJECTS})

# Link against SDL2
target_link_libraries(inventory_system ${SDL2_LIBRARIES})