/*
================================================================================
Name: 30.c
Author: Meenal Jain
Description: Write a program to create shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check if overwriting is happening or not
c. detach the shared memory
d. remove the shared memory
Date: 21st September 2024
================================================================================
*/
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHM_SIZE 1024
int main(){

	int key;
	key = ftok("21a.c",65);
	if(key == -1){
		perror("ftok");
		exit(0);
	}
	int shmid;
	//creating a shared memory
	shmid = shmget(key, SHM_SIZE, 0744 | IPC_CREAT);
	if(shmid == -1){
		perror("shmget");
		exit(0);
	}
	
	char *data;

	data = shmat(shmid,NULL,0);
	if(data == (char *)-1){
		perror("shmat");
		exit(0);
	}

	printf("Attaching memory for writing!\n");

	strcpy((char *)data, "This is the initial message");
	printf("Written the message to the data block! %s \n", (char *)data);

	if(shmdt(data) == -1){
		perror("shmdt");
		exit(0);
	}

	printf("Deattaching the shared memory!");
	
	data = shmat(shmid, NULL, SHM_RDONLY);
	if(data ==(char *)-1){
		perror("shmat (read only)");
		exit(0);
	}

	printf("Shared memory now being attached in read only mode!");

	strcpy((char *)data, "Writing in read mode?");

	printf("Attempting to read mode, and the string is %s\n", (char *)data);
		
	if(shmdt(data) == -1){
		perror("shmdt read-only");
		exit(0);
	}
	
	printf("Shared Memory detached after read only");

	if(shmctl(shmid, IPC_RMID, NULL)==-1){
		perror("shmctl failed!");
		exit(0);
	}
	printf("Shared memory deleted!");

	return 0;

}

/*
Attaching memory for writing!Written the message to the data block! This is the initial message 

*/
