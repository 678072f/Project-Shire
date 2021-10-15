// Serial Communications Link V1.0
// Daniel Duhon, 10/14/2021
// Serial Class

#include <stdlib.h>
#include "serial.h"

using namespace Shire;

Serial::Serial(void) {
    // Constructor: Setup serial connection here.
    std::cout << "Opening serial port...\n";
    
    serialPort = open("/dev/ttyACM0", O_RDWR); // Open serial at /dev/ttyACM0 (Default)
    
    // Read existing settings and handle errors.
    if(tcgetattr(serialPort, &arduino) != 0) {
        std::printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }
    
    // C_FLAGS
    arduino.c_flag |= PARENB; // Set parity bit.
    arduino.c_flag &= ~CSTOPB; // Clear stop field, use one stop bit.
    arduino.c_flag |= CS8; // Set 8 bits per byte.
    arduino.c_flag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control.
    arduino.c_flag |= CREAD | CLOCAL; // Turn on READ and disable ctrl lines.
    
    // C_LFLAGS
    arduino.c_lflag &= ~ICANON; // Disable canonical mode.
    arduino.c_lflag &= ~ECHO; // Disable echo.
    arduino.c_lflag &= ~ECHOE; // Disable erasure.
    arduino.c_lflag &= ~ECHONL; // Disable new-line echo.
    arduino.c_lflag &= ~ISIG; // Disable INTR, QUIT, and SUSP.
    
    // Input modes
    arduino.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off software flow control.
    arduino.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INCLR | IGNCR | ICRNL); // Disable special handling of received bits.
    
    // Output Modes
    arduino.c_oflag &= ~OPOST; // Disable special interpretation of output.
    arduino.c_oflag &= ~ONLCR; // Prevent conversion of new-line characters to carriage return.
    
    arduino.c_cc[VTIME] = 50; // Wait up to 5 seconds.
    arduino.c_cc[VMIN]
    
    cfsetspeed(&arduino, B9600); // Set Baud rate (9600 for arduino)
}

double Serial::readSerial(void) {
    // Read data from serial port and store to variable.
    std::cout << "Do stuff...\n";
    return data;
}

void Serial::writeSerial(double data, std::string dataString) {
    // Write data to serial.
    std::cout << "Do stuff...\n";
    serialData = data;
    serialDataString = dataString;
}

void Serial::setSerialPort(int port) {
    serialPort = open(port, O_RDWR); // For modifying the serial port.
}

Serial::~Serial() {
    // Destructor: Uninitialize serial connection here.
    std::cout << "Closing serial port...\n";
}
