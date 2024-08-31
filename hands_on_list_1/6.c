/*
================================================================================
Name: 6.c
Author: Meenal Jain
Description: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 31st August 2024
================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(){
	
	char buffer[BUFFER_SIZE];
	ssize_t read_bytes;
	while((read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0){
		
		if(write(STDOUT_FILENO, buffer, read_bytes) != read_bytes)
			perror("write failed");
	}
	if(read_bytes == -1)
		perror("Read Error");
	return 0;
	/* Solution
	ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/          hands_on_list_1$ ./6
        Hey! do you work?
        Hey! do you work?
        Oh yes you do!
        Oh yes you do!
        */
}
