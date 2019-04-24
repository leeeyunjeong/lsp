/*#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

void has_tty()
{
	int tty = open("/dev/tty", O_RDWR);
	if (tty > 0) {
		 printf("process %d has tty %d\n", getpid(), tty); 
		   } else {
			       printf("process %d has no tty\n", getpid()); 
				     }
}
int main(void) {
	  pid_t pid; 

	    if ( (pid = fork()) < 0) { 
			    printf("fork error\n"); exit(1);

		  } else if (pid == 0) { 
	        has_tty();
		    setsid();
		    has_tty(); 

	    if ( (pid = fork()) < 0) { 
	     printf("fork error\n"); exit(1);

		 } else if (pid > 0) { 
																				      exit(0);     }    
		has_tty();
	    sleep(2);
	   printf("second child, ppid = %d\n", getppid());
	   exit(0);
	   }*/

/*#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
	    pid_t p1 = fork();

		    if (p1 != 0)
				    {
	     printf("p1 process id is %d", getpid());							        wait();
		system("ps");
				    }
	    else
		 {    
			 pid_t p2 = fork();
		     int pid = getpid();

		    if (p2 != 0) 
      {
																	            printf("p2 process id is %d", pid);
																				        }		  
			else
	   {
																			            printf("p3 process id is %d", pid);
																						        }
     exit(0);
	    }
}*/
#include<stdio.h>
#include <unistd.h>
//#include <sys wait.h>
#include <errno.h>

int main(int argc, char **argv)
{
	pid_t pid;

	if ( (pid = fork())>0)
		{
			waitpid(pid,NULL,0);
			while(1);
			}
    else if( pid ==0)
	{ if((pid = fork())>0)
		{
			return 0;
		}
		else if(pid ==0)
		{
			sleep(2);
		}
		return 0 ;
	}
	else
	{
		int errsy = errno;
		perror("fork error");
		return errsy;
	}
	return 0;
}

