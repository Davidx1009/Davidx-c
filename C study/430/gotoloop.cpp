#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int a=0,sum=0; 
	start:
		a++;
		sum+=a;
		printf("%d",a); 
		if(a < 10)
		{printf("+");
		 goto start;
		}
	
	printf("=%d\n",sum);
	
	system("pause");
	return 0;
	
}
