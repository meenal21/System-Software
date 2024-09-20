/*
================================================================================
Name: 14.c
Author: Meenal Jain
Description: Write a simple program to create a pipe, write to a pipe, read from a pipe and display on the monitor.
Date: 20th September 2024
================================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 10

int main(int argc, char *argv[]){
	
	int fd[2];
	char buf[BUF_SIZE];
	ssize_t nr;

	int ret = pipe(fd); // madde the fd a pipe
	
	if(ret == -1){
		perror("pipe");
		exit(0);
	}

	if(write(fd[1],argv[1], strlen(argv[1])) != strlen(argv[1])){
		perror("write");
		exit(0);
	}
	close(fd[1]);
	for(;;){
		nr = read(fd[0], buf, BUF_SIZE);
		if(nr == -1){
			perror("read");
			exit(0);
		}
		if(nr == 0)
			break;	
		if(nr>0){
			if(write(STDOUT_FILENO, buf, nr)!=nr){
				perror("write to stdout");
				exit(0);
			}
		}
	}

	if(write(STDOUT_FILENO, "\n", 1)!= 1){
		perror("Write in new character");
		exit(0);
	}
	close(fd[0]);
	return 0;
}
/*
ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_2$ ./a.out "This is a sample line!"
This is a sample line!
*/
