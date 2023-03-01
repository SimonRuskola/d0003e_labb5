


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

/*

int tcgetattr(int fildes, struct termios *termios_p);

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

#include <sys/types.h>


pid_t tcgetpgrp(int fildes);

int tcsetpgrp(int fildes, pid_t pgid);

pid_t tcgetsid(int fildes);


*/
   

int openFile(){

    int temp = open(PATH, O_RDWR);
	return temp;
}


void main( void )
{
 

   //printf("Hello World!");
   int file = openFile();
   printf("%d",file);
   //debugFile = open(DEBUG_PATH, O_RDWR);


}
