/*
================================================================================
Name: 15.c
Author: Meenal Jain
Description: Write a program to send and receive data from parent to child process.
Date: 12th September 2024
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

	int ret = pipe(fd); // made the fd a pipe
	
	if(ret == -1){
		perror("Pipe");
		exit(0);
	}
	pid_t pid = fork(); // create a child
	if(pid == 0){ // child process
		if(close(fd[1])== -1){
			perror("Close");
			exit(0);
		}
		printf("In child process! \n");
		for(;;){
			nr = read(fd[0], buf, BUF_SIZE);
			if(nr == -1){
				perror("Read");
				exit(0);
			}
			else if(nr == 0){
				printf("Reached end of file for read");
				break;
			}
			else{
				if(write(STDOUT_FILENO,buf, nr) != nr){
					perror("Writing error");
					exit(0);
				}
			}
		}
	
		write(STDOUT_FILENO, "\n",1);
		if(close(fd[0])==-1){
			perror("close");
			exit(0);
		}
	}
	else if(pid > 0){
		if(close(fd[0])== -1){
			perror("close-parent");
			exit(0);
		}

		if(write(fd[1], argv[1], strlen(argv[1]))!=strlen(argv[1])){
			perror("parent - write");
			exit(0);
		}
		if(close(fd[1]) == -1){
			perror("close - write - parent");
			exit(0);
		}

		// wait for the child to finish, so that it can read and then parent will exit!
		wait(NULL);
		exit(0);
	}
	else{
		perror("fork");
		close(fd[0]);
		close(fd[1]);
		exit(0);
	}



	return 0;
}
/*
./a.out "This is a file"
In child process! 
This is a file
Reached end of file for read
*/
