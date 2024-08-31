/*
================================================================================
Name: 17_init_ticket.c
Author: Meenal Jain
Description: Write a program to simulate online ticket reservation. Write a program to open the file, store a ticket number and exit.
Date: 31st August 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

struct Ticket{
	int ticket_number;
};

int main(){
	int fd;
	struct Ticket ticket;
	ticket.ticket_number = 10;

	fd = open("ticket.txt", O_RDWR|O_CREAT|O_TRUNC, 0644);
	if(fd ==-1){
		perror("Open failed");
		exit(EXIT_FAILURE);
	}

	if(write(fd, &ticket, sizeof(struct Ticket)) == -1){
		perror("Write Failed!");
		exit(EXIT_FAILURE);
	}

	printf("Ticket number: %d\n", ticket.ticket_number);
	close(fd);
	return 0;
}

/* Output

Ticket number: 10

*/

