cmake_minimum_required(VERSION 3.14)

# Project details
project(Connect4 LANGUAGES CXX)

# Define the path to the external libraries
set(LIBRARY_PATH ${CMAKE_SOURCE_DIR}/external/lib)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 Widgets package
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Define source, header, and UI files for the application
set(SOURCES
    src/main.cpp
    src/MainWindow.cpp
    src/PlayerSetup.cpp
    src/GameScreen.cpp
    src/EndGame.cpp
    src/GameBoard.cpp
    src/HumanPlayer.cpp
    src/ComputerPlayer.cpp
    src/HorizontalWinStrategy.cpp
    src/VerticalWinStrategy.cpp
    src/DiagonalWinStrategy.cpp
)

set(HEADERS
    inc/MainWindow.h
    inc/PlayerSetup.h
    inc/GameScreen.h
    inc/EndGame.h
    inc/GameBoard.h
    inc/Player.h
    inc/HumanPlayer.h
    inc/ComputerPlayer.h
    inc/WinConditionStrategy.h
    inc/HorizontalWinStrategy.h
    inc/VerticalWinStrategy.h
    inc/DiagonalWinStrategy.h
)

# UI files
set(UIS
    ${CMAKE_SOURCE_DIR}/ui/MainWindow.ui
    ${CMAKE_SOURCE_DIR}/ui/PlayerSetup.ui
    ${CMAKE_SOURCE_DIR}/ui/GameScreen.ui
    ${CMAKE_SOURCE_DIR}/ui/EndGame.ui
)

message(STATUS "UI Files: ${UIS}")

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_BINARY_DIR} # For generated UI files
)

# Enable Qt6 features for automatic MOC, UIC, and RCC processing
set(CMAKE_AUTOMOC ON)

# Ensure UI files are wrapped
qt6_wrap_ui(UI_HEADERS ${UIS})

# Add executable target for the main application
add_executable(Connect4 ${SOURCES} ${HEADERS} ${UI_HEADERS})

# Link against Qt6 Widgets library
target_link_libraries(Connect4 PRIVATE Qt6::Widgets)

# Add Google Test submodule
add_subdirectory(external/gtest)

# Define test source files
set(TEST_SOURCES
    tests/GameBoardTest.cpp
    tests/PlayerTest.cpp
)

# Add test executable
add_executable(GameLogicTests
    ${TEST_SOURCES}
    src/GameBoard.cpp   # Include GameBoard implementation
    src/HumanPlayer.cpp # Include HumanPlayer implementation
    src/ComputerPlayer.cpp # Include ComputerPlayer implementation
    src/HorizontalWinStrategy.cpp
    src/VerticalWinStrategy.cpp
    src/DiagonalWinStrategy.cpp
)

# Include directories for tests
target_include_directories(GameLogicTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# Link Google Test libraries and application logic to tests
target_link_libraries(GameLogicTests PRIVATE
    gtest
    gtest_main
)

# Enable testing
enable_testing()

# Add test cases
add_test(NAME GameLogicTests COMMAND GameLogicTests)

# Optional: Display configuration details
message(STATUS "Configured Connect4 with Google Test support.")
