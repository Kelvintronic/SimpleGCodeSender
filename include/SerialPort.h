#ifndef SERIALPORT_H
#define SERIALPORT_H

#define ARDUINO_WAIT_TIME 2000
#define MAX_DATA_LENGTH 1000

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <iostream>
#include <string.h>
#include <chrono>
#include <thread>
#include <time.h>

using namespace std;

class SerialPort
{
private:
    HANDLE handler;
    bool connected;
    COMSTAT status;
    DWORD errors;
public:
    SerialPort(string portName);
    ~SerialPort();

    string readSerialPort();
    bool writeSerialPort(char *buffer, unsigned int buf_size);
    bool isConnected();
    bool isData();

};

#endif // SERIALPORT_H

