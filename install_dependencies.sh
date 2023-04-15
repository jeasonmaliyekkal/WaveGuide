#!/bin/bash
echo "This will install the dependencies for WaveGuide".
echo "This requires sudo privileges."
echo "REQUIRED : libopencv-dev libx11-dev libxtst-dev"

# Update package lists
sudo apt-get update



# Install OpenCV,X11 and XTest libraries
sudo apt-get install -y libopencv-dev libx11-dev libxtst-dev