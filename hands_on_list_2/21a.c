#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<stdlib.h>

#define BUF_SIZE 100

int main(){

	char msg[] = "This is the message from program 1";
	ssize_t nr1;
	char buf[BUF_SIZE];

	const char *fifo_path1 = "myfifo1";
	const char *fifo_path2 = "myfifo2";

	if(mkfifo(fifo_path1, 0666) == -1){
		perror("mkfifo");
		exit(0);
	}
	printf("Created pipe %s\n", fifo_path1);
	if(mkfifo(fifo_path2,0666)==-1){
		perror("mkfifo");
		exit(0);
	}
	printf("Created pipe %s\n", fifo_path2);

	// open first with write and second with read mode
	
	int fd1 = open("myfifo1", O_WRONLY);
	if(fd1 == -1){
		perror("open");
		exit(0);
	}
	int fd2 = open("myfifo2", O_RDONLY);
	if(fd2 == -1){
		perror("open");
		exit(0);
	}

	printf("First Prog writing to the pipe");
	if(write(fd1, msg, sizeof(msg))!=sizeof(msg)){
		perror("write");
		exit(0);
	}

	while(1){
		nr1 = read(fd2, buf, BUF_SIZE);
		if(nr1 == -1){
			perror("read");
			exit(0);
		}
		if(nr1 == 0)
			break;
		if(nr1 > 0){
			if(write(STDOUT_FILENO, buf, nr1)!=nr1){
				perror("write");
				exit(0);
			}
		}
	}

	write(STDOUT_FILENO, "\n", 1);
	close(fd1);
	close(fd2);
	return 0;
		
}

