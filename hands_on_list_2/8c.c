/*
================================================================================
Name: 8c.c
Author: Meenal Jain
Description: Write a seperate program using signal system call to catch the following signals.
c. SIGFPE
Date: 12th September 2024
================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void fpeHandler(int sig);

int main(){
	
	signal(SIGFPE, fpeHandler);
	int x;
	x = 5/0;
	printf("Caught the SIGFPE signal!\n");	
	return 0;
}

void fpeHandler(int sig){
	printf("Arithmetic issue has been caught!\n");
	exit(0);
}
/*
Arithmetic issue has been caught!
*/
