#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/io.h>

#define DATA_PORT 0x378
#define STATUS_PORT ​ DATA_PORT​ +1
#define CONTROL_PORT ​ DATA_PORT​ +2
/* parallel port base address */

unsigned char status, data;

void main(){
	if (ioperm(DATA_PORT, 1, 1)){
   		fprintf(stderr, "Access denied to %x\n", DATA_PORT),
		exit(1);
	}
	if (ioperm(​ STATUS_PORT​ , 1, 1)){
		fprintf(stderr, "Access denied to %x\n", ​ STATUS_PORT​ ),
		exit(1);
	}
	status = inb(​ STATUS_PORT​ );
	data = status;
	outb(data,​ ​ DATA_PORT);
}