/*
================================================================================
Name: 11.c
Author: Meenal Jain
Description: Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
================================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{	
	int f_d;
	const char *path = "/home/ubuntu/ss_assignment/System-Software/hands_on_list_1/demofile1";
	f_d = open(path, O_RDWR);
	int f_d_dup;
	int ret_dup;
	int ret_dup2;
	int f_d_dup2;
	int ret_fcntl;
	int f_d_fcntl;
	int ret;
	const char *str1 = "appending without dup()";
	const char *str2 = "appending with dup()";
	const char *str3 = "appending with dup2()";
	const char *str4 = "appending with fcntl";

	if(f_d != -1){
		f_d_dup = dup(f_d);
		ret = write(f_d, str1,strlen(str1));
		ret_dup = write(f_d_dup, str2, strlen(str2));		
		f_d_dup2 = dup2(f_d, 3);
		ret_dup2 = write(f_d_dup2, str3, strlen(str3));
		f_d_fcntl = fcntl(f_d, F_DUPFD, f_d_dup2);
		ret_fcntl = write(f_d_fcntl, str4, strlen(str4));
		/* appending without dup()appending with dup()appending with dup2()appending with fcntl */
	}
	close(f_d_fcntl);
	close(f_d_dup2);
	close(f_d_dup);
	close(f_d);
	return 0;
}
