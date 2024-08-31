/*
================================================================================
Name: 3.c
Author: Meenal Jain
Description: Write a program to create a file and return the file descriptor. Use creat() command.
Date: 31st August 2024
================================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{	
	const char *path  = argv[1];

	int f_d = creat(path, 0644);
	printf("%d\n", f_d);
	if(f_d == -1)
		perror("creat failed");
	return 0;
	/* Solution
	ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ./3 "/home/ubuntu/ss_assignment/System-Software/hands_on_list_1/demo_creat"
3
ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ll | grep "demo_"
-rw-r--r-- 1 ubuntu ubuntu     0 Aug 31 17:38 demo_creat
        */
}
