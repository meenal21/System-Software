/*
================================================================================
Name: 16.c
Author: Meenal Jain
Description: Write a program to perform mandatory locking.
a. implement write lock
b. implement read lock
Date: 31st August 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

void set_write_lock(int fd){
	struct flock lock;

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	printf("Acquiring write lock! \n");

	if(fcntl(fd, F_SETLKW, &lock)== -1){
		perror("Error acquiring write lock");
		exit(EXIT_FAILURE);
	}
	printf("Write lock acquired successfully");
}

void set_read_lock(int fd){
	struct flock lock;

	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	printf("Acquiring read lock! \n");

	if(fcntl(fd, F_SETLKW, &lock) == -1){
		perror("Error acquiring read lock\n");
		exit(EXIT_FAILURE);
	}
	printf("Read lock acquired successfully\n");
}

void release_lock(int fd){
	struct flock lock;

	lock.l_type = F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	printf("Releasing the lock\n");

	if(fcntl(fd, F_SETLKW, &lock) == -1){
		perror("Error releasing lock\n");
		exit(EXIT_FAILURE);
	}

	printf("Lock released successfully!\n");
}

int main(int argc, char *argv[]){

	const char *path = argv[1];

	int fd = open(path, O_RDWR);
	if(fd == -1){
		perror("Error opening the file!");
		exit(EXIT_FAILURE);
	}

	// setting file permission for mandatory locking
	
	if(chmod(path, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP) == -1){
		perror("Error setting file permissions");
		close(fd);
		exit(EXIT_FAILURE);
	}

	set_write_lock(fd);

	sleep(5);

	release_lock(fd);

	set_read_lock(fd);

	sleep(5);

	release_lock(fd);

	close(fd);

	return 0;
}

/* Solution

Acquiring write lock! 
Write lock acquired successfullyReleasing the lock
Lock released successfully!
Acquiring read lock! 
Read lock acquired successfully
Releasing the lock
Lock released successfully!

*/
