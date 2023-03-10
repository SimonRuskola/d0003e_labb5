

#include "TinyTimber.h"
#include "usart.h"

#define initLightsObject(serial) {initObject(),serial,0,0,0,0,0,0}

#define north 1
#define south 0
#define green 1
#define red   0

typedef struct {
    Object super;
    serialObj* serial;
    int carsOnBridge;
    int carsNorth;
    int carsSouth;
    int southLight;
    int northLight;
    int direction;

} lightsObject;


void carToBridge(lightsObject* self, int direction);
void carOffBridge(lightsObject* self);
void lightUpdate(lightsObject* self);
void updateLCD(lightsObject* self);