#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(void){
	pid_t pid;
    int i;

for(i=0; i<5; i++){

	if ((pid = fork ()) < 0){
		    perror("arror  from fork");
}
	else if (pid ==0) {
		   printf("bye from child %d: %d\n", i, getpid());
		   return(0);
	} //자식은 여기까지 에서 쪽난다
else{
} //부모프로세스는 아무것도 안해준다

}
sleep(60); //waiting for 
printf("bye from parent\n");	
	return(0);
	}



