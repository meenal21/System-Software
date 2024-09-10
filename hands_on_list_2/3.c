#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main(){

	int ret;
	struct rlimit rlim;
	rlim.rlim_cur = 5;

	ret = setrlimit(RLIMIT_CORE, &rlim);
	if(ret == -1){
		perror("Set Resource Limit Failed");
	}
	else{
		printf("The soft core Resource Limit has been set to 5 \n");
	}
	return 0;
}
