/*
================================================================================
Name: 22.c
Author: Meenal Jain
Description: Write a program, open a file, call fork and the write to the file by both the child as well as the parent processes. Check the output of the file.
Date: 30th August 2024
================================================================================
*/


#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

	const char *path = argv[1];
	int f_d;
	int ret;
	pid_t pid;
	const char *par = "Written by parent";
       	const char *chi = "Written by child";	

	f_d = open(path, O_RDWR | O_APPEND);
	pid = fork();
	
	if (pid > 0){
		ret = write(f_d, par, strlen(par));
		printf("Printing parent string %s\n", par);
	}
	else if (!pid){
		ret = write(f_d, chi, strlen(chi));
		printf("Printing child string %s\n", chi);
	}
	else{
		perror("fork");
	}
        /* Solution - 
        
          Printing parent string Written by parent
          Printing child string Written by child
        
          In the file -
          Written by parentWritten by child
        */
	return 0;
}
