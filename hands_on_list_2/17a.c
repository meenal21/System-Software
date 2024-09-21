/*
================================================================================
Name: 17a.c
Author: Meenal Jain
Description: 17. Write a program to execute ls -l | wc.
a. use dup
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2]; // Pipe file descriptors
    pid_t pid1, pid2;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // First child: Execute 'ls -l'
    if ((pid1 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) { // Child process
        // Close unused write end
        close(pipefd[1]);
        // Duplicate read end to stdin
        dup(pipefd[0]); 
        close(pipefd[0]); // Close original read end

        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls"); // Only reached if execlp fails
        exit(EXIT_FAILURE);
    }

    // Second child: Execute 'wc'
    if ((pid2 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) { // Child process
        // Close unused read end
        close(pipefd[0]);
        // Duplicate write end to stdout
        dup(pipefd[1]); 
        close(pipefd[1]); // Close original write end

        execlp("wc", "wc", NULL);
        perror("execlp wc"); // Only reached if execlp fails
        exit(EXIT_FAILURE);
    }

    // Parent process: close both ends of the pipe
    close(pipefd[0]);
    close(pipefd[1]);

    // Wait for both children to finish
    wait(NULL);
    wait(NULL);

    return 0;
}
/*
total 420
-rw-rw-r-- 1 ubuntu ubuntu   968 Sep 21 20:19 10a.c
-rw-rw-r-- 1 ubuntu ubuntu  1023 Sep 21 20:18 10b.c
-rw-rw-r-- 1 ubuntu ubuntu   968 Sep 21 20:17 10.c
-rw-rw-r-- 1 ubuntu ubuntu   983 Sep 21 20:19 10c.c
-rw-rw-r-- 1 ubuntu ubuntu  1323 Sep 21 20:24 11.c
-rw-rw-r-- 1 ubuntu ubuntu   998 Sep 12 14:18 12.c

*/

