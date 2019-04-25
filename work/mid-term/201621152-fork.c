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
 printf("201621152:  %d\n", getpid()); 
  glob++; 
  var++; 
				 
	} 
else if(pid ==0) {
	  printf("leeyunjeong:  %d\n", getpid());
	 glob++;
	  var++;

}
	else  { 
 printf("parent pid:  %d\n", getpid()); 
			  sleep(1); 
	} 
		 
   printf("pid =%d, glob = %d, var = %d\n",  getpid(), glob,var); 
	 
	return(0); 
	 } 

