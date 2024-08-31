/*
================================================================================
Name: 21.c
Author: Meenal Jain
Description: Write a program, call fork and print the parent and child process id.
Date: 30th August 2024
================================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main(){
	pid_t pid;

	pid = fork();
	
	printf("My pid is %d\n", pid);	
	if(pid > 0){
		printf("I am the parent with pid %d! \n", pid);
	}
	else if (!pid){
		printf("I am the child\n");
	}
	else if(pid == -1){
		perror("fork");
	}
        /* My pid is 4260
           I am the parent with pid 4260! 
           My pid is 0
           I am the child
        */
	return 0;
}
