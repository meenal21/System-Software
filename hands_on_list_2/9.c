/*
================================================================================
Name: 9.c
Author: Meenal Jain
Description: Write a program to ignore a SIGINT signal then reset the deafult action of the SIGINT signal - Use signal system call.
Date: 12th September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ign_signal(int sig){
	printf("Ignoring the signal!\n");
}

void reset_signal(int sig){
	signal(SIGINT, SIG_DFL);
	printf("The Signal has now been reset to default, please press Ctrl+C!\n");
}

int main(){
	
	signal(SIGINT, ign_signal);
	pause();

	signal(SIGINT, reset_signal);
	while(1){
		pause();
	}
	return 0;
}
/*
^CIgnoring the signal!
^CThe Signal has now been reset to default, please press Ctrl+C!
^C
*/
