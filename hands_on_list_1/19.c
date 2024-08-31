/*
================================================================================
Name: 19.c
Author: Meenal Jain
Description: Write a program to find out time taken to execute getpid system call. Use time stamp counter
a. implement write lock
Date: 31st August 2024
================================================================================
*/

#include <unistd.h>
#include <stdio.h>


unsigned long long read_tsc(){
	unsigned int low, high;

	__asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
	return ((unsigned long long)high << 32) | low;
}

int main(){

	unsigned long long start, end;

	start = read_tsc();

	getpid();

	end = read_tsc();

	printf("Clock cyles taken by getpid(): %llu \n", end-start);

	return 0;
}

/* Output 

Clock cyles taken by getpid(): 9900

*/
