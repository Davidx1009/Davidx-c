#include <stdio.h>
#include <stdlib.h>
void add10(int *,int *);

int main(void)
{
	int a=3,b=5;
	
	printf("a=%d,b=%d\n",a,b);
	add10(&a,&b);
	
	printf("after call add10\na=%d,b=%d\n",a,b);
	
	return 0;
}

void add10(int *a1,int *b1)
{
	*a1=*a1 +10;
	*b1=*b1 +10;
}
