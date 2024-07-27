cmake_minimum_required(VERSION 3.10)

# Project name
project(FitnessApp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(FitnessApp
    main.cpp
    src/FitnessApp.cpp
    src/RegisterUser.cpp
    src/LoginUser.cpp
    src/BMICalculator.cpp
    src/BodyTypeOptions.cpp
    src/Ectomorph.cpp
    src/Mesomorph.cpp
    src/Endomorph.cpp
)

# Find SQLite3 package
find_package(SQLite3 REQUIRED)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/src ${SQLite3_INCLUDE_DIRS})

# Link SQLite3 library
target_link_libraries(FitnessApp ${SQLite3_LIBRARIES})

