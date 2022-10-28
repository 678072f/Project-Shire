#!/bin/bash

declare -a packages("arduino" "make" "git" "gcc" "python3" "python3-dev" "python3-pip" "python3-matplotlib" "python3-numpy")

for i in "${packages[@]}"; do
    if ! dpkg-query -W -f='${Status}' $i 2>/dev/null | grep -q "ok installed"; then
        echo "$i is not installed. Installing..."
        sudo apt-get install "$i"
    else
        echo "$i is installed."
    fi
done
