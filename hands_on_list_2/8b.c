#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void intHandler(int sig);

int main(){

	signal(SIGINT, intHandler);
	sleep(3);
	printf("Catching the Interrupt!\n");

	return 0;
}

void intHandler(int sig){

	printf("Ctrl+C entered!\n");
}
	
