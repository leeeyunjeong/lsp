#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(void){
	pid_t pid;


	printf("before fork (%d)\n", getpid());

	if ((pid = fork ()) < 0){
		    perror("arror  from fork");
	}
	
	else if (pid ==0) {
		   printf("hi from child! %d\n", getpid());
		   printf("hi from child! %d\n", getppid());
	}
	
	else {
		wait(NULL);//아이가 죽기전까지 기다린다
		  printf("hi from parent! %d\n", getpid());
		  printf("hi from parent! %d\n", getppid());
	}

	printf("bye %d\n", getpid());
	
	return(0);
}

