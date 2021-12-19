// Project-Shire V0.0.1c
// Daniel Duhon 2021
// Last Updated: 10/19/2021

#include "general.h"

int main() {
	std::cout << "Project-Shire Software Version V" << Shire::versionNumber << " (" << Shire::buildNumber << ")"<< std::endl;

    char * serialPort1 = "/dev/ttyACM0";
    
    Shire::Serial test1(serialPort1);
   // Shire::Serial test2(serialPort2);
    
    unsigned char data1;
   // unsigned char data2;
//    int n = 256; // Test Buffer Size
    
    test1.openSerialPort();
   // test2.openSerialPort();
    
    unsigned int testData1[] = { 1 };
    
    test1.writeSerial(*testData1);
   // test2.writeSerial(*testData2);
    test1.readSerial();
   // test2.readSerial();
    
    data1 = test1.getSerialData();
   // data2 = test2.getSerialData();
    while(1) {
    std::cout << data1 << '\t' << testData1 << std::endl;
   // std::cout << data2 << '\t' << testData2 << std::endl;
    int i = 0;
    std::cin >> i;
    if(i == 1)
        test1.writeSerial(*testData1);
    }
    
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
