#include "AnalogIn.h"
#include "Initialize.h"
#include "Uart.h"
#include <plib.h>

#define DESIRED_BAUDRATE_NU32 115200 // Baudrate

void initialize()
{
    initializePic();
    initializePorts();
    initializePWM();
    initializeTimers();
    initializeUart();
    initializeAnalogIn();
}

void initializeAnalogIn()
{
}

void initializePic()
{
    SYSTEMConfig(SYS_FREQ, SYS_CFG_ALL);
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
    INTEnableSystemMultiVectoredInt();
}

void initializePorts()
{
}

void initializePWM()
{
}

void initializeTimers()
{
}

void initializeUart()
{
}