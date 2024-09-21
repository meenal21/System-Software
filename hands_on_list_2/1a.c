/*
================================================================================
Name: 1a.c
Author: Meenal Jain
Description: 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date: 21st September 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_alarm(int signum) {
    printf("ITIMER_REAL: Timer expired!\n");
}

int main() {
    struct itimerval timer;

    // Set the timer for 10 seconds and 10 microseconds
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 0; // No repeating
    timer.it_interval.tv_usec = 0;

    // Register the signal handler
    signal(SIGALRM, handle_alarm);

    // Set the timer
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(EXIT_FAILURE);
    }

    // Wait for the timer to expire
    pause();
    return 0;
}
/*
ITIMER_REAL: Timer expired!
*/
