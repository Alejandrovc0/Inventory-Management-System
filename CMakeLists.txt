cmake_minimum_required(VERSION 3.10)

project(Inventory_Managment_System)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Include headers
include_directories(include)

# Add precompiled object files
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(inventory_system src/main.cpp ${SOURCES})

set(SDL2_DIR "lib\\cmake\\SDL2")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Link against SDL2
target_link_libraries(inventory_system ${SDL2_LIBRARIES})

