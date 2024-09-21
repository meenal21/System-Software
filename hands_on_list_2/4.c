/*
================================================================================
Name: 4.c
Author: Meenal Jain
Description: Write a program to measure how much time is taken to execute 100 getppid( ) system call. Use time stamp counter.
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ (
        "rdtsc"
        : "=a"(lo), "=d"(hi)
    );
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    int i;
    uint64_t start, end;
    pid_t ppid;

    // Read the timestamp counter before the loop
    start = rdtsc();

    // Perform 100 getppid() calls
    for (i = 0; i < 100; i++) {
        ppid = getppid();
    }

    // Read the timestamp counter after the loop
    end = rdtsc();

    // Calculate the elapsed cycles
    uint64_t elapsed_cycles = end - start;

    printf("Executed 100 getppid() system calls in %lu cycles.\n", elapsed_cycles);
    printf("Parent process ID: %d\n", ppid);

    return 0;
}
/*
Executed 100 getppid() system calls in 57650 cycles.
Parent process ID: 2932
*/
