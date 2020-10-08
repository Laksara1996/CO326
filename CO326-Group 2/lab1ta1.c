#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/io.h>


#define DATA_PORT 0x378
#define STATUS_PORT DATA_PORT+1
#define CONTROL_PORT DATA_PORT+2

unsigned char status,data;

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
		for(int i=0; i<8;i++){
			data = ~(data & (1<<i));
			sleep(1);
			outb(data, DATA_PORT);
		}
	}
	

}