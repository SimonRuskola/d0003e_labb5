
#include "TinyTimber.h"
#include "lcd.h"
#include "light.h"




typedef struct{
	Object super;
	serialObj* serial;
	lightsObject* lights;
    
} runObj;


#define initRun(serial, lights) {initObject(), serial, lights}

void run(runObj* self);