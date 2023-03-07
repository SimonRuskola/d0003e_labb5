




#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <unistd.h>
#include <pthread.h>
#include <io.h>

#include <termios.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define north 1
#define south 0
#define green 1
#define red   0

#define PATH "/dev/ttyS0"

unsigned int com3;

struct bridgeStatus{
   unsigned int southQ;
   unsigned int northQ;
   unsigned int northboundTrafficlight;
   unsigned int southboundTrafficlight;
};




void main( void )
{
	struct termios com3Config;
	com3 = open(PATH, O_RDWR);

	if(tcgetattr(com3, &com3Config) < 0)
	{
		printf("Com3 broken\n");
	}

	com3Config.c_cflag = CS8 | CSTOPB | CLOCAL | CREAD;
	com3Config.c_oflag = 0;	
	com3Config.c_iflag = 0;
	com3Config.c_lflag = 0;
	//com3Config.c_cc[VMIN]  = 1;
	//com3Config.c_cc[VTIME] = 5;


	write(com3,'A',1);


	while (1)
	{
		/* code */
	}
	




}



