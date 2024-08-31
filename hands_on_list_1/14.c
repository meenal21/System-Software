/*
================================================================================
Name: 14.c
Author: Meenal Jain
Description: Write a program to open a find the type of a file.
a. Input should be taken from the command line.
b. program should be able to identify any type of a file.
Date: 30th August 2024
================================================================================
*/


#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){

	const char *path = argv[1];
	struct stat file_buf;
	int ret;

	ret = stat(path, &file_buf);
	//checking file types here using type macros
	if(ret != -1){
		if(S_ISREG(file_buf.st_mode)){
			printf("The file %s is a regular file", path);
		}
		else if(S_ISDIR(file_buf.st_mode)){
			printf("The file %s is a directory", path);
		}
		else if(S_ISCHR(file_buf.st_mode)){
			printf("The file %s is a character device!", path);
		}
		else{
			printf("The file %s is not a recognized file type!", path);
		}
        /* The file is a regular file/home/ubuntu/ss_assignment/System-Software/hands_on_list_1/demofile */
	}
	else{
		perror("stat");
	}
	
	return 0;
}
