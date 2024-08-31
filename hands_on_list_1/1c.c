/*
================================================================================
Name: 19.c
Author: Meenal Jain
Description: Create following type of files using system calls
c. FIFO
Date: 31st August 2024
================================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

	const char *fifo = argv[1];

	if(mknod(fifo, S_IFIFO | 0644, 0)==-1){
		perror("fifo failed!");
		exit(EXIT_FAILURE);
	}

	printf("Fifo created successfully at %s\n", fifo);

	return 0;
}

/* Output 

ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ./1c "/home/ubuntu/ss_assignment/System-Software/hands_on_list_1/fifo_new"
Fifo created successfully at /home/ubuntu/ss_assignment/System-Software/hands_on_list_1/fifo_new
ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ll | grep fifo
prw-r--r-- 1 ubuntu ubuntu     0 Aug 31 23:08 fifo_new|

*/
