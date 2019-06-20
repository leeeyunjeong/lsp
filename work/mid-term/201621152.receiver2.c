#include<stdio.h>
 #include <sys/ipc.h>
 #include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1024
	 
void die(char *s)
{
	perror(s);
	exit(1);
}

typedef struct magbuf
{
	long mytype;

