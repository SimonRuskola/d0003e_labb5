
#include "usart.h"
#include <avr/io.h>
#include "lcd.h"



void USART_Init(serialObj* self)
{
/* Set baud rate */
//UBRR0H = (unsigned char)(MYUBRR>>8);
UBRR0L = (unsigned char)(((8000000/16)/9600)-1);



/* Enable receiver and transmitter  and enables interupts*/
UCSR0B |= (1<<RXEN0)|(1<<TXEN0);  // receiver and transmitter 
UCSR0B |= (1 << RXCIE0);          //interupts
//UCSR0B |= (1 << TXCIE0);          // transmit inter



/* Set frame format:  */
UCSR0C &= ~(1<<USBS0);   //   1 stop bit 
UCSR0C |= (1<<UCSZ00); 
UCSR0C |= (1<<UCSZ01); // 8 data,

}


unsigned int USART_Receive(serialObj* self)
{
	while(!(UCSR0A & (1<<RXC0)));
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


void USART_Echo(){


    if((UCSR0A & (1<<RXC0))>0){
		unsigned char data = UDR0;
		writeLong(data);
		while ( !( UCSR0A & (1<<UDRE0))) ;
		//UDR0 = 'A';
		UDR0 = data;

	}
    


	
        
    
    
	


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