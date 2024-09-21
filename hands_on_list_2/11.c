/*
================================================================================
Name: 11.c
Author: Meenal Jain
Description: Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call.
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGINT (currently does nothing)
void ignore_sigint(int sig) {
    printf("SIGINT signal ignored.\n");
}

int main() {
    struct sigaction sa_ignore, sa_default;

    // Set up the SIGINT handler to ignore the signal
    sa_ignore.sa_handler = ignore_sigint;
    sigemptyset(&sa_ignore.sa_mask);
    sa_ignore.sa_flags = 0;
    sigaction(SIGINT, &sa_ignore, NULL);

    printf("SIGINT is now being ignored. Press Ctrl+C to test it.\n");
    sleep(5); 

    sa_default.sa_handler = SIG_DFL; 
    sigemptyset(&sa_default.sa_mask);
    sa_default.sa_flags = 0;
    sigaction(SIGINT, &sa_default, NULL);

    printf("SIGINT has been reset to default action. Press Ctrl+C again.\n");
    sleep(5); 

    return 0;
}
/*

SIGINT is now being ignored. Press Ctrl+C to test it.
^CSIGINT signal ignored.
SIGINT has been reset to default action. Press Ctrl+C again.
^C
*/
