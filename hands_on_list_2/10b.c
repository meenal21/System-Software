/*
================================================================================
Name: 10b.c
Author: Meenal Jain
Description: Write a separate program using sigaction system call to catch the following signals.
b. SIGINT
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGINT
void handle_sigint(int sig) {
    printf("Caught SIGINT: Interrupt signal received!\n");
    exit(EXIT_SUCCESS);
}

int main() {
    struct sigaction sa_int;

    // Set up the SIGINT handler
    sa_int.sa_handler = handle_sigint;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;
    sigaction(SIGINT, &sa_int, NULL);

    printf("Press Ctrl+C to send SIGINT.\n");

    // Infinite loop to keep the program running
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}
/*
Press Ctrl+C to send SIGINT.
^CCaught SIGINT: Interrupt signal received!
*/
