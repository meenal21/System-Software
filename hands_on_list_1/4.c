/*
================================================================================
Name: 4.c
Author: Meenal Jain
Description: Write a program to write an existing file in read write mode. Try O_EXCL flag also.
Date: 31st August 2024
================================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{	
	const char *path = argv[1];
	int f_d = open(path, O_CREAT | O_EXCL | O_RDWR);

	if(f_d == -1)
		perror("open failed");
	else
		close(f_d);
	return 0;
	
	/* Solution
	ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/ hands_on_list_1$ ./4 "/home/ubuntu/ss_assignment/System-Software/ hands_on_list_1/demoopen_"
        ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ll | grep demoopen_
        -r-s--S--T 1 ubuntu ubuntu     0 Aug 31 18:03 demoopen_*

        */
}
