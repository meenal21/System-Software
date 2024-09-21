/*
================================================================================
Name: 28.c
Author: Meenal Jain
Description: Write a program to change the existing access mode of the message queue.
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>

struct msqid_ds q_info;

int main(){

	int key;
	key = ftok("21a.c",65);

	if(key == -1){
		perror("ftok");
		exit(0);
	}
	int msgid;
	msgid = msgget(key, 0666);
	if(msgid == -1){
		perror("msgget");
		exit(0);
	}

	if(msgctl(msgid, IPC_STAT,&q_info )==-1){
		perror("msgctl");
		exit(0);
	}
	printf("Existing Permission are %d \n", q_info.msg_perm.mode);
	
	q_info.msg_perm.mode = 0644;

	if(msgctl(msgid, IPC_SET, &q_info)==-1){
		perror("msgctl");
		exit(0);
	}

	if(msgctl(msgid, IPC_STAT, &q_info)==-1){
		perror("msgid");
		exit(0);
	}
	printf("New Permissions are %d \n", q_info.msg_perm.mode);

	return 0;
}
/*
Existing Permission are 438 
New Permissions are 420 
*/
