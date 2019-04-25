#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
			
 int main(int argc , char *argv[]){
 char sum;
  int sum++;

	 printf("d\n", argc);
     printf("%s%s%s\n", *argv);

if ((sum = fork ()) < 0){
 perror("arror  from fork");
}
else if (pid ==0) {
printf("child1 sum: %d\n", sum);
  sum++;
  }
 else if(sum ==0) {
 printf("child2 sum:  %d\n",sum);
sum++
 }
  else  {
 printf("parent pid:  %d\n", sum); 
 printf("parent = child1+ child2");
 }
 printf("child1 =%d, child2 = %d, sum = %d\n",  sum);
 return(0);   
 }

