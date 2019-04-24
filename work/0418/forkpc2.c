#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> 
#include <sys/types.h> 

void ch(char *str) {
	char *p;
	int c, s;
}

int main(void){
	pid_t pid, pid2, ppid;
	//printf() is provided from glibc
 // buffer is used for various reasons
	printf("before fork(); %d\n", getpid());

	if((pid = fork()) <0){
		perror("error from fork()\n");
	}

	else if(pid == 0){
		printf("hi from 1st child: my gid %d\n", getpid());

		if((pid2= fork()) <0){
			perror("error from fork()\n");
	}

	else if(pid2 ==0) {
		/* 2nd child */

		printf("hi from 2nd child: my pid %d\n", getpid());
		printf("hi from 2nd child: my ppid %d\n", getppid());
	}
		else{
			/* 1st child */
			exit(0);
		}
	}

	else{
		if( waitpid(pid, &s, WEXITED)){
		printf("hi from parent: my pid %d\n", getpid());
		}
	}
return (0);
}

