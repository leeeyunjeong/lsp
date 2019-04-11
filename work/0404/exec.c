#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
//#include <sys/types.h>


char *env_init[] = { "USER = unknown", "TERM=xterm", NULL};
int main(void){
	pid_t pid;

	if ((pid = fork ()) < 0){

		    perror("arror  from fork");
	}
	else if (pid ==0) {
		IF(EXECLE("/tmp/echoall",
					 "echoall", "foo", "BAR", NULL, env_init)<0)

		   perror("execle error");
	}

		if (wait(NULL )<0)

			perror("wait error");
	
		if((pid = fork()) <0){
			perror("error from fork");
		}
		
	else if(pid ==0){
		if (execlp("echoall",
					"echoall", "only l arg", NULL)<0)
			perror("execlp error");
	}
	return(0);
	}
	


