

#include "TinyTimber.h"



//typedef struct{
//    Object super;
//    int inData;
//    int outData;
//} serialObj;


void USART_Init( unsigned int ubrr);
unsigned int USART_Receive( void );
void USART_Transmit( unsigned int data );
void pushToSerial(unsigned int data);
int pullFromSerial(void);
void USART_Flush( void );