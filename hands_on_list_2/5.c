/*
================================================================================
Name: 5.c
Author: Meenal Jain
Description: Write a program to print the system limitation of 
a. max length of the arguments to the exec family of functions
b. max number of simultaneous process per user id
c. number of clock ticker per second
d. max size of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory

Date: 10th September 2024
================================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main(){

	long ret;

	ret = sysconf(_SC_ARG_MAX);
	if(ret!=-1){
		printf("Max number of arguments to the exec -  %ld\n", ret);
	}
	else{
		perror("Sysconf failed!\n");
	}
	ret = sysconf(_SC_CHILD_MAX);
	if(ret == -1)
		perror("sysconf failed");
	else
		printf("Max number of simultaneous process per user id - %ld \n", ret);
	ret = sysconf(_SC_CLK_TCK);
	if(ret == -1)
		perror("sysconf failed");
	else
		printf("Number of clock tickers per second -  %ld\n",ret);
	ret = sysconf(_SC_OPEN_MAX);
	if(ret == -1)
		perror("sysconf failed");
	else
		printf("Max number of files that a process can have open at any point of time - %ld\n", ret);
	ret = sysconf(_SC_PAGESIZE);
	if(ret == -1)
		perror("sysconf failed");
	else
		printf("Size of page in bytes - %ld\n", ret);
	ret = sysconf(_SC_PHYS_PAGES);
	if(ret == -1)
		perror("sysconf failed");
	else
		printf("Number of pages in physical memory %ld\n",ret);
	ret = sysconf(_SC_AVPHYS_PAGES);
	if(ret == -1)
		perror("sysconf failed");
	else
		printf("Number of currently available pages in the physical memory - %ld\n", ret);
return 0;
}

/*
Max number of arguments to the exec -  2097152
Max number of simultaneous process per user id - 14875 
Number of clock tickers per second -  100
Max number of files that a process can have open at any point of time - 1024
Size of page in bytes - 4096
Number of pages in physical memory 969837
Number of currently available pages in the physical memory - 289533
