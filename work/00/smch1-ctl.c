/* shm2-ctl.c */  
2  #include <stdio.h>  
3  #include <unistd.h>  
4  #include <sys/ipc.h>  
5  #include <sys/shm.h>  
6  #include <sys/types.h> 
7   #define  KEY_NUM     773500  
8   #define  MEM_SIZE    1024 
9   int main(void) {  
	10	  int    shm_id;  
	11	  void  *shm_addr;  
	12	  struct shmid_ds shm_info; 
	13	  if( -1 == (shm_id = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT|0666))) { 
		14		  printf( ".....gksrmf\n"); 
		15		  return -1;  
		16		  }   
	17	  else {  
		18		  printf( ".. ... .. ..\n"); 
		19		  }    
	20	  if((void *)-1 == (shm_addr = shmat(shm_id, (void *)0, 0))) { 
		21		  printf( ".. ... .. ..\n");  
		22		  return -1;  
		23		  }    
	24	  else {  
		25		  printf( ".. ... .. ..\n"); 
		26		  }  
	27	  if( -1 == shmctl(shm_id, IPC_STAT, &shm_info)) { 
		28		  printf( ".. ... .. .... .......\n");  
		29		  return -1; 
		30		  } 
	31	  printf( ".. .... .... ..... .. : %ld\n", shm_info.shm_nattch); 
	32	  if( -1 == shmdt(shm_addr)) { 
		33		  printf( ".. ... .. ..\n");  
		34		  return -1; 
		35		  }  
	36	  else {  
		37		  printf( ".. ... .. ..\n"); 
		38		  } 
	39	  if( -1 == shmctl(shm_id, IPC_RMID, 0)) {  
		40		  printf( ".. ... .. ..\n"); 
		41		  return -1;  
		42		  }  
	43	  else {  
		44		  printf( ".. ... .. ..\n"); 
		45		  } 
	46	  return 0;  
	47	  } 

