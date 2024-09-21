/*
================================================================================
Name: 31b.c
Author: Meenal Jain
Description: Write a program to create a semaphore and initialize value to the semaphore -
a. Counting Semaphore
Date: 21st September 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>

int main(){

	int key;
	key = ftok("21a.c", 65);
	if(key == -1){
		perror("ftok");
		exit(0);
	}
	
	int semid;
	semid = semget(key,1,0666|IPC_CREAT);
	if(semid == -1){
		perror("semget");
		exit(0);
	}

	if(semctl(semid, 0, SETVAL, 10)==-1){
		perror("semctl");
		exit(0);
	}

	printf("Created a coutning semaphore initialised with value 10");

	return 0;

}
/*
Created a coutning semaphore initialised with value 10
*/
