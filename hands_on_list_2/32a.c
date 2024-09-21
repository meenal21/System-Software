#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

struct Ticket{
  int ticket_number;
};
int main(){


	int key;
	key = ftok("21a.c",65);
	if(key == -1){
		perror("ftok");
		exit(0);
	}

	int semid;
	semid = semget(key, 1, 0666|IPC_CREAT);
	if(semid == -1){
		perror("semget");
		exit(0);
	}

	if(semctl(semid, 0, SETVAL, 1) == -1){
		perror("semctl");
		exit(0);
	}

	printf("Create a ticket:\n");

	struct sembuf sem;
	int fd;
	const char *path = "ticket.txt";
	struct Ticket ticket;
	fd = open(path, O_RDWR);
	if(fd == -1){
		perror("Open Failed!");
		exit(EXIT_FAILURE);
	}
  

		sem.sem_num = 0;
		sem.sem_op = -1; //to decrement the semaphore val!
		sem.sem_flg = 0;

		if(semop(semid, &sem,1)==-1){
		  perror("Lock Failed");
		  exit(0);
		}
		//Critical Section
		//
		
		if(read(fd, &ticket, sizeof(struct Ticket))== -1){
		    perror("Reading the file failed!\n");
		    exit(EXIT_FAILURE);
	        }
	        printf("Current Ticket number %d\n", ticket.ticket_number);
	        ticket.ticket_number += 1;
	        printf("The ticket number is %d now!\n", ticket.ticket_number);

	        lseek(fd, 0, SEEK_SET);
	        if(write(fd, &ticket, sizeof(struct Ticket))==-1){
	        	perror("Error writing to the file!\n");
	        	exit(EXIT_FAILURE);
	        }

		sleep(10);
		
		sem.sem_op = 1;
		semop(semid, &sem, 1);
    
	close(fd);
	return 0;
}

