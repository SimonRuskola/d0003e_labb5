


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



unsigned int com3File;
char keyboardInput;
unsigned int com3Input;
struct termios com3Config;

unsigned int output; 

pthread_mutex_t bridgeMutex;

pthread_t carsOnBridge_th[6];


unsigned int southQ;
unsigned int northQ;
unsigned int northboundRedLight;
unsigned int northboundGreenLight;
unsigned int southboundRedLight;
unsigned int southboundGreenLight;
unsigned int carsOnBridge;
unsigned int direction;




void update(void){
	printf("--------------------------------------------\n");
	printf("Cars in north queue: %d\n", northQ);
	printf("Cars in south queue: %d\n", southQ);
	printf("Cars on the bridge:  %d\n", carsOnBridge);
	printf("South red: %d\nSouth green: %d\nNorth red: %d\nNorth green: %d\n", southboundRedLight, southboundGreenLight, northboundRedLight, northboundGreenLight);
	printf("--------------------------------------------\n");

	// write to serial port
}


void *readKeyboard(void *vargp){
	while(1){
		
		keyboardInput = getchar();
		
		if(keyboardInput == 's'){
			southQ++;
			output = 0x04;
			write(com3File, &output , 1);
			update();
		
		}
		else if(keyboardInput == 'n'){
			northQ++;
			output = 0x01;
			write(com3File, &output , 1);
			update();
			
		}
		else if(keyboardInput == 'e'){
			exit(1);
		}
		//printf("write: %d\n",output);
		
	}
}
void *pushCarOffBridge(void *vargp){
	sleep(5);
	carsOnBridge--;
	update();

}

void pushCarToBridge(void){
	if(direction == north){
		northQ--;
		pthread_create(&(carsOnBridge_th[carsOnBridge]), NULL, pushCarOffBridge, NULL);
		carsOnBridge++;
		output = 0x02;
		write(com3File, &output , 1);
	} else if(direction == south){
		southQ--;
		pthread_create(&(carsOnBridge_th[carsOnBridge]), NULL, pushCarOffBridge, NULL);
		carsOnBridge++;
		output = 0x08;
		write(com3File, &output , 1);
	}
	//printf("write: %d\n",output);
}

void *readCom3(void *vargp){
	while (1)
	{
		while(read(com3File, &com3Input, 1) == -1);

		//if(com3Input & (1<<1)){ // true if north red is on
		//   printf("read: north red on\n");}


		if(com3Input & (1<<1)){  // true if north red is on
			northboundRedLight = 1;
		}else {
			northboundRedLight = 0;
		}

		if(com3Input & (1<<3)){ // true if south red is on
		   southboundRedLight = 1;
		   
		}else{
			southboundRedLight = 0;
		}


		if(com3Input & (1)){ // true if north green is on
		    northboundGreenLight = 1;
		    direction = north;
			pushCarToBridge();

		}else{
			northboundGreenLight = 0;
		}
		
		if(com3Input & (1<<2)){ // true if south green is on
		    southboundGreenLight = 1;
		    direction = south;
			pushCarToBridge();

		}else{
			southboundGreenLight = 0;
		}

		update();

	}
	
}



int main( void )
{
	unsigned int test;
	com3File = open("/dev/ttyS2", O_RDWR);

	if(com3File == (-1)){
		printf("com3File broke\n");

	}
	//printf("com3File: %d\n",com3File);

	if(tcgetattr(com3File, &com3Config) < 0)
	{
		printf("com3 tcgetattr broken\n");
	}

	if(cfsetispeed(&com3Config, B9600) < 0 || cfsetospeed(&com3Config, B9600) < 0) {

		printf("Com3 speed broke.\n");
	}
	

	com3Config.c_cflag = CS8;  // 8 bits

	com3Config.c_cflag &= ~CSTOPB;  // only 1 stop bit

	com3Config.c_cflag &= ~PARENB; // no parity bit

	


	//com3Config.c_cflag = CS8 | CSTOPB | CLOCAL | CREAD;
	//com3Config.c_oflag = 0;	
	//com3Config.c_iflag = 0;
	//com3Config.c_lflag = 0;
	//com3Config.c_cc[VTIME] = 5;
	//com3Config.c_cc[VMIN]  = 1;
	//printf("%d\n",3);
	//printf("%d\n",test);


	if(tcgetattr(com3File, &com3Config) < 0)
	{
		printf("com3 tcgetattr broken2\n");
	}

	



	update();


	pthread_t readKeyboard_th;
	pthread_create(&readKeyboard_th, NULL, readKeyboard, NULL);

	pthread_t readCom3_th;
	pthread_create(&readCom3_th, NULL, readCom3, NULL);

	
	//write(com3File,&test2,1);

	/*
	test = read(com3File, &com3Input, 1);


	if(test == (-1))
	{
		printf("com3 read broke %d\n", test);
		
	}else{
		printf("com3 worked %d\n", test);
	}

	printf("error message: %d\n",test);
	printf("input: %d\n",com3Input);
	*/


	while (1)
	{
	
	}
	


	

}






