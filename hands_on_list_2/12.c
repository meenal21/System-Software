/*
================================================================================
Name: 12.c
Author: Meenal Jain
Description: Write a program to ignore a create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.
Date: 12th September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){

	pid_t pid = fork();

	if(pid < 0){
		perror("Unable to fork!\n");
	}
	else if(pid == 0){
		sleep(3);
		printf("The parent id of the child process is %d\n", getppid());
		kill(getppid(), SIGKILL);
		sleep(5);
		printf("The Child process is orphan!\n");
	}
	else{	
		printf("The parent process will exit!\n");
		sleep(10);	
	}
	return 0;
}

/*

The parent process will exit!
The parent id of the child process is 3506
Killed
ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_2$ The Child process is orphan!

*/
