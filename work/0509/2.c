#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	double i;
	double j;
//	char *bug = malloc(sizeof(int));
  char *bug = malloc(sizeof(char *));

	
	 
	for(i=0; i<5; i++){
		printf("loop %d: ",(int)i);
		j= i/2 + i;
		printf("\tj is %1f \n",j);
	}

	strcpy(bug,"hi");
	printf("bug is %s\n", bug);

	return 0;
}
