/*
================================================================================
Name: 26.c
Author: Meenal Jain
Description: Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program.
Date: 30th August 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	const char *path = argv[1];
	const char *cmd = argv[2];
	const char *arg = argv[3];

	int result = execl(path, cmd, arg, NULL);

	if(result == -1){
		perror("execl failed");
	}
        /* Output
        ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ./26 "/bin/touch" touch execfile
        ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ls | grep 'exec'
        execfile
        */
	return 0;
}
