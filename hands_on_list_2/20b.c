/*
================================================================================
Name: 20.c
Author: Meenal Jain
Description: Write two programs so that both can communicate by FIFO - Use one way communication
- Second Program
Date: 21st September 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUF_SIZE 10

int main(){

	int fd;
	char msg[BUF_SIZE];
	ssize_t nr;
	fd = open("myfifo",O_RDONLY);
	
	if(fd == -1){
		perror("open");
		exit(0);
	}
	
	printf("Reading from the fifo\n");

	for(;;){
		nr = read(fd, msg, BUF_SIZE);
		if(nr == -1){
			perror("read");
			exit(0);
		}
		if(nr == 0)
			break;
		if(nr > 0){
			if(write(STDOUT_FILENO, msg, nr)!=nr){
				perror("wrtie");
				exit(0);
			}
		}
	}
	if(write(STDOUT_FILENO, "\n",1)!=1){
		perror("write");
		exit(0);
	}
	return 0;
}
/*
Reading from the fifo
This is the message to the FIFO
*/
