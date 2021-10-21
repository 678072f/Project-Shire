all: ../bin/main.o ../bin/serial.o
	g++ -v -std=c++17 ../bin/*.o -o ../bin/shire_d

../bin/main.o: main.cpp
	g++ -c -v -std=c++17 main.cpp -o ../bin/main.o

../bin/serial.o: serial.cpp serial.h
	g++ -c -v -std=c++17 serial.cpp -o ../bin/serial.o
