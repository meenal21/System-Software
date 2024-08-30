/*
================================================================================
Name: 23.c
Author: Meenal Jain
Description: Write a program to create a Zombie state of the running program.
Date: 30th August 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	
	pid_t pid;

	pid = fork();

	if(pid > 0){
		printf("Parent with PID %d waiting for 10 seconds\n", pid);
	
		sleep(10);
		printf("Parent is exiting now!\n");
	}
	else if(!pid){
		printf("Child process is created and now exiting!\n");
		exit(0);
	}
	else{
		perror("fork");
		exit(1);
	}
        /* Output:
           Parent with PID 4879 waiting for 10 seconds
           Child process is created and now exiting!
           Parent is exiting now!
        */
	return 0;
}
