/*
================================================================================
Name: 1b.c
Author: Meenal Jain
Description: Create following type of files using system calls
a. hard link
Date: 31st August 2024
================================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	const char *path = argv[1];
	const char *newpath = argv[2];

	int ret = link(path, newpath);
	if(ret == -1)
		perror("HardLink failed");
	return 0;
	/*
	ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ./1b "/home/ubuntu/ss_assignment/System-Software/hands_on_list_1/demofile" "/home/ubuntu/ss_assignment/System-Software/hands_on_list_1/demofile_hardlink"

	ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ll | grep "demofile"
-rw-rw-r-- 2 ubuntu ubuntu    30 Aug 29 17:15 demofile
-rw-rw-r-- 1 ubuntu ubuntu   117 Aug 30 13:29 demofile1
-rw-rw-r-- 2 ubuntu ubuntu    30 Aug 29 17:15 demofile_hardlink
lrwxrwxrwx 1 ubuntu ubuntu    67 Aug 31 17:07 demofile_symlink -> /home/ubuntu/ss_assignment/System-Software/hands_on_list_1/demofile
        */
}
