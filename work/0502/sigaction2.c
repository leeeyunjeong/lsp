#include<stdio.h>
#include<signal.h>
#include<unistd.h>


void sigint_handler(int signo){
	int ndx;

	printf("Ctrl-C 키를 늘루셨죠\n");
	printf("5초간 대기하겠습니다.이때 Ctrl-2키를 눌러주세요\n");
    
		for(ndx = 3; 0 < ndx; ndx--) {
					printf("%d 초 남았습니다\n", ndx);
					sleep(1);
					}
}

int main(void){
	struct sigaction act;

	act.sa_handler = sigint_handler;
	sigfillset(&act.sa_mask);

	sigaction(SIGINT, &act, NULL);

	while(1){
		printf("signal handler registered for SIGINT\n");
		sleep(1);
	}
	return(0);
}


