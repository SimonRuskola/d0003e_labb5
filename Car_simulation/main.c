


#define PATH "/dev/ttyS2"

#include <termios.h>
//#include <sys/termios.h>
//#include <sys/termios.h>
//#include "sysroot/usr/include/termios.h"
//#include "C:\cygwin64\usr\include\termios.h"

//#include </usr/include/machine/termios.h>
//#include </usr/include/sys/termios.h>
//#include </usr/include/termios.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <io.h>



int openFile(){

    int temp = open(PATH, O_RDWR);
	
	if(temp >= 0){
		printf("Sucsess!\n");
	}
	else{
		printf("Could not open the file\n");
	}
	
	return temp;
}




void main( void )
{

   //printf("Hello World!");
   struct termios test;
   int fildes = 5;
   
   
   int tcgetattr(fildes, termios);


int tcsetattr(int fildes, int optional_actions,
	const struct termios *termios_p);


int tcsendbreak(int fildes, int duration);


int tcdrain(int fildes);


int tcflush(int fildes, int queue_selector);


int tcflow(int fildes, int action);


speed_t cfgetospeed(const struct termios *termios_p);


int cfsetospeed(struct termios *termios_p, speed_t speed);


speed_t cfgetispeed(const struct termios *termios_p);


int cfsetispeed(struct termios *termios_p, speed_t speed);


   
   //int file = openFile();
   //printf("%d",3);
   //printf("%d",file);



}


void parseData(int* input, int* output, int* northQueue, int* southQueue, int* northIncomming, int* southIncomming, int* northLeft, int* southLeft, int *localChanged){
	
	*output = 0b0000;
	
	if(checkTimeOut()){
		if(getLightState(input, NORTH) && *northQueue){
			carOnBridge(NORTH);
			letCarOverBridge(output, northQueue, northLeft, NORTH);
			*localChanged = 1;
			
		}
		if(getLightState(input, SOUTH) && *southQueue){
			carOnBridge(SOUTH);
			letCarOverBridge(output, southQueue, southLeft, SOUTH);
			*localChanged = 1;
		}
	}
	
	if(*northIncomming){
		addCarToQueue(output, northQueue, northIncomming, NORTH);
		*localChanged = 1;
	}
	
	if(*southIncomming){
		addCarToQueue(output, southQueue, southIncomming, SOUTH);
		*localChanged = 1;
	}
	
	if(carCrash(output)){
		printf("Full fart framåt o inga bromsar!!  ÅÅÅÅNEEEEJ BARN FAMILJEN\n");
		*localChanged = 1;
	}
	
}
