project(order)
cmake_minimum_required(VERSION 3.18)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Definitions
add_definitions(-DDEFAULT_INPUT_FILE="input.bin")

# Includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Sources
add_library(sort STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/sort.c)

# Targets
add_executable(order ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)
target_link_libraries(order sort)
