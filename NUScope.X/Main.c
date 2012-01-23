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

//Function prototypes
void reset();


//Global variables
int SendIndex;
int Done = 1;
//Parameters
int Frequency = 10;
int Limit = 50;


int main(void)
{
    initialize();
    while(1)
    {
        if (Done)
        {
            reset();
            Done = 0;
        }
    }
}

//Functions
void reset()
{
    closeTimer(2);
    SendIndex = 0;
}

//ISRs

void __ISR(_TIMER_2_VECTOR, ipl3) Send(void)
{
    SendCharacter(1, '1');
    SendIndex++;
    if (SendIndex == Limit)
    {
        Done = 1;
    }
    mT2ClearIntFlag();
}

void __ISR(_UART_1_VECTOR, ipl2) Uart1Handler(void)
{
    if(INTGetFlag(INT_SOURCE_UART_RX(UART1)))
    {
        char data = UARTGetDataByte(UART1);
        switch(data)
        {
            //Start
            case '1':
                setupTimer(2, Frequency, 3);
                break;
                

            default:
                break;
        }

        INTClearFlag(INT_SOURCE_UART_RX(UART1));
    }

    if(INTGetFlag(INT_SOURCE_UART_TX(UART1)))
    {
        INTClearFlag(INT_SOURCE_UART_TX(UART1));
    }
}