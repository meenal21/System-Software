/*
================================================================================
Name: 9.c
Author: Meenal Jain
Description: Write a program to print the following informtation about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change

Date: 29th August 2024
================================================================================
*/


#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main( int argc, char *argv[])
{
	int stat_ret;
	struct stat st_obj;
	
	stat_ret = stat("/home/ubuntu/file1", &st_obj);

	if(stat_ret==0){
		printf("Details of the file are: \n");
		printf("Inode number: %ld \n",st_obj.st_ino);
		printf("Number of Hard Links: %ld \n", st_obj.st_nlink);
		printf("UID: %d \n", st_obj.st_uid);
		printf("GID: %d \n", st_obj.st_gid);
		printf("Size of the file: %ld \n", st_obj.st_size);
		printf("Block Size: %ld \n", st_obj.st_blksize);
		printf("Number of blocks allocated: %ld \n", st_obj.st_blocks);
		printf("Time of Last Access: %ld \n", st_obj.st_atime);
		printf("Time of Last Modification: %ld \n", st_obj.st_mtime);
		printf("Time of Last Change: %ld \n", st_obj.st_ctime);
		return 0;
	}
	return 1;
}
