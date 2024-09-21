/*
================================================================================
Name: 31a.c
Author: Meenal Jain
Description: Write a program to create a semaphore and initialize value to the semaphore -
a. Binary Semaphore
Date: 21st September 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>

int main(){

	int key;
	int semid;

	key = ftok("21a.c",65);
	if(key == -1){
		perror("ftok");
		exit(0);
	}

	semid = semget(key, 1, 0666|IPC_CREAT);
	if(semid == -1){
		perror("semget");
		exit(0);
	}

	if(semctl(semid, 0,SETVAL,1)==-1){
		perror("semctl");
		exit(0);
	}
	printf("Binary Semaphore created and initialized to 1 and unlocked!\n");
	return 0;
}
/*
Binary Semaphore created and initialized to 1 and unlocked!
*/
