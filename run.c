
#include "run.h"



void run(runObj* self){
    USART_Init ( MYUBRR );
    LCD_Init();

    INSTALL(self,interupts, IRQ_USART0_RX);
    INSTALL(self,interupts, IRQ_USART0_UDRE);
    INSTALL(self,interupts, IRQ_USART0_TX);

    unsigned int test;

    USART_Transmit(23);
    test = USART_Receive();
    printAt(test, 2);
    while(1){

    }

}


void interupts(runObj* self){

}
