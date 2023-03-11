
#include "run.h"



void test(runObj* self){
    printAt(23,0);
}


void run(runObj* self){
    LCD_Init();
    USART_Init (self->serial);

    INSTALL(self->lights, sensorRead, IRQ_USART0_RX);

    //ASYNC(self, test, NULL);

    

    //INSTALL(self,interupts, IRQ_USART0_RX);
    //INSTALL(self,interupts, IRQ_USART0_UDRE);
    //INSTALL(self,interupts, IRQ_USART0_TX);
    printAt(0, 4);

    //unsigned int test;

    //test = USART_Receive();
    //USART_Transmit(self->serial,0xA);
    //int i = 1;
    

        //pushToSerial(i);
        //i++;
        //test = pullFromSerial;
        //USART_Flush();
        //printAt(test,0);

        //pushToSerial(0x1);
    

}


