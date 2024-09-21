/*
================================================================================
Name: 10a.c
Author: Meenal Jain
Description: Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGSEGV
void handle_sigsegv(int sig) {
    printf("Caught SIGSEGV: Segmentation fault occurred!\n");
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa_seg;

    // Set up the SIGSEGV handler
    sa_seg.sa_handler = handle_sigsegv;
    sigemptyset(&sa_seg.sa_mask);
    sa_seg.sa_flags = 0;
    sigaction(SIGSEGV, &sa_seg, NULL);

    // Trigger SIGSEGV by dereferencing a null pointer
    int *p = NULL;
    *p = 42; // This line will cause SIGSEGV

    return 0;
}
/*
Caught SIGSEGV: Segmentation fault occurred!
*/
