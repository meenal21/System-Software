/*
================================================================================
Name: 25.c
Author: Meenal Jain
Description: Write a program to create three child processes. The parent should wait for a particular child.
Date: 31st August 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

	pid_t pid1, pid2, pid3, wpid;
	int status;

	pid1 = fork();
	if(pid1 == -1){
		perror("fork failed!");
		exit(EXIT_FAILURE);
	}

	if(pid1 == 0){
		printf("Child 1 %d is running..\n", getpid());
		sleep(2);
		exit(10);
	}

	pid2 = fork();
	
	if(pid2 == -1){
		perror("fork failed!");
		exit(EXIT_FAILURE);
	}

	if(pid2 == 0){
		printf("Child 2 %d is running..\n", getpid());
		sleep(4);
		exit(20);
	}

	pid3 = fork();
        
        if(pid3 == -1){
                perror("fork failed!");
                exit(EXIT_FAILURE);
        }
        
        if(pid3 == 0){
                printf("Child 3 %d is running..\n", getpid());
                sleep(6);
                exit(30);
        }

	printf("Parent %d is waiting for child 2 %d .. \n", getpid(), pid2);


	wpid = waitpid(pid2, &status, 0);

	if(wpid == -1){
		perror("waitpid");
		exit(EXIT_FAILURE);
	}

	if(WIFEXITED(status)){
		printf("Child 2 %d exited with status %d \n", wpid, WEXITSTATUS(status));
	}else{
		printf("Child 2 %d did not terminate properly!!\n", wpid);
	}


	while ((wpid = wait(&status)) > 0) {
		if(WIFEXITED(status)){
			printf("Other child %d exited with status %d \n", wpid, WEXITSTATUS(status));
		}
		else{
                	printf("Other Child %d did not terminate properly!!\n", wpid);
       		 }
	}

	return 0;
}

/* Output 

ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ./25
Child 1 7351 is running..
Child 2 7352 is running..
Parent 7350 is waiting for child 2 7352 .. 
Child 3 7353 is running..
Child 2 7352 exited with status 20 
Other child 7351 exited with status 10 
Other child 7353 exited with status 30 

*/
	
