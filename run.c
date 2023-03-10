
#include "run.h"


void sensorRead(runObj* self){
    SYNC(self->serial, USART_Receive, NULL );

	if(self->serial->inData & (1)){ // true if north car arrival
        self->lights->carsNorth++;
		    
	}if(self->serial->inData & (1<<1)){ // true if north car bridge entry
        self->lights->carsNorth--;
        self->lights->carsOnBridge++;

	}if(self->serial->inData & (1<<2)){ // true if south car arrival
        self->lights->carsSouth++;

	}if(self->serial->inData & (1<<3)){ // true if south car bridge entry
        self->lights->carsSouth--;
        self->lights->carsOnBridge++;

	}

	

}

void run(runObj* self){
    LCD_Init();
    USART_Init (self->serial);

    INSTALL(self, sensorRead, IRQ_USART0_RX);

    ASYNC(self->lights, lightUpdate, NULL);

    //INSTALL(self,interupts, IRQ_USART0_RX);
    //INSTALL(self,interupts, IRQ_USART0_UDRE);
    //INSTALL(self,interupts, IRQ_USART0_TX);
    printAt(0, 4);

    //unsigned int test;

    //test = USART_Receive();
    //USART_Transmit(self->serial,0xA);
    //int i = 1;
    while(1){

        //pushToSerial(i);
        //i++;
        //test = pullFromSerial;
        //USART_Flush();
        //printAt(test,0);

        //pushToSerial(0x1);
    }

}


