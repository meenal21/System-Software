/*
================================================================================
Name: 24.c
Author: Meenal Jain
Description: Write a program to create an orphan process.
Date: 30th August 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	pid_t pid;

	pid = fork();

	if(pid > 0){
		printf("Parent with pid %d is created and now exiting before the child\n", pid);
		exit(0);
	}
	else if(!pid){
		printf("Child Process is sleeping for 10 seconds\n");
		sleep(10);
		printf("Child parent is %d", getppid());

	}
	else{
		perror("fork");
		exit(1);
	}
	/* Output - 
	 
	   Parent with pid 5016 is created and now exiting before the child
           Child Process is sleeping for 10 seconds
           ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ Child parent is 1839
          --- no prompt on shell!
	   ps 1839 -
	   PID TTY      STAT   TIME COMMAND
           1839 ?        Ss     0:03 /usr/lib/systemd/systemd --user
           */

	   
	return 0;
}
