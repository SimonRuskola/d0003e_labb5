
#include "run.h"



void run(runObj* self){
    USART_Init ( MYUBRR );
    LCD_Init();

    INSTALL(self,interupts, IRQ_USART0_RX);
    INSTALL(self,interupts, IRQ_USART0_UDRE);
    INSTALL(self,interupts, IRQ_USART0_TX);
    

    while(1){

    }

}


void interupts(runObj* self){

}
