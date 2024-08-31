/*
================================================================================
Name: 28.c
Author: Meenal Jain
Description: Write a program to get maximum and minimum real time priority
Date: 31st August 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(){

	int max_pt = sched_get_priority_max(SCHED_FIFO);
	if(max_pt == -1){
		perror("getting max priority failed");
		exit(EXIT_FAILURE);
	}


	int min_pt = sched_get_priority_min(SCHED_FIFO);
	if(min_pt == -1){
		perror("getting min priority failed");
		exit(EXIT_FAILURE);
	}

	printf("The maximum real time priority is %d\n", max_pt);
	printf("The minimum real time priority is %d\n", min_pt);
	
	return 0;
}

/* Solution
The maximum real time priority is 99
The minimum real time priority is 1
*/
