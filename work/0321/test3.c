#include<stdio.h>

	int plus(int x, int y,int z){
		return x+y+z;
	}
	int minus(int x, int y, int z){
		return x-y-z;
	}

	int	multiply(int x, int y, int z){
			return x*y*z;
	}

	int	divide(int x, int y, int z){
		return x/y/z;
	}

	int main()
    {
	  int x, y, z;
	  char a;
	  printf("사칙연산을 입력\n");
      scanf("%d%c%d%c%d",&x,&a,&y,&a,&z);

      printf("%d%c%d%d%d=", x, a, y,z);
     
	  if(a== '+')
		  printf("%d",plus(x,y,z));

      if(a== '-')
	  printf("%d",minus(x,y,z));

	  if(a== '*')
	  printf("%d",multiply(x,y,z));

	  if(a== '/')
	  printf("%d",divide(x,y,z));


	return 0;
}

