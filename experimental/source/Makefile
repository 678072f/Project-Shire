all: main.o serial.o
	g++ main.o serial.o -o shire_d

main.o: main.cpp
	g++ -c main.cpp

serial.o: serial.cpp serial.h
	g++ -c serial.cpp
