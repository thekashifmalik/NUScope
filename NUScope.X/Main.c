//NUScope

//Set configuration bits
#pragma config FWDTEN = OFF //Disable WDT timer
#pragma config ICESEL = ICS_PGx2
#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_1
#pragma config FPBDIV = DIV_1
#pragma config POSCMOD = XT, FNOSC = PRIPLL

//Libraries
#include "Initialize.h"
#include <plib.h>

//Global variables


int main(void)
{
    initialize();
    while(1)
    {
    }
}

//ISRs