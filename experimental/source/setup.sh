#!/bin/bash

pkgs=( "gcc" "make" "python3" "python3-pip" "xserver-xorg" "git" "python3-sympy" "python3-numpy")

for i in "${pkgs[@]}"; do
	if [[ "$(which $i)" != "" ]]; then
		echo "$i is installed"
	else
		sudo apt install $i -y
	fi
done
