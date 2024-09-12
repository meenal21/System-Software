/*
================================================================================
Name: 8d.c
Author: Meenal Jain
Description: Write a seperate program using signal system call to catch the following signals.
d. SIGALRM
Date: 12th September 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void alarmHandler(int sig);

int main(){

	signal(SIGALRM, alarmHandler);
	alarm(5);

	pause();
	return 0;
}

void alarmHandler(int sig){
	printf("5 seconds are up!\n");
	exit(0);
}

/* 
5 seconds are up!
*/
