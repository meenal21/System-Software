/*
================================================================================
Name: 13.c
Author: Meenal Jain
Description: Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal(using kill system call). Find out whether the first program is able to catch the signal or not.
Date: 20th September 2024
================================================================================
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void sigstop_handler(int sig){
	printf("The Signal Stop has been caught");
}

int main(){

	printf("The process id is %d\n", getpid());

	signal(SIGSTOP,sigstop_handler);
	pause();
	return 0;
}
/*
The process id is 4795

[1]+  Stopped                 ./13
*/
