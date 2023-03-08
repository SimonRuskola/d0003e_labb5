
#include "TinyTimber.h"
#include "lcd.h"
#include "usart.h"


#define FOSC 1843200// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

typedef struct{
	Object super;
    
} runObj;


#define initRun {initObject()}

void run(runObj* self);
void interupts(runObj* self);