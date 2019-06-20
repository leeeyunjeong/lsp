/* shm1-writer.c */ 
2  #include <stdio.h>  
3  #include <unistd.h>  
4  #include <sys/ipc.h>  
5  #include <sys/shm.h> 
6  #define  KEY_NUM     7735  
7  #define  MEM_SIZE    1024 
8  int main(void) { 
	9	   int   shm_id;  
	10	    void *shm_addr;  
	11		 int   count = 0; 
	12		  if(-1 == (shm_id = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT | 0666))) {  
		13			   perror("shmget() error");  
		14			    return -1;  }    
	15		   if((void *)-1 == (shm_addr = shmat(shm_id, (void *)0, 0))) {  
		16			   perror("shmat() error");  
		17			   return -1;  }  
	18		   while(1) {  
		19			    // write in the shared memory  
			20			    sprintf((char *)shm_addr, "%d", count++); 
		21				sleep(1);  }  
	22		      return 0; } 

