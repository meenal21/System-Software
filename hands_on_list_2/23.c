/*
================================================================================
Name: 23.c
Author: Meenal Jain
Description: Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

int main() {
    // Get the maximum number of open files
    long max_open_files = sysconf(_SC_OPEN_MAX);
    if (max_open_files == -1) {
        perror("sysconf");
        exit(EXIT_FAILURE);
    }

    // Get the size of the pipe (circular buffer)
    // Since there is no standard way to get the pipe size in C, we assume the default size
    // Pipe size can vary between systems, but common values are 4096 bytes
    long pipe_size = 4096; // Default pipe size; adjust as necessary for your system

    printf("Maximum number of open files: %ld\n", max_open_files);
    printf("Size of a pipe (circular buffer): %ld bytes\n", pipe_size);

    return 0;
}
/*
Maximum number of open files: 1024
Size of a pipe (circular buffer): 4096 bytes
*/
