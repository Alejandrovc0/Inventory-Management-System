cmake_minimum_required(VERSION 3.10)

project(Inventory_Managment_System)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

# Include headers
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(inventory_system ${SOURCES})

# Link against SDL2 using sdl2-config.cmake
include(${CMAKE_SOURCE_DIR}/lib/cmake/SDL2/sdl2-config.cmake)

# Link against SDL2
target_link_libraries(inventory_system SDL2::SDL2)

