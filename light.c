

#include "light.h"
#include "TinyTimber.h"
#include "lcd.h"

void carToBridge(lightsObject* self, int direction){
    self->direction = direction;
    if(direction == north){
        self->carsNorth--;
        self->carsOnBridge++;
    }else if(direction == south){
        self->carsSouth--;
        self->carsOnBridge++;
    }
    AFTER(MSEC(5000),self, carOffBridge, NULL);
    updateLCD(self);

}
void carOffBridge(lightsObject* self){
    self->carsOnBridge--;
    if(self->carsOnBridge==0){
        self->northLight = 0;
        self->southLight = 0;
        ASYNC(self, lightUpdate, NULL);
    }
    updateLCD(self);
}


void switchLight(lightsObject* self){
    if(self->direction == north){
        self->direction == south;
    }else{
        self->direction == north;
    }

    ASYNC(self, nextLight, 1);

}

void nextLight(lightsObject* self, int i){

    if(i >= 5){
        AFTER(MSEC(5000),self, switchLight, NULL);
    }else{
        if(self->direction == north){
            ASYNC(self->serial, USART_Transmit, 0x9) // 0x9 = 1001  green north and red south on
            ASYNC(self->serial, USART_Transmit, 0x5) // 0x5 = 0101 all red on and green off
        }else if(self->direction == south){
            ASYNC(self->serial, USART_Transmit, 0x6) // 0x6 = 0110 green south and red north on
            ASYNC(self->serial, USART_Transmit, 0x5) // 0x5 = 0101 all red on and green off
        }

        AFTER(MSEC(1000),self, nextLight, i+1);

    }


    
}

void lightUpdate(lightsObject* self){
    if(self->carsNorth>=self->carsSouth){
        ASYNC(self->serial, USART_Transmit, 0x9) // 0x9 = 1001  green north and red south on
        ASYNC(self->serial, USART_Transmit, 0x5) // 0x5 = 0101 all red on and green off
        self->direction = north; 
    }else{
        ASYNC(self->serial, USART_Transmit, 0x6) // 0x6 = 0110 green south and red north on
        ASYNC(self->serial, USART_Transmit, 0x5) // 0x5 = 0101 all red on and green off
        self->direction = south;
    }


    AFTER(MSEC(1000),self, nextLight, 1);

    
}



void updateLCD(lightsObject* self){
    printAt(self->carsNorth,0);
    printAt(self->carsOnBridge,2);
    printAt(self->carsSouth,4);
}