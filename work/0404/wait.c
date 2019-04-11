#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
//#include <sys/types.h>


int main(void){
	pid_t pid;
    int status;

	//printf("before fork (%d)\n", getpid());

	if ((pid = fork ()) < 0)
		    perror("arror  from fork");

	else if (pid ==0) {
		   printf("hi from child\n");
		   exit(7);
		   //printf("hi from child! %d\n", getppid());
	}
	
	else {
		if (wait(&status) != pid)
			perror("wait error");
	
	    printf("hi from parent\n");

		//void pr_exit(int status){

   	    if(WIFEXITED(status))//자식이 죽으면서 부모한테 남김 위에 exit숫자
				  printf("nomal termination, exit status=%d\n",
					  WEXITSTATUS(status));

	else if(WIFSIGNALED(status))
	      printf("abnormal termination, signal number = %d\n",WTERMSIG(status));
		  //printf("hi from parent! %d\n", getppid());
	}

	//printf("bye %d\n", getpid());
	
	return(0);
	}
	//}


