CC=g++
CFLAGS=-v -Wall -std=c++17
DEBUGDIR=../debug
DIR=../bin


all: $(DIR)/main.o $(DIR)/serial.o $(DIR)/controls.o
	$(CC) $(CFLAGS) ../bin/*.o -o $(DIR)/shire

$(DIR)/main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp -o $(DIR)/main.o

$(DIR)/serial.o: serial.cpp serial.h
	$(CC) -c $(CFLAGS) serial.cpp -o $(DIR)/serial.o
	
$(DIR)/controls.o: controls.cpp controls.h
	$(CC) -c $(CFLAGS) controls.cpp -o $(DIR)/controls.o
	
	
debug: $(DEBUGDIR)/main.o $(DEBUGDIR)/serial.o $(DEBUGDIR)/controls.o
	$(CC) $(CFLAGS) $(DEBUGDIR)/*.o -o $(DEBUGDIR)/shire_d
	
$(DEBUGDIR)/main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp -o $(DEBUGDIR)/main.o
	
$(DEBUGDIR)/serial.o: serial.cpp serial.h
	$(CC) -c $(CFLAGS) serial.cpp -o $(DEBUGDIR)/serial.o
	
$(DEBUGDIR)/controls.o: controls.cpp controls.h
	$(CC) -c $(CFLAGS) controls.cpp -o $(DEBUGDIR)/controls.o

clean:
	rm -rf $(DIR)/*.o $(DEBUGDIR)/*.o $(DIR)/shire $(DEBUGDIR)/shire_d
