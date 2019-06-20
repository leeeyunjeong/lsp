
 Open this file in GitHub Desktop 
   Edit this file 
    
     Delete this file 
	  

	 1  /* shm1-reader.c */ 
	 2  #include <stdio.h>  
	 3  #include <unistd.h>  
	 4 #include <sys/ipc.h> 
	 5  #include <sys/shm.h> 
	 6  #define  KEY_NUM     7735  
	 7  #define  MEM_SIZE    1024 
	 8  int main(void) {  
		 9	  int   shm_id;  
		 10		   void *shm_addr; 
		 11		    if(-1 == (shm_id = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT | 0666))) {  
			 12				 perror("shmget() error");  
			 13				 return -1;  } 
		 14			 if((void *)-1 == (shm_addr = shmat(shm_id, (void *)0, 0))) {  
			 15				  perror("shmat() error");  
			 16				   return -1;  } 
		 17			 while(1) { 20. // print out the data read from the shared memory 21. printf("%s\n", (char *)shm_addr); 
			 18				  sleep(1);  }  
		 19			 return 0;  } 

