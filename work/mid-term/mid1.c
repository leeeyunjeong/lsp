#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
 
  int glob = 42; 
 
 
 int main(void){ 
int var; 
pid_t pid; 
var = 88;  
if ((pid = fork ()) < 0){ 
 perror("arror  from fork"); 
}  
else if (pid ==0) { 
 printf("child pid:  %d\n", getpid()); 
  glob++; 
  var++; 
				 
	} 

	else { 
 printf("parent pid:  %d\n", getpid()); 
			  sleep(1); 
	} 
		 
   printf("pid =%d, glob = %d, var = %d\n",  getpid(), glob,var); 
	 
	return(0); 
	 } 

