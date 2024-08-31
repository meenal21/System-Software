/*
================================================================================
Name: 18.c
Author: Meenal Jain
Description: Write a program to perform Record locking.
a. implement write lock
b. implement read lock

Create 3 records in the file. Whenever you access a particular record, first lock it and then modify/access to avoid race condition.
Date: 31st August 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>


struct Record{
	int id;
	int value;
};

void set_write_lock(int fd, int record_num){
	struct flock lock;
	
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = record_num * sizeof(struct Record);
	lock.l_len = sizeof(struct Record);

	printf("Acquiring write lock on record %d! \n", record_num);

	if(fcntl(fd, F_SETLKW, &lock)==-1){
		perror("Error acquiring write lock!\n");
		exit(EXIT_FAILURE);
	}
	printf("Write lock acquired successfully on record %d! \n", record_num);
}

void set_read_lock(int fd, int record_num){

	struct flock lock;

	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = record_num * sizeof(struct Record);
	lock.l_len = sizeof(struct Record);

	printf("Acquiring read lock on record %d! \n", record_num);

	if(fcntl(fd, F_SETLKW, &lock) == -1){
		perror("Error acquiring read lock!\n");
		exit(EXIT_FAILURE);
	}
	printf("Read lock acquired successfully on record %d! \n", record_num);
}

void release_lock(int fd, int record_num){

	struct flock lock;

	lock.l_type = F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = record_num * sizeof(struct Record);
	lock.l_len = sizeof(struct Record);

	printf("Releasing the lock on record %d \n",record_num);

	if(fcntl(fd, F_SETLKW, &lock )==-1){
		perror("Error releasing lock \n");
		exit(EXIT_FAILURE);
	}
	printf("Lock released successfully on record %d. \n", record_num);
}

void create_records(const char *filename){
	int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd == -1){
		perror("Error opening file!");
		exit(EXIT_FAILURE);
	}

	struct Record record;
	for(int i = 0; i <3; i++){
		record.id = i+1;
		record.value = (i+1) * 25;
		if(write(fd, &record, sizeof(struct Record))== -1){
			perror("Error writing to file! \n");
			close(fd);
			exit(EXIT_FAILURE);
		}
	}

	printf("Records created successfully in the file %s. \n", filename);
	close(fd);

}

void modify_record(int fd, int record_num, int new_value){
	struct Record record;

	set_write_lock(fd, record_num);

	lseek(fd, record_num * sizeof(struct Record), SEEK_SET);
	read(fd, &record, sizeof(struct Record));

	printf("Original record - ID %d, Value - %d \n", record.id, record.value);
	record.value = new_value;

	lseek(fd, record_num * sizeof(struct Record), SEEK_SET);
	write(fd, &record, sizeof(struct Record));
	printf("Modified Record - ID %d, Value - %d \n", record.id, record.value);

}

void read_record(int fd, int record_num){

	struct Record record;

	set_read_lock(fd, record_num);

	lseek(fd, record_num * sizeof(struct Record), SEEK_SET);
	read(fd, &record, sizeof(struct Record));
	printf("Read Record - ID %d, Value - %d\n", record.id, record.value);

	release_lock(fd, record_num);
}

int main(int argc, char *argv[]){
	const char *path = argv[1];

	create_records(path);

	int fd = open(path, O_RDWR);
	if(fd == -1){
		perror("Error opening file!\n");
		exit(EXIT_FAILURE);
	}

	modify_record(fd,0,500);

	read_record(fd,1);

	modify_record(fd, 2, 40);

	close(fd);
	return 0;
}

/* Output

Acquiring write lock on record 0! 
Write lock acquired successfully on record 0! 
Original record - ID 1, Value - 25 
Modified Record - ID 1, Value - 500 
Acquiring read lock on record 1! 
Read lock acquired successfully on record 1! 
Read Record - ID 2, Value - 50
Releasing the lock on record 1 
Lock released successfully on record 1. 
Acquiring write lock on record 2! 
Write lock acquired successfully on record 2! 
Original record - ID 3, Value - 75 
Modified Record - ID 3, Value - 40 

*/
