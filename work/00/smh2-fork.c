/* shm2-fork.c */  
2  #include <stdio.h>  
3 #include <unistd.h>  
4 #include <sys/ipc.h>  
5 #include <sys/shm.h> 
6 #define  KEY_NUM     77350000  
7 #define  MEM_SIZE    1024 
8  int main(void) {  
	9  int   shm_id;  
	10  void *shm_addr;  
	11  int  *cal_num;  
	12  int   pid; 
	13  if(-1 == (shm_id = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT | 0666))) {  
		14	 perror("shmget() error");  
		15	 return -1;  
		16  }    
	17	 if((void *)-1 == (shm_addr = shmat(shm_id, (void *)0, 0))) {  
		18		 perror("shmat() error");  
		19		 return -1;  
		20	 }    
	21	  cal_num = (int *)shm_addr; 
	22	  pid = fork(); 
	23	  if (pid == 0) { 
		24		  // write into the shared memory  
			25		  *cal_num = 1; 
		26		  while(1) {  
			27			   // write into the shared memory  
				28			  *cal_num = *cal_num + 1;  
			29			  printf("child: %d\n", *cal_num);  
			30			  sleep(1);  
			31		  }  
		32	  } 
	33  else if(pid > 0) { 
		34	 while(1) {  
			35		 sleep(1);  
			36		 // print out data read from the shared memory  
				37		  printf("parent: %d\n", *cal_num);  } }  } 

