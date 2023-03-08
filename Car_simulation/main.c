




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



#define PATH "/dev/ttyS2"

unsigned int com3File;

struct bridgeStatus{
   unsigned int southQ;
   unsigned int northQ;
   unsigned int northboundTrafficlight;
   unsigned int southboundTrafficlight;
};


int main( void )
{
	unsigned int test;
	struct termios com3Config;
	unsigned int input;
	com3File = open(PATH, O_RDWR);

	if(com3File < 0){
		printf("com3File broke\n");

	}

	
	if(tcgetattr(com3File, &com3Config) < 0)
	{
		printf("com3 tcgetattr broken\n");
	}

	//com3Config.c_cflag = CS8 
	//com3Config.c_cflag = CS8 | CSTOPB | CLOCAL | CREAD;
	//com3Config.c_oflag = 0;	
	//com3Config.c_iflag = 0;
	//com3Config.c_lflag = 0;
	//com3Config.c_cc[VTIME] = 5;
	//com3Config.c_cc[VMIN]  = 1;


	test = read(com3File, &input, 1);
	if(test < 0)
	{
		printf("com3 read broke\n");
	}

	
	//write(com3File,&test,1);

	printf("%d\n",3);
	printf("%d\n",input);
	printf("%d\n",test);

	
	
	return
	




}



