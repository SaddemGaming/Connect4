#!/bin/bash

set -e  # Exit immediately if a command exits with a non-zero status

echo "=== Connect4 Project Setup and Build Script ==="

# Update package manager
echo "Updating package lists..."
sudo apt update

# Install dependencies
echo "Installing required packages..."
sudo apt install -y build-essential cmake qt6-base-dev git

# Navigate to the script's directory (Connect4 root)
SCRIPT_DIR="$(dirname "$(realpath "$0")")"
cd "$SCRIPT_DIR"

# Clone googletest
EXTERNEL_DIR="external"
cd "$EXTERNEL_DIR"
if [ ! -d "gtest" ]; then
    echo "Cloning googletest..."
    git clone git@github.com:google/googletest.git gtest
fi
cd "$SCRIPT_DIR"

# Create and navigate to the build directory
BUILD_DIR="build"
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi
cd "$BUILD_DIR"

# Configure the project with CMake
echo "Configuring the project..."
cmake ..

# Build the project
echo "Building the project..."
make -j$(nproc)

echo "=== Build Complete ==="

# Run the application
APP_EXECUTABLE="./Connect4"
if [ -f "$APP_EXECUTABLE" ]; then
    echo "Launching the Connect4 application..."
    $APP_EXECUTABLE
else
    echo "Application not found. Build might have failed."
fi


echo "=== Setup and Build Completed Successfully ==="
