/*
================================================================================
Name: 29.c
Author: Meenal Jain
Description: Write a program to get scheduling policy and modify scheduling policy
Date: 31st August 2024
================================================================================
*/


#include <stdlib.h>
#include <sched.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	

	int policy;
	policy = sched_getscheduler(0);
		
	switch(policy){

	case SCHED_OTHER:
		printf("Policy is Other/Normal");
		break;
	case SCHED_RR:
		printf("Policy is Round Robin");
		break;
	case SCHED_FIFO:
		printf("Policy is FIFO");
		break;
	case -1:
		perror("sched_getscheduler failed");
		break;
	default:
		printf("Unknown policy!");
	}

	return 0;
}

/* Output
Policy is Other/Normal
   */
