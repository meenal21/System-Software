/*
================================================================================
Name: 20.c
Author: Meenal Jain
Description: Write two programs so that both can communicate by FIFO - Use one way communication
- First Program 
Date: 21st September 2024
================================================================================
*/
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	const char *fifo_path = "myfifo";
	int ret = mkfifo(fifo_path, 0644);

	if(ret == -1){	
		perror("mkfifo");
		exit(0);
	}
	printf("The created FIFO is %s\n", fifo_path);
	// created fifo so far, now create the write program
	
	int fd; 
	char msg[] = "This is the message to the FIFO";

	fd = open("myfifo",O_WRONLY);
	
	if(fd == -1){
		perror("open");
		exit(0);
	}
	
	if(write(fd, msg, sizeof(msg))!=sizeof(msg)){
		perror("write");
		exit(0);
	}
	close(fd);
	printf("Message has been sent to the fd\n");
	return 0;
}
/*

The created FIFO is myfifo
Message has been sent to the fd

*/
