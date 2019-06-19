 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/msg.h>

 #define BUFF_SIZE 1024

 typedef struct {
 long data_type;
 int data_num;
 char data_buff[BUFF_SIZE];
 } 
 msg_t;

 int main(int argc, char *argv[]) {
 int msqid;
 int i;
 msg_t data;
 struct msqid_ds msqstat;
 
 if(argc < 2) {
 perror("parameter is required");
 exit(1);
 }
		 
 if(-1 == (msqid = msgget((key_t)8875, IPC_CREAT | 0666))) {
 perror("msgget() error");
 exit(1);
 }

 if(-1 == msgctl(msqid, IPC_STAT, &msqstat)) {
 perror("msgctl() error");
 exit(1);
	   }

 printf("# of msg in the queue: %ld\n", msqstat.msg_qnum);
 printf("PID of last msgend: %d\n", msqstat.msg_lrpid);
 printf("PID of last msgrcv: %d\n", msqstat.msg_lrpid);


 for(i = 0; i < msqstat.msg_qnum; i++) {	   
 rcv_byte = msgrcv(msqid, &data, sizeof(msg_t) - sizeof(long),atoi(argv[1], 0));
 
  if (-1 == rcv_byte){
  perror("msgrcv() error");
  exit(1);
  }	

  if(0 == rcv_byte){
  break;
  }

  if( -1 == msgctl(msqid, IPC_STAT, &msqstat)){
	  perror("msgctl() error");
	  exit(1);
	  }

  printf("# of msg in the queue: %sld\n" msqstat.msg_qnum);
  printf("PID of last msgend: %d\n", msqstat.msg_lrpid);
  printf("PID of last msgrcv: %d\n", msqstat.msg_lrpid);

  printf("%d - %s\n", data.data_num, data.data_buff);
		 }
  return(0);
    }
