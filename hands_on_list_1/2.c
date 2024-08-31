/*
================================================================================
Name: 2.c
Author: Meenal Jain
Description: Write a simple program to execute an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding directory.
Date: 31st August 2024
================================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(){
	
	printf("PID of the process is %d\n", getpid());
	for(;;);
	return 0;
	/* Solution
	ubuntu@ubunyu-Vm:~/ss_assignment/System-Software/hands_on_list_1$ ./2
        PID of the process is 4324      
        Killed
  
	ubuntu@ubunyu-Vm:/proc/4324$ cat status
Name:	2
Umask:	0002
State:	R (running)
Tgid:	4324
Ngid:	0
Pid:	4324
PPid:	3334
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 100 114 1000 
NStgid:	4324
NSpid:	4324
NSpgid:	4324
NSsid:	3334
        */

}
