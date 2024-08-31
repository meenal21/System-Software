/*
================================================================================
Name: 17b.c
Author: Meenal Jain
Description: Write a program to simulate online ticket reservation. Write a seperate program to open a file, Implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
Date: 31st August 2024
================================================================================
*/


#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct Ticket{
	int ticket_number;
};

int main(){

	int fd;
	const char *path = "ticket.txt";
	
	struct Ticket ticket;
	struct flock lock;

	fd = open(path, O_RDWR);
	if(fd == -1){
		perror("Open Failed!");
		exit(EXIT_FAILURE);
	}

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = sizeof(struct Ticket);

	printf("Acquiring write lock!\n");

	if(fcntl(fd, F_SETLKW, &lock)== -1){
		perror("Error acquiring write lock!\n");
		exit(EXIT_FAILURE);
	}

	printf("Write Lock Acquired!\n");

	if(read(fd, &ticket, sizeof(struct Ticket))== -1){
		perror("Reading the file failed!\n");
		exit(EXIT_FAILURE);
	}
	
	ticket.ticket_number += 1;
	printf("The ticket number is %d now!\n", ticket.ticket_number);

	lseek(fd, 0, SEEK_SET);
	if(write(fd, &ticket, sizeof(struct Ticket))==-1){
		perror("Error writing to the file!\n");
		exit(EXIT_FAILURE);
	}


	lock.l_type = F_UNLCK;
	if(fcntl(fd, F_SETLKW, &lock)== -1){
		perror("Unlocking failed!");
		exit(EXIT_FAILURE);
	}

	printf("Write Lock removed!\n");

	close(fd);	
	return 0;
}

/* Output

ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ./17b
Acquiring write lock!
Write Lock Acquired!
The ticket number is 11 now!
Write Lock removed!
ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ./17b
Acquiring write lock!
Write Lock Acquired!
The ticket number is 12 now!
Write Lock removed!

*/
