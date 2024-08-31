/*
================================================================================
Name: 8.c
Author: Meenal Jain
Description: Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
Date: 31st August 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFERSIZE 1024
int main(int argc, char *argv[]){

	int f_d;
	char buffer[BUFFERSIZE];
	ssize_t read_b;
	int start_l = 0;

	f_d = open(argv[1], O_RDONLY);
	if(f_d == -1){
		perror("Opening the file failed");
		exit(EXIT_FAILURE);
	}

	while((read_b = read(f_d, buffer, BUFFERSIZE)) > 0){
		for(int i = 0; i < read_b; i++){
			if(buffer[i] == '\n'){
				write(STDOUT_FILENO, &buffer[start_l], i - start_l + 1);
				start_l = i + 1;
			}
		}
	

		if(start_l < read_b)
			write(STDOUT_FILENO, &buffer[start_l], read_b - start_l);

		start_l = 0;

	}
	if(read_b == -1){
		perror("Error reading from the file");
		close(f_d);
		exit(EXIT_FAILURE);
	}

	close(f_d);
	return 0;
}

/* Solution

ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ./8 "/home/ubuntu/ss_assignment/System-Software/hands_on_list_1/example.txt"
This is a file
I am using this for reading line by line
This is the third line
This is the fourth line

*/
