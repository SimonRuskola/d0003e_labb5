

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

void lightUpdate(lightsObject* self){
    if(self->direction == north){
        self->direction == south;
        self->southLight = 1;
        //send info to pc about light switch
    }else if(self->direction == south){
        self->direction == north;
        self->northLight = 1;
         //send info to pc about light switch
    }
}

void updateLCD(lightsObject* self){
    printAt(self->carsNorth,0);
    printAt(self->carsOnBridge,2);
    printAt(self->carsSouth,4);
}