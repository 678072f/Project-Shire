all: ../bin/main.o ../bin/serial.o
	g++ -v ../bin/{main.o,serial.o} -o ../bin/shire_d

../bin/main.o: main.cpp
	g++ -c -v main.cpp -o ../bin/main.o

../bin/serial.o: serial.cpp serial.h
	g++ -c -v serial.cpp -o ../bin/serial.o
