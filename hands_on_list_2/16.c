#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define BUF_SIZE 10

int main(int argc, char *argv[]){

	int fd1[2], fd2[2]; // made 2 file descriptors
	ssize_t nr1, nr2;
	char buf1[BUF_SIZE];
	char buf2[BUF_SIZE];

	pipe(fd1);
	pipe(fd2);

	pid_t pid = fork();

	if(pid == -1){
		perror("fork");
		exit(0);
	}
	if(pid > 0){
		if(close(fd1[0])==-1){
			perror("close-read-parent");
			exit(0);
		}
		if(write(fd1[1],argv[1], strlen(argv[1]))!=strlen(argv[1])){
			perror("write-parent");
			exit(0);
		}
		if(close(fd1[1])==-1){
			perror("close-write-parent");
			exit(0);
		}
		wait(NULL);
		if(close(fd2[1])==-1){
			perror("close");
			exit(0);
		}
		for(;;){
			nr2 = read(fd2[0],buf2,BUF_SIZE);
			if(nr2 == -1){
				perror("read-parent");
				exit(0);
			}	
			if(nr2==0)
				break;
			else{
				if(write(STDOUT_FILENO,buf2,nr2)!=nr2){
					perror("write-parent-out");
					exit(0);
				}
			}
		}
		if(write(STDOUT_FILENO,"\n",1)!=1){
			perror("write");
			exit(0);
		}
		if(close(fd2[0])==-1){
			perror("close");
			exit(0);
		}
	}
	else{
		if(close(fd1[1])==-1){
			perror("close");
			exit(0);
		}
		for(;;){
			nr1 = read(fd1[0],buf1, BUF_SIZE);
			if(nr1 == -1){
				perror("Read");
				exit(0);
			}
			if(nr1 ==  0)
				break;
			if(nr1 > 0){
				if(write(STDOUT_FILENO, buf1, nr1)!=nr1){
					perror("write");
					exit(0);
				}
			}

		}
		if(write(STDOUT_FILENO,"\n",1)!=1){
			perror("write");
			exit(0);
		}
		if(close(fd1[0])==-1){
			perror("close");
			exit(0);
		}
		if(close(fd2[0])==-1){
			perror("close");
			exit(0);
		}
		if(write(fd2[1], argv[2],strlen(argv[2])!=strlen(argv[2]))){
			perror("write");
			exit(0);
		}
		if(close(fd2[1])==-1){
			perror("close");
			exit(0);
		}
	}


	return 0;
}
