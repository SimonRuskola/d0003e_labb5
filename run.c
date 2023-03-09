
#include "run.h"



void run(runObj* self){
    USART_Init ( MYUBRR );
    LCD_Init();

    //INSTALL(self,interupts, IRQ_USART0_RX);
    //INSTALL(self,interupts, IRQ_USART0_UDRE);
    //INSTALL(self,interupts, IRQ_USART0_TX);

    unsigned int test;

    //test = USART_Receive();
    //printAt(test, 2);
    int i = 1;
    while(1){

        pushToSerial(i);
        i++;
        test = pullFromSerial;
        USART_Flush();
        printAt(test,0);

        //pushToSerial(0x1);
        //USART_Transmit(0x1);
    }

}


void interupts(runObj* self){

}
