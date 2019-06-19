#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main(void){
	sigset_t sigset;
	int ndx;
	
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	sigprocmask(SIG_BLOCK, &sigset, NULL);

	for(ndx = 10; 0< ndx; ndx--){
		printf("카운트다운 %d\n", ndx);
		sleep(1);
	}

	printf("Ctr;-C에 대한 블록을 해제합니다\n");
    sigprocmask( SIG_
	i++;
	}

	alarm(5);

	return(0);
}


