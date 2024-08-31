/*
================================================================================
Name: 30.c
Author: Meenal Jain
Description: Write a program to run a script at a specific time using a Daemon process.
Date: 31st August 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define HOUR 23
#define MINUTE 39

void daemonize(){

	pid_t pid = fork();
	if(pid < 0) exit(EXIT_FAILURE);
	if(pid > 0) exit(EXIT_SUCCESS);

	if(setsid() < 0) exit(EXIT_FAILURE);

	pid = fork();
	if(pid < 0) exit(EXIT_FAILURE);
        if(pid > 0) exit(EXIT_SUCCESS);

	chdir("/");
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	open("/dev/null", O_RDONLY);
	open("/dev/null",O_RDWR);
	open("/dev/null", O_RDWR);
}

int main(int argc, char *argv[]){

	time_t now;
	struct tm target_tm;
	double seconds_until_target;

	daemonize();

	time(&now);

	struct tm *tm_info = localtime(&now);

	target_tm = *tm_info;
	target_tm.tm_hour = HOUR;
	target_tm.tm_min = MINUTE;
	target_tm.tm_sec = 0;
	target_tm.tm_isdst = -1;

	time_t target_time = mktime(&target_tm);
	seconds_until_target = difftime(target_time, now);

	if(seconds_until_target < 0) seconds_until_target += 86400;

	sleep((unsigned int)seconds_until_target);
	system(argv[1]);

	return 0;
}

