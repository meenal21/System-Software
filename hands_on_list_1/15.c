/*
================================================================================
Name: 15.c
Author: Meenal Jain
Description: Write a program to display the environment variable of the user(use environ)
Date: 31st August 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ; 

int main(){
	
	char **env = environ;

	//iterating through the environment variables
	while(*env){
		printf("%s\n",*env);
		env++;
	}
	return 0;
}

/* Solution
SHELL=/bin/bash
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
*/
