// Serial Communications Link V2.0
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
    
    struct termios arduino;
    
    serialPort = open(serialPortDir, O_RDWR);
    
    // Read existing settings and handle errors.
    if(serialPort < 0) {
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
char Serial::readSerial() {
    std::cout << "Reading from serial at " << serialPortDir << std::endl;
    
    // Counts number of bytes received.
    numberRead = read(serialPort, &serialDataIn, sizeof(&serialDataIn));
    std::cout << numberRead << '\n';
    
    return read(serialPort, &serialDataIn, sizeof(&serialDataIn));
}

void Serial::writeSerial(char data) {
    // Write data to serial.
    serialDataOut = data;
    std::cout << "Writing " << data << " to serial at " << serialPortDir << std::endl;
    
    write(serialPort, &serialDataOut, sizeof(serialDataOut));
    std::cout << "Done..." << '\n';
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

// IO Variable Functions
void Serial::setElevatorDeflection(double deltaE) {
    
}


double Serial::getElevatorDeflection() {
    
}


void Serial::setAileronDeflection(double deltaA) {
    
}


double Serial::getAileronDeflection() {
    
}


void Serial::setRudderDeflection(double deltaR) {
    
}


double Serial::getRudderDeflection() {
    
}


void Serial::setThrottle(double deltaT) {
    
}


double Serial::getThrottle() {
    
}

// Status functions
bool Serial::checkElevatorStatus() {
    
}


bool Serial::checkAileronStatus() {
    
}


bool Serial::checkRudderStatus() {
    
}


bool Serial::checkThrottleStatus() {
    
}

// Destructor
Serial::~Serial() {
    // Destructor: Uninitialize serial connection here.
    std::cout << "Closing serial port at " << serialPortDir << std::endl;
    
    close(serialPort);
}
