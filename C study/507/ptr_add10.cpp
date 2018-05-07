#include <stdio.h>
#include <stdlib.h>

void add10(int *);

int main(void)
{
	int a=5;
	printf("before call add10, a =%d\n",a);
	add10(&a);
	printf("after call add10, a =%d\n",a);
	
	return 0;
}

void add10(int *p1)
{
	*p1=*p1 + 10;
	
}
