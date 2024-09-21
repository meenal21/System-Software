/*
================================================================================
Name: 10c.c
Author: Meenal Jain
Description: Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGFPE
void handle_sigfpe(int sig) {
    printf("Caught SIGFPE: Floating-point exception occurred!\n");
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa_fpe;

    // Set up the SIGFPE handler
    sa_fpe.sa_handler = handle_sigfpe;
    sigemptyset(&sa_fpe.sa_mask);
    sa_fpe.sa_flags = 0;
    sigaction(SIGFPE, &sa_fpe, NULL);

    // Trigger SIGFPE by dividing by zero
    int a = 1, b = 0;
    printf("Result: %d\n", a / b); // This line will cause SIGFPE

    return 0;
}
/*
Caught SIGFPE: Floating-point exception occurred!
*/
