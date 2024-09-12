#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void fpeHandler(int sig);

int main(){
	
	signal(SIGFPE, fpeHandler);
	int x;
	x = 5/0;
	printf("Caught the SIGFPE signal!");	
	return 0;
}

void fpeHandler(int sig){
	printf("Arithmetic issue has been caught!");
	exit(0);
}
