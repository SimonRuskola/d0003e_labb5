
#include <avr/io.h>
#include "run.h"



serialObj serial  = initUsart; 
lightsObject lights = initLightsObject(&serial);
runObj mainObj = initRun(&serial, &lights);


int main( void )
{

    TINYTIMBER(&mainObj, run, NULL);

    while (1)
    {
        
    }
    

}
