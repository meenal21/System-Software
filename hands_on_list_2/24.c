/*
================================================================================
Name: 24.c
Author: Meenal Jain
Description: Write a simple program to create a message queue and print the key and message queue id.
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){

	int key; 
	key = ftok("20a.c", 65);

	if(key == -1){
		perror("ftok");
		exit(0);
	}

	int msgid;
       	msgid = msgget(key, 0666|IPC_CREAT);

	if(msgid == -1){
		perror("msgget");
		exit(0);	
	}	

	printf("The key is %d \n", key);
	printf("The msgid is %d \n", msgid);

	return 0;
}
/*

The key is 1090655574 
The msgid is 0 

*/
