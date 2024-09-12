/*
================================================================================
Name: 8b.c
Author: Meenal Jain
Description: Write a seperate program using signal system call to catch the following signals.
b. SIGINT
Date: 12th September 2024
================================================================================
*/
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void intHandler(int sig);

int main(){

	signal(SIGINT, intHandler);
	sleep(3);
	printf("Catching the Interrupt!\n");

	return 0;
}

void intHandler(int sig){

	printf("Ctrl+C entered!\n");
}
	
/*
^CCtrl+C entered!
Catching the Interrupt!
*/
