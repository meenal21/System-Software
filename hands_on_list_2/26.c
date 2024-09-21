/*
================================================================================
Name: 20.c
Author: Meenal Jain
Description: Write a program to send a message to the message queue.
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>

struct msg_buffer{
	long mtype;
	char mtext[100];
};

int main(){

	int key;
	int msgid;

	key = ftok("21a.c", 65);
	if(key == -1){
		perror("ftok");
		exit(0);
	}

	msgid = msgget(key, 0666|IPC_CREAT);
	if(msgid == -1){
		perror("msgget");
		exit(0);
	}
	
	struct msg_buffer msg;

	msg.mtype = 1;
	strcpy(msg.mtext, "This is a text to be sent as a message");

	if(msgsnd(msgid, &msg, sizeof(msg.mtext),0)==-1){
		perror("msgsnd");
		exit(0);
	}

	return 0;
}
/*

ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_2$ ipcs 

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41021556 0          ubuntu     666        0            0           
0x4102155f 1          ubuntu     666        100          1  

*/
