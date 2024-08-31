/*
================================================================================
Name: 13.c
Author: Meenal Jain
Description: Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not!
Date: 31st August 2024
================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

int main(){
	
	fd_set readfds;
	struct timeval timeout;

	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);


	timeout.tv_sec = 10;
	timeout.tv_usec = 0;

	printf("Waiting for input for 10 secs!\n");

	int retval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

	if(retval == -1){
		perror("select error!\n");
	}
	else if (retval){
		printf("we got the data in 10 secs! Thank You!\n");
	}
	else{
		printf("Alas! We did not recieve any data from user within 10 secs!\n");
	}
	return 0;
}

/* Output

Scenario 1:

Waiting for input for 10 secs!
dsfsd
we got the data in 10 secs! Thank You!

Scenario 2:

Waiting for input for 10 secs!
Alas! We did not recieve any data from user within 10 secs!

*/
