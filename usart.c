
#include "usart.h"
#include <avr/io.h>



void USART_Init(serialObj* self)
{
/* Set baud rate */
UBRR0H = (unsigned char)(MYUBRR>>8);
UBRR0L = (unsigned char)MYUBRR;
/* Enable receiver and transmitter  and enables interupts*/
UCSR0B = (1<<RXEN0)|(1<<TXEN0) | (1 << RXCIE0) | (1 << TXCIE0);
/* Set frame format: 8 data, 1 stop bit */
UCSR0C = (0<<USBS0)|(3<<UCSZ00)|(0<<4)|(0<<5); // upm1/upm0

}


unsigned int USART_Receive(serialObj* self)
{
unsigned char status, resh, resl;
/* Wait for data to be received */
//while ( !(UCSR0A & (1<<RXC0)) );
/* Get status and 9th bit, then data */
/* from buffer */
status = UCSR0A;
resh = UCSR0B;
resl = UDR0;
/* If error, return -1 */
if ( status & (1<<FE0)|(1<<DOR0)|(1<<UPE0) ){
    return -1;
}
/* Filter the 9th bit, then return */
resh = (resh >> 1) & 0x01;
return ((resh << 8) | resl  ); 
self->inData = UDR0;
}


void USART_Transmit(serialObj* self, unsigned int data )
{
/* Wait for empty transmit buffer */
while ( !( UCSR0A & (1<<UDRE0))) ;
/* Copy 9th bit to TXB8 */
UCSR0B &= ~(1<<TXB80);
if ( data & 0x0100 ){
    UCSR0B |= (1<<TXB80);
}
/* Put data into buffer, sends the data */
UDR0 = data;
}



void USART_Flush( void )
{
unsigned char dummy;
while ( UCSR0A & (1<<RXC0) ) dummy = UDR0;
}


void pushToSerial(unsigned int data){
	
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
		

}


int pullFromSerial(void){
	
	LCDDR0 ^= (1 << 1);
	
	while(!(UCSR0A & (1<<RXC0)));
	
	return UDR0;
			
}