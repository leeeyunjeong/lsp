nclude <stdio.h>  
4  #include <stdlib.h> 
5  #include <assert.h> 
6  #include <pthread.h>  
7  #include <unistd.h> 
8  #define NUM_THREADS 5 
9  void *perform_work(void *arguments) {  
	10	  int index = *((int *)arguments); 
	11	    int sleep_time = 1 + rand() % NUM_THREADS; 
	12		 printf("THREAD %d: Started.\n", index);  
	13		  printf("THREAD %d: Will be sleeping for %d seconds.\n", index, sleep_time); 
	14		   sleep(sleep_time); 
	15		    printf("THREAD %d: Ended.\n", index); 
	16			 } 
	17  int main(void) {  
		18	  pthread_t threads[NUM_THREADS]; 
		19	   int thread_args[NUM_THREADS];  
		20	    int i;  
		21		 int result_code; 
		22		  // create all threads one by one  
			23		  for (i = 0; i < NUM_THREADS; i++) {  
				24			   printf("IN MAIN: Creating thread %d.\n", i);  
				25			    thread_args[i] = i;  
				26				 result_code = pthread_create(&threads[i], NULL, perform_work, &thread_args[i]);  
				27				  assert(!result_code);  
				28				   }    
		29		   printf("IN MAIN: All threads are created.\n"); 
		30		    // wait for each thread to complete  
			31		    for (i = 0; i < NUM_THREADS; i++) {  
				32				 result_code = pthread_join(threads[i], NULL);  
				33				  assert(!result_code);  
				34				   printf("IN MAIN: Thread %d has ended.\n", i);  
				35				    }    
		36			 printf("MAIN program has ended.\n");  
		37			  return 0;  } 

