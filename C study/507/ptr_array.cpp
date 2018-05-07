#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int sum=0,i,a[3]={1,7,3};
	int *ptr;
	
	ptr=a;
	for(i=0;i<3;i++)
		sum+=*(ptr++);
	
	printf("sum=%d\n",sum);
	
	return 0;
}
