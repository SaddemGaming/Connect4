#!/bin/bash

set -e  # Exit immediately if a command exits with a non-zero status

echo "=== Connect4 Project Setup and Build Script ==="

# Function to check if a package is installed
is_installed() {
    dpkg -l | grep -qw "$1"
}

# Update package manager only if necessary
if ! is_installed "build-essential" || ! is_installed "cmake" || ! is_installed "qt6-base-dev" || ! is_installed "git"; then
    echo "Updating package lists..."
    sudo apt update
else
    echo "All required packages are already installed."
fi

# Install dependencies if not already installed
echo "Checking for required packages..."
for package in build-essential cmake qt6-base-dev git; do
    if ! is_installed "$package"; then
        echo "Installing $package..."
        sudo apt install -y "$package"
    else
        echo "$package is already installed."
    fi
done

# Navigate to the script's directory (Connect4 root)
SCRIPT_DIR="$(dirname "$(realpath "$0")")"
cd "$SCRIPT_DIR"

# Clone googletest if not already cloned
EXTERNEL_DIR="external"
GTEST_DIR="$EXTERNEL_DIR/gtest"

if [ ! -d "$GTEST_DIR" ] || [ -z "$(ls -A "$GTEST_DIR")" ]; then
    echo "Cloning googletest..."
    mkdir -p "$EXTERNEL_DIR"
    cd "$EXTERNEL_DIR"
    rm -rf gtest
    git clone https://github.com/google/googletest.git gtest
    cd "$SCRIPT_DIR"
else
    echo "googletest is already cloned and not empty."
fi

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
