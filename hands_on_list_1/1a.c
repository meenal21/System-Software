/*
================================================================================
Name: 1a.c
Author: Meenal Jain
Description: Create following type of files using system calls
a. symlink
Date: 31st August 2024
================================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	const char *oldpath = argv[1];
	const char *newpath = argv[2];

	int ret = symlink(oldpath, newpath);
	if(ret == -1)
		perror("symlink failed");
	return 0;
	/* Solution
	ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ./1a "/home/ubuntu/ss_assignment/System-Software/hands_on_list_1/demofile" "/home/ubuntu/ss_assignment/System-Software/hands_on_list_1/demofile_symlink"
ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ls
 1      12     1a     22.c   26      27b.c       demofile_symlink
 10     12.c   1a.c   23     26.c    27c.c       execfile
 10.c   14     21     23.c   27a     9.c         processfile1
 11     14.c   21.c   24     27a.c   demofile
 11.c  '1[A'   22     24.c   27b     demofile1
        */

}
