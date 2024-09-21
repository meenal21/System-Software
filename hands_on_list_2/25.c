/*
================================================================================
Name: 25.c
Author: Meenal Jain
Description: Write a program to print message queue's properties
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <time.h>


int main(){

	int key;
	int msgid;
	struct msqid_ds buf;

	key = ftok("20a.c", 65);

	if(key == -1){
		perror("ftok");
		exit(0);
	}
	msgid = msgget(key, 0666|IPC_CREAT);

	if(msgid == -1){
		perror("msgget");
		exit(0);
	}

	if(msgctl(msgid, IPC_STAT, &buf)==-1){
		perror("msgctl");
		exit(0);
	}
	
	printf("a. access permission %d\n",buf.msg_perm.mode);
	printf("b. uid %d gid %d\n", buf.msg_perm.uid, buf.msg_perm.gid);
	printf("c. last sent %ld and last received %ld \n", buf.msg_stime, buf.msg_rtime);
	printf("d. time of last change %ld \n", buf.msg_ctime);
	printf("e. size of the queue %ld \n", buf.__msg_cbytes);
	printf("f. number of messages in the queue %ld\n", buf.msg_qnum);
	printf("g. maximum number of bytes allowed %ld\n", buf.msg_qbytes);
	printf("h. pid of the msgsnd %d and msgrcv %d\n", buf.msg_lspid, buf.msg_lrpid);
	return 0;
}
/*

a. access permission 438
b. uid 1000 gid 1000
c. last sent 0 and last received 0 
d. time of last change 1726911814 
e. size of the queue 0 
f. number of messages in the queue 0
g. maximum number of bytes allowed 16384
h. pid of the msgsnd 0 and msgrcv 0

*/
