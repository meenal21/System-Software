/*
================================================================================
Name: 27a.c
Author: Meenal Jain
Description: Write a program to execute ls -Rl by the following system calls
a. execl
Date: 30th August 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int ret, retlp, retle, retv, retvp;
	
	ret = execl(argv[1], argv[2], argv[3], NULL); 
	if(ret == -1)
		perror("execl failed");
	return 0;
	/* Output
        ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ./27a "/bin/ls" ls -Rl
        .:
        total 268
        -rwxrwxr-x 1 ubuntu ubuntu 16088 Aug 30 12:44  1
        -rwxrwxr-x 1 ubuntu ubuntu 16120 Aug 29 17:15  10
        -rw-rw-r-- 1 ubuntu ubuntu  1194 Aug 30 12:51  10.c
        -rwxrwxr-x 1 ubuntu ubuntu 16200 Aug 30 11:52  11
        -rw-rw-r-- 1 ubuntu ubuntu  1460 Aug 30 12:52  11.c
        */
}
