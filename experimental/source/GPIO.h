//
//  GPIO.h
//  GPIO Class
//
//  Created by Daniel Duhon on 10/21/18.
//

#ifndef GPIO_h
#define GPIO_h
#include <string>

using namespace std;

class GPIOClass {
public:
    GPIOClass();
    GPIOClass(string x);
    int exportGPIO();
    int unexportGPIO();
    int setDirGPIO(string dir);
    int setValGPIO(string val);
    int getValGPIO(string& val);
private:
    string GPIONum;
};

#endif /* GPIO_h */
