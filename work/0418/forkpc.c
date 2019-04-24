/*#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> 
#include <sys/types.h> 

void ch(char *str) {
	char *p;
	int c;

	setbuf(stdout, NULL);

	for(p = str; (c = *p++) |=0;)
		putc(c, stdout);
}

int main(void){
	pid_t pid;

	if((pid = fork()) <0){
		perror("fork() error");
		exit(1);
	}
	else if(pid == 0){
		ch("output from child\n");
	}
	else{
		ch("output from parent\n");
	}

	return (0);
}
*/

#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/wait.h> 
  
int main() 
{ 
	    pid_t pid; 
		  
		    // fork first time 
		    pid = fork(); 
			  
			    if (pid == 0) 
					    {       // double fork 
   pid = fork(); 
    if (pid == 0) 
      printf("Grandchild pid : %d\n Child"
																	               " pid : %d\n", getpid(), getppid()); 
									    } 
				  		    else
		 { 
      wait(NULL); 
	       sleep(10); 
	  } 
} 

