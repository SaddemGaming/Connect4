# Connect4 Game

Welcome to the **Connect4 Game** assignement!
This is a classic Connect4 game implemented with a graphical user interface using **Qt6**. The game also includes unit tests for game logic using **Google Test (gtest)**.

## Features
- **Player vs Player** mode.
- **Player vs Computer** mode with an AI opponent (random moves).
- A graphical board with real-time updates using Qt6.
- Automated tests to verify the correctness of game logic.

## Requirements
Before running the game, ensure you have the following installed on your system:
- A Linux environment (Ubuntu/Debian-based recommended).
- A C++17 compatible compiler (e.g., GCC).
- Basic build tools (`cmake`, `make`).

## Setup and Build Instructions
This project comes with a pre-configured setup script to handle dependencies, build the project, and run it. Follow these steps:

1. **Unzip the Project**:
   ```bash
   unzip Connect4.zip
   ```
   Navigate into the project directory:
   ```bash
   cd Connect4
   ```
2. **Make the Setup Script Executable**:
   The setup script is named `setup_and_build.sh`.
   You need to make it executable:
   ```bash
   chmod +x setup_and_build.sh
   ```
3. **Run the Setup Script**:
   Execute the script to install dependencies, build the project, and run the application:
   ```bash
   ./setup_and_build.sh
   ```
- The game will launch automatically after a successful build.
- The script will also run the unit tests to validate the game logic.

## Notes
- Ensure you have sudo access for installing required packages.
- The script is designed to work on Ubuntu/Debian-based systems. For other Linux distributions, you may need to adjust the dependency installation commands.




