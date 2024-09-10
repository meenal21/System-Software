/*
================================================================================
Name: 3.c
Author: Meenal Jain
Description: Write a program to set a system resource limit.
Date: 10th September 2024
================================================================================
*/
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main(){

	int ret;
	struct rlimit rlim;
	rlim.rlim_cur = 5;

	ret = setrlimit(RLIMIT_CORE, &rlim);
	if(ret == -1){
		perror("Set Resource Limit Failed");
	}
	else{
	      
		printf("The soft core Resource Limit has been set to 5 \n");
	}
	return 0;
}
/* 
The soft core Resource Limit has been set to 5
*/
