#!/bin/bash

# Check if the script is run with sudo privileges
if [ "$(id -u)" -ne 0 ]; then
    echo "This script requires sudo permissions to setup."
    echo "Please run the script with 'sudo' command."
    exit 1
fi

# Copy the file "../dist/cavg/" to /usr/bin
cp dist/cavg /usr/bin/

# Inform the user and request a restart
echo "CAVG has now been set up."
echo "You can now run 'cavg' from the terminal."
echo "Press enter to continue..."
read