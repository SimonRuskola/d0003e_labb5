
#include "usart.h"
#include <avr/io.h>
#include "lcd.h"



#define FOSC 1843200// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1


void main( void )
{

LCD_Init();
USART_Init ( MYUBRR );
int temp;
while (1)
{
    USART_Transmit(5);
    temp =USART_Receive();
    printAt(temp,0);
}



}
