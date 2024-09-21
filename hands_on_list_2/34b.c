/*
================================================================================
Name: 34b.c
Author: Meenal Jain
Description: Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Date: 21st September 2024
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *client_socket_ptr) {
    int client_socket = *(int *)client_socket_ptr;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(client_socket, buffer, sizeof(buffer))) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Received: %s", buffer);
        send(client_socket, buffer, bytes_read, 0); // Echo back
    }

    close(client_socket);
    free(client_socket_ptr); // Free the allocated memory
    return NULL;
}

int main() {
    int server_fd, *new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        new_socket = malloc(sizeof(int)); // Allocate memory for socket descriptor
        *new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (*new_socket < 0) {
            perror("accept");
            free(new_socket);
            continue;
        }

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, new_socket) != 0) {
            perror("pthread_create");
            free(new_socket);
            continue;
        }

        pthread_detach(tid); // Detach the thread to clean up resources automatically
    }

    return 0;
}
