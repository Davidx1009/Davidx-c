#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a,b;

	for(a=1;a<10;a++)
	{
		for(b=1;b<10;b++)	
			printf("%d*%d=%d |",a,b,a*b);
		printf("\n");
	}
	
	return 0;
	
}
