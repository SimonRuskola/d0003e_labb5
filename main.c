
#include <avr/io.h>
#include "run.h"




serialObj serial  = initUsart; 
lightsObject lights = initLightsObject(&serial);
runObj mainObj = initRun(&serial, &lights);




int main( void )
{
    //LCD_Init();
    //USART_Init(&serial);
    //while (1)
    //{
    //    USART_Echo();
    //}
    
    
    TINYTIMBER(&mainObj, run, NULL);

    //while (1)
    //{
        
    //}
    

}


