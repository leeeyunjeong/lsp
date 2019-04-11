#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>

char buf[] = " write to stdout\n";

int main(void){
	pid_t pid;

	//write() is a system call provided by OS
	if (write(STDOUT_FILENO, buf, strlen(buf)) != strlen(buf))
		    perror("write error");



	printf("printf by %d: before fork\n", getpid());
	if((pid = fork())<0){
      perror("arror from fork");}

	else if (pid ==0) {
		   printf(" printf by %d: hi from child\n", getpid());
		   
		   //printf("hi from child! %d\n", getppid());
	}
	
	else {
	
	    printf("printf by %d: hi from parent\n", getpid());
	}
	printf("printf by %d: bye\n", getpid());
	

	//printf("bye %d\n", getpid());
	
	return(0);
	}
	//}


