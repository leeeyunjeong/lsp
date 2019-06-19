#include<stdio.h>
#include<signal.h>

int main(void)
{
	sigset_t set;

  sigfillset(&set);

//	sigemptyset(&set);
//	sigaddset(&set, SIGINT);
  // sigaddset(&set, SIGSYS);


	switch(sigismember(&set, SIGINT)) {
		case 1 : printf("SIGINT는 포함되어 있습니다.\n");
				 break;
	    case 0 : printf("SIGINT는 없습니다.\n");
				 break;
		default : printf("sigismember() 호출에 실패했습니다.\n");

	}
	
    switch(sigismember(&set, SIGTERM)) {
	  case 1 : printf("SIGTERM는 포함되어 있습니다.\n");
                break;
	  case 0 : printf("SIGTERM는 없습니다.\n");
	             break;
	  default : printf("sigismember() 호출에 실패했습니다.\n");
	}
 
	 //sigdelset(&set, SIGINT);
   
  //  switch(sigismember(&set, SIGINT)) {
	//   case 1 : printf("SIGINT는 포함되어 있습니다.\n");
	  //        break;
       //case 0 : printf("SIGINT는 없습니다.\n");
         //    break;
	   //default : printf("sigismember() 호출에 실패했습니다.\n");
//	}


	return 0;
}
