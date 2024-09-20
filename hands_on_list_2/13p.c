/*
================================================================================
Name: 13p.c
Author: Meenal Jain
Description: Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal(using kill system call). Find out whether the first program is able to catch the signal or not.
- This is the killing program.
Date: 20th September 2024
================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	pid_t pid = atoi(argv[1]);
	printf("Stopping the process %d",pid);
	kill(pid, SIGSTOP);
	sleep(2);
	return 0;
}
/*
Stopping the process 4795
*/
