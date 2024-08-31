/*
================================================================================
Name: 12.c
Author: Meenal Jain
Description: Write a program to find out the opening mode of a file. Use fcntl.
Date: 30th August 2024
================================================================================
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int f_d;
	int ret;
	int flags;
	int accessmode;
	const char *path = "/home/ubuntu/ss_assignment/System-Software/hands_on_list_1/demofile1";

	f_d = open(path,O_RDWR);
	flags = fcntl(f_d, F_GETFL);
	accessmode =  flags & O_ACCMODE;

	if (accessmode==O_RDWR){
		printf("The file is in read write mode\n");
	}
	printf("The accessmode is %d",accessmode);
	/* The file is in read write mode
           The accessmode is 2 */
	return 0;
}
