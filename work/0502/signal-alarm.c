#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int counter = 0;

void sigint_handler(int signo){
	printf("알람 발생 %dil\n", counter++);
//	alarm(1);
}

int main(void){
	int i =0;
	signal(SIGALRM, sigint_handler);
	alarm(5);

	while(i<10){
	printf("%d\n", i);
//	sleep(1);
	i++;
	}

	alarm(5);

	return(0);
}


