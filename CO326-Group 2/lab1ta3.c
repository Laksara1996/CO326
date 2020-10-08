#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/io.h>


#define DATA_PORT 0x378
#define STATUS_PORT DATA_PORT+1
#define CONTROL_PORT DATA_PORT+2

unsigned char status,data;
unsigned char com[]={0b00000000,0b00000001,0b00000010,0b00000011,0b00000100,0b00000101,0b00000110,0b00000111,0b00001000,0b00001001};

int main(){
	if(ioperm(DATA_PORT,1,1)){
		fprintf(stderr,"Access Denied to %x/n",DATA_PORT);
		exit(1);
	}

	if (ioperm(STATUS_PORT,1, 1)){
		fprintf(stderr, "Access Denied to %x/n",STATUS_PORT);
		exit(1);
	}

	status = inb(STATUS_PORT);
	data = 255;
	while(1){
		for(int i=0; i<10;i++){
			data = com[i];
			outb(data, DATA_PORT);
			sleep(1);
			

		}
	}
	

}