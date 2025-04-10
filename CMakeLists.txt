cmake_minimum_required(VERSION 3.10)
project(iland-model VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)


# Build settings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Find required packages
# Uncomment as needed
find_package(Boost REQUIRED COMPONENTS system filesystem)
find_package(Qt6 COMPONENTS Core Gui Widgets Qml Sql Xml Concurrent REQUIRED)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h" "include/*.hpp")

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/abe
    ${PROJECT_SOURCE_DIR}/src/bite
    ${PROJECT_SOURCE_DIR}/src/abe/output
    ${PROJECT_SOURCE_DIR}/src/core
    ${PROJECT_SOURCE_DIR}/src/output
    ${PROJECT_SOURCE_DIR}/src/tools
    # Add other include directories as needed
)

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# PYTHON ZONE
add_executable(python_interface src/interface/python.cpp)
target_link_libraries(python_interface
   Boost::system
   Boost::filesystem
   Qt6::Core
   Qt6::Gui
   Qt6::Widgets
   Qt6::Qml
   Qt6::Sql
   Qt6::Xml
   Qt6::Concurrent
)
set_target_properties(python_interface PROPERTIES CXX_STANDARD 17)
# END PYTHON ZONE


# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
   Boost::system
   Boost::filesystem
   Qt6::Core
   Qt6::Gui
   Qt6::Widgets
   Qt6::Qml
   Qt6::Sql
   Qt6::Xml
   Qt6::Concurrent
)

# Installation
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# Testing (uncomment if needed)
# enable_testing()
# add_subdirectory(tests)