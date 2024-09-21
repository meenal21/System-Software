/*
================================================================================
Name: 27.c
Author: Meenal Jain
Description: Write a program to receive a message from message queue using 
a. 0 as flag
b. IPC_NOWAIT as flag
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>

struct msg_buffer {
	int mtype;
	char mtext[100];
};

void receive_msg(int msgid, int flag){
	struct msg_buffer msg;

	if(msgrcv(msgid, &msg, sizeof(msg.mtext),1,flag)== -1){
		if(flag == IPC_NOWAIT)
			perror("IPC_NOWAIT receive");
		else
			perror("0 receive");
		exit(0);
	}

	printf("Received message: %s\n", msg.mtext);
}

int main(){

	int key;
	int msgid;

	key = ftok("21a.c", 65);
	if(key == -1){
		perror("ftok");
		exit(0);
	}

	msgid = msgget(key, 0666);

	if(msgid == -1){
		perror("msgget");
		exit(0);
	}
	
	printf("Receiving message with flag 0 - blocking call \n");
	receive_msg(msgid, 0);
	printf("REceiving message with flag IPC_NOWAIT - non blocking call\n");
	receive_msg(msgid, IPC_NOWAIT);

	return 0;
}
/*
Receiving message with flag 0 - blocking call 
Received message: 
*** stack smashing detected ***: terminated
Aborted (core dumped)
ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_2$ ./a.out
Receiving message with flag 0 - blocking call
*/
