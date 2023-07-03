cmake_minimum_required(VERSION 3.10)
project(SpaceBattle)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    src/SpaceShip.cpp
)

# Add test files
set(TEST_SOURCES
    src/SpaceBattleTest.cpp
)

# Include directories
include_directories(include)

# Find Google Test package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create executable for tests
add_executable(SpaceBattleTest ${TEST_SOURCES} ${SOURCES})
target_link_libraries(SpaceBattleTest ${GTEST_BOTH_LIBRARIES})
