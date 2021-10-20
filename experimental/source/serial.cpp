// Serial Communications Link V1.1
// Daniel Duhon, 10/19/2021
// Serial Class

// Included libraries
#include "serial.h"

using namespace Shire;

Serial::Serial(char * serial) {
    // Constructor: Setup serial connection here.
    
    serialPortDir = serial;
}

void Serial::openSerialPort() {
    std::cout << "Opening serial port at " << serialPortDir << std::endl;
    
    serialPort = open(serialPortDir, O_RDWR);
    
    // Read existing settings and handle errors.
    if(tcgetattr(serialPort, &arduino) != 0) {
        std::printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }
    
    // C_FLAGS
    arduino.c_cflag |= PARENB; // Set parity bit.
    arduino.c_cflag &= ~CSTOPB; // Clear stop field, use one stop bit.
    arduino.c_cflag |= CS8; // Set 8 bits per byte.
    arduino.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control.
    arduino.c_cflag |= CREAD | CLOCAL; // Turn on READ and disable ctrl lines.
    
    // C_LFLAGS
    arduino.c_lflag &= ~ICANON; // Disable canonical mode.
    arduino.c_lflag &= ~ECHO; // Disable echo.
    arduino.c_lflag &= ~ECHOE; // Disable erasure.
    arduino.c_lflag &= ~ECHONL; // Disable new-line echo.
    arduino.c_lflag &= ~ISIG; // Disable INTR, QUIT, and SUSP.
    
    // Input modes
    arduino.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off software flow control.
    arduino.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL); // Disable special handling of received bits.
    
    // Output Modes
    arduino.c_oflag &= ~OPOST; // Disable special interpretation of output.
    arduino.c_oflag &= ~ONLCR; // Prevent conversion of new-line characters to carriage return.
    
    arduino.c_cc[VTIME] = 50; // Wait up to 5 seconds.
    arduino.c_cc[VMIN];
    
    cfsetspeed(&arduino, B9600); // Set Baud rate (9600 for arduino)
    // Save tty settings and check for errors.
    if(tcsetattr(serialPort, TCSANOW, &arduino) != 0) {
        std::printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }
}

// Read data from serial port and store to variable.
void Serial::readSerial() {
    std::cout << "Reading from serial at " << serialPortDir << std::endl;
    
    // Counts number of bytes received.
    numberRead = read(serialPort, &serialDataIn, sizeof(&serialDataIn));
}

void Serial::writeSerial(unsigned char data) {
    // Write data to serial.
    std::cout << "Writing to serial at " << serialPortDir << std::endl;
    serialDataOut = data;
    
    write(serialPort, &serialDataOut, sizeof(serialDataOut));
}

// Allows for use and output of Serial::serialDataIn variable.
char Serial::getSerialData() {
    char data = *serialDataIn;
    return data;
}

int Serial::getNumberRead() {
    int number = numberRead;
    return number;
}

Serial::~Serial() {
    // Destructor: Uninitialize serial connection here.
    std::cout << "Closing serial port at " << serialPortDir << std::endl;
    
    close(serialPort);
}
