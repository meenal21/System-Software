/*
================================================================================
Name: 18.c
Author: Meenal Jain
Description: Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipe1[2]; // Pipe for ls -l | grep ^d
    int pipe2[2]; // Pipe for grep | wc
    pid_t pid1, pid2, pid3;

    // Create first pipe
    if (pipe(pipe1) == -1) {
        perror("pipe1");
        exit(EXIT_FAILURE);
    }

    // Create second pipe
    if (pipe(pipe2) == -1) {
        perror("pipe2");
        exit(EXIT_FAILURE);
    }

    // First child: Execute 'ls -l'
    if ((pid1 = fork()) == -1) {
        perror("fork1");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) { // Child process
        dup2(pipe1[1], STDOUT_FILENO); // Redirect stdout to pipe1's write end
        close(pipe1[0]); // Close unused read end
        close(pipe1[1]); // Close original write end

        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls"); // Only reached if execlp fails
        exit(EXIT_FAILURE);
    }

    // Second child: Execute 'grep ^d'
    if ((pid2 = fork()) == -1) {
        perror("fork2");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) { // Child process
        dup2(pipe1[0], STDIN_FILENO); // Redirect stdin to pipe1's read end
        close(pipe1[0]); // Close original read end
        close(pipe1[1]); // Close unused write end
        dup2(pipe2[1], STDOUT_FILENO); // Redirect stdout to pipe2's write end
        close(pipe2[0]); // Close unused read end
        close(pipe2[1]); // Close original write end

        execlp("grep", "grep", "^d", NULL);
        perror("execlp grep"); // Only reached if execlp fails
        exit(EXIT_FAILURE);
    }

    // Third child: Execute 'wc'
    if ((pid3 = fork()) == -1) {
        perror("fork3");
        exit(EXIT_FAILURE);
    }

    if (pid3 == 0) { // Child process
        dup2(pipe2[0], STDIN_FILENO); // Redirect stdin to pipe2's read end
        close(pipe2[0]); // Close original read end
        close(pipe2[1]); // Close unused write end

        execlp("wc", "wc", "-l", NULL); // Count lines
        perror("execlp wc"); // Only reached if execlp fails
        exit(EXIT_FAILURE);
    }

    // Parent process: close all pipe ends
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

    // Wait for all children to finish
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
/*

*/
