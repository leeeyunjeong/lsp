#include <stdio.h>
#include <stdlib>
#include <unistd.h>
//#include "helper.h"

void ch(char *str) {
	char *p;
	int c;

	setbuf(stdout, NULL);

	for (p =  str; (c = *p++) != 0;)
		putc(c, stdout);
}
int main {
   pid_t pid;

   if((pid = fork()) <0 ){
	   perror("fork() error");
	   exit(1);}

   else if (pid ==0){
   ch("output from child\n");
   }
   else{
	   ch("output from parent\n");
   }
   return 0;
}

