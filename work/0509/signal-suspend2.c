#include <stdio.h>
 #include <unistd.h>
 #include <signal.h>

struct sigaction act_new;
struct sigaction act_old;

 int main(void) {
	 sigset_t sigset;


	 
	 struct stgaction act_new;
  act_new.sa_handler = sigint_handler;


	 sigemptyset(&sigset);
	 sigaddset(&sigset, SIGINT);

	printf("PID: %d, waiting for any signal except SIGINT\n", getpid());
	 
	sigsuspend(&sigset);
	
	return 0;
}
