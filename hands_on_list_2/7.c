/*
================================================================================
Name: 6.c
Author: Meenal Jain
Description: Write a simple program to print the created thread ids.
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    // Retrieve the thread ID from the argument
    pthread_t thread_id = pthread_self();
    printf("Thread ID: %lu is running.\n", thread_id);
    sleep(1); // Simulate some work
    printf("Thread ID: %lu has finished.\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];

    // Create three threads
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished execution.\n");
    return 0;
}
/*
Thread ID: 126417119479488 is running.
Thread ID: 126417140451008 is running.
Thread ID: 126417129965248 is running.
Thread ID: 126417140451008 has finished.
Thread ID: 126417119479488 has finished.
Thread ID: 126417129965248 has finished.
All threads have finished execution.
*/
