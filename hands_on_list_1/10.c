/*
================================================================================
Name: 10.c
Author: Meenal Jain
Description: Write a program to open a file with read write mode, write 10 bytes, mode the file pointer by 10 bytes(use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
================================================================================
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	
	int f_d;
	const char *str = "Adding 10 bytes to the file";
	int w_ret;
	int l_off;

	f_d = open("/home/ubuntu/ss_assignment/System-Software/hands_on_list_1/demofile", O_RDWR);
	if(f_d != -1){
		w_ret = write(f_d, str, 10);
		l_off = lseek(f_d, 10, SEEK_CUR);
		printf("The lseek return value is %d \n", l_off);
		/* The lseek return value is 20*/
		w_ret = write(f_d, str,10);
		/* od demofile - 0000000 062101 064544 063556 030440 020060 000000 000000 000000 0000020 000000 000000 062101 064544 063556 030440 020060 0000036 */

	}
	/* closing the opened file */
	close(f_d);
	
	return 0;
}
