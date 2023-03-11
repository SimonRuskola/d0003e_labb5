

#include "TinyTimber.h"
#include "usart.h"

#define initLightsObject(serial) {initObject(),serial,0,0,0,0,0,2,0,0}

#define north 1
#define south 0
#define green 1
#define red   0
#define noDirection 2

typedef struct {
    Object super;
    serialObj* serial;
    int carsOnBridge;
    int carsNorth;
    int carsSouth;
    int southLight;
    int northLight;
    int direction;
    int carsRow;
    int bridgeLock;

} lightsObject;


startCars(lightsObject* self);
void sensorRead(lightsObject* self);
void carToBridge(lightsObject* self, int direction);
void carOffBridge(lightsObject* self);
void lightUpdate(lightsObject* self);
void updateLCD(lightsObject* self);