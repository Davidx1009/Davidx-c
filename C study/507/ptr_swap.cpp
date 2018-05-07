#include <stdio.h>
#include <stdlib.h>

void swap(int *,int *);

int main(void)
{
	int a=5,b=33;
	printf("before call swap(),A=%d,B=%d\n",a,b);
	swap(&a,&b);
	printf("after call swap(),A=%d,B=%d\n",a,b);
	
	return 0;
}

void swap(int *p1,int *p2)
{
	int tmp; 
	
	tmp=*p1;
	*p1=*p2;
	*p2=tmp;
	
}
