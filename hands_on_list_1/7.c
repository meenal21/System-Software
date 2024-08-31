/*
================================================================================
Name: 7.c
Author: Meenal Jain
Description: Write a program to copy file1 into file2.
Date: 31st August 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
	
	ssize_t read_b, write_b;
	int s_fd, d_fd;
	char buffer[BUFFER_SIZE];

	// supposing the number of arguments is correct!
	
	s_fd = open(argv[1], O_RDONLY);
	if(s_fd == -1){
		perror("Open failed for source file");
		exit(EXIT_FAILURE);
	}
	
	d_fd = open(argv[2], O_CREAT|O_TRUNC|O_WRONLY);
	if(d_fd == -1){
		perror("Open/Create failed for Destination file");
		exit(EXIT_FAILURE);
	}

	while((read_b = read(s_fd, buffer, BUFFER_SIZE))>0){
		write_b = write(d_fd, buffer, read_b);
		if(write_b != read_b){
			perror("Unable to write to Destination file");
			close(s_fd);
			close(d_fd);
			exit(EXIT_FAILURE);
		}
	}

	if(read_b == -1){
		perror("Unable to read from Source File");
	}

	close(s_fd);
	close(d_fd);
	return 0;
}


/* Solution

ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ./7 "/home/ubuntu/ss_assignment/System-Software/hands_on_list_1/demofile1" "/home/ubuntu/ss_assignment/System-Software/hands_on_list_1/demofile1_copy"
ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ cat demofile1
appending without dup()appending with dup()appending with dup2()appending with f

ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ cat demofile1_copy
appending without dup()appending with dup()appending with dup2()appending with fcntlWritten by parentWritten by child

*/
