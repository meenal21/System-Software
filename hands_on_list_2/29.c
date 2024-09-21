/*
================================================================================
Name: 28.c
Author: Meenal Jain
Description: Write a program to delete the message queue.
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>

int main(){

	int key;
	key = ftok("21a.c", 65);
	if(key == -1){
		perror("ftok");
		exit(0);
	}
	int msgid;
	msgid = msgget(key, 0644);
	if(msgid == -1){
		perror("msgget");
		exit(0);
	}
	
	printf("Deleting the queue\n");
	if(msgctl(msgid, IPC_RMID, NULL)==-1){
		perror("mgctl");
		exit(0);
	
	}
	return 0;
}
/*

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41021556 0          ubuntu     666        0            0           
0x4102155f 1          ubuntu     644        0            0           

ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_2$ ./a.out
Deleting the queue
ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41021556 0          ubuntu     666        0            0           

*/
