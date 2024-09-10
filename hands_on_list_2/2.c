/*
================================================================================
Name: 3.c
Author: Meenal Jain
Description: Write a program to print system resource limits.
Date: 10th September 2024
================================================================================
*/

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main(){

	int ret;
	struct rlimit rlim;

	ret = getrlimit(RLIMIT_CORE, &rlim);

	if(ret == -1)
		perror("Unable to get resource limits for core!");
	else{
		printf("The system resource limits for core are soft limit - %ld, hard limit - %ld \n", rlim.rlim_cur, rlim.rlim_max);
	}
	return 0;

}
/*
The system resource limits for core are soft limit - 0, hard limit - -1
*/
