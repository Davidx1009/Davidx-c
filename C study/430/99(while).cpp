#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a=1,b=1;
    
    while(a<10)
    {
    	while(b<10)
    	{
    		printf("%d*%d=%d |",a,b,a*b);
    	    b++;	
    	}
    	a++;
    	b=1;
    	printf("\n");
	}
return 0;
	
}
