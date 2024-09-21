/*
================================================================================
Name: 6.c
Author: Meenal Jain
Description: Write a simple program to create three threads.
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    printf("Thread %d is running.\n", thread_id);
    sleep(1); // Simulate some work
    printf("Thread %d has finished.\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3];

    // Create three threads
    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i + 1; // Assign thread IDs
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
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
Thread 2 is running.
Thread 1 is running.
Thread 3 is running.
Thread 1 has finished.
Thread 2 has finished.
Thread 3 has finished.
All threads have finished execution.
*/
