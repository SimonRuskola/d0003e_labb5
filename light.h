

#include "TinyTimber.h"

#define initPulseGenerator {initObject(),0,0,0,0,0}

typedef struct {
    Object super;
    int carsOnBridge;
    int carsNorth;
    int carsSouth;
    int southLight;
    int northLight;

} lightsObject;