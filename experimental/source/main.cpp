// Project-Shire V0.0.1a
// Daniel Duhon 2021

#include <iostream>
#include <math.h>
#include "serial.h"

int main() {
	std::cout << "Project-Shire Software V0.0.1c" << std::endl;

    Shire::Serial test;
    
    char * serialPort1 = "/dev/ttyACM0";
    char data1;
    int n;
    
    test.setSerialPort(serialPort1);
    test.openSerialPort();
    test.readSerial(n);
    
    data1 = test.getSerialData();
    
    std::cout << data1 << std::endl;
    
//    FUTURE IMPLEMENTATION
//	// constants: (to be replaced by constants_config.conf)
//	const double g[3] = {0, 0, 32.174};
//	const double T_isa = 59;
//	const double P_isa = 2116.22;
//	const double p_isa = 0.002377;
//	const double gamma = 1.40;

	// Math:
//	double fluidElement[][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
//
//	double matrixMult(double mat1[], double mat2[]);
//	double matrixMult(double mat1, double mat2) {
//		for(int i = 0; i < sizeof(mat1); i++)
//			for(int j = 0; j < sizeof(mat2[0]); j++) {
//			//TODO:Finish Loop and function
//			}
			
//	}

	return 0;
}
