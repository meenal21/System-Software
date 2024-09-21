/*
================================================================================
Name: 19.c
Author: Meenal Jain
Description: Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
d. mknod system call
e. mkfifo library function
Date: 21st September 2024
================================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *fifo_name = "my_fifo6";

    // Create FIFO using mkfifo
    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("FIFO created with mkfifo: %s\n", fifo_name);
    return 0;
}

/*
FIFO created with mknod: my_fifo6

*/
