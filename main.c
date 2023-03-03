
#include "usart.h"
#include <avr/io.h>
#include "run.h"


runObj mainObj = initRun;


void main( void )
{

    TINYTIMBER(*mainObj, run, NULL);

}
