/*
================================================================================
Name: 22.c
Author: Meenal Jain
Description: Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>

#define FIFO_NAME "my_fifo"

int main() {
    // Create a FIFO
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for data to be written into FIFO %s...\n", FIFO_NAME);

    // Open the FIFO for reading
    int fifo_fd = open(FIFO_NAME, O_RDONLY | O_NONBLOCK);
    if (fifo_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    fd_set readfds;
    struct timeval timeout;

    // Set up the file descriptor set
    FD_ZERO(&readfds);
    FD_SET(fifo_fd, &readfds);

    // Set timeout to 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    // Wait for data to be written into the FIFO
    int retval = select(fifo_fd + 1, &readfds, NULL, NULL, &timeout);

    if (retval == -1) {
        perror("select");
        close(fifo_fd);
        exit(EXIT_FAILURE);
    } else if (retval == 0) {
        printf("Timeout: No data written to FIFO within 10 seconds.\n");
    } else {
        // Data is available to read
        char buffer[256];
        ssize_t bytesRead = read(fifo_fd, buffer, sizeof(buffer) - 1);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0'; // Null-terminate the string
            printf("Received data: %s\n", buffer);
        } else {
            perror("read");
        }
    }

    close(fifo_fd);
    unlink(FIFO_NAME); // Clean up FIFO file
    return 0;
}
/*
Waiting for data to be written into FIFO my_fifo...
Timeout: No data written to FIFO within 10 seconds.
*/
