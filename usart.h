

#include "TinyTimber.h"



#define FOSC 8000000// Clock Speed
#define BAUD 9600
#define MYUBRR (FOSC/16/BAUD-1)


typedef struct{
    Object super;
    int inData;
    int outData;
} serialObj;

#define initUsart {initObject(), 0, 0}


void USART_Echo();
void USART_Init(serialObj* self);
unsigned int USART_Receive(serialObj* self);
void USART_Transmit(serialObj* self, unsigned int data );
void pushToSerial(unsigned int data);
int pullFromSerial(void);
void USART_Flush( void );