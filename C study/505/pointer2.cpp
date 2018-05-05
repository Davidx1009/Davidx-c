#include <stdlib.h>
#include <stdio.h>
void pointer(int *);

int main(void)
{
	int *ptr; 
	int a=5;

	ptr=&a;
	pointer(ptr);
	pointer(&a);
	
	return 0;
}

void pointer(int *p1)
{   printf("%%p=%p\n",p1);
	printf("%%d=%d\n",*p1);
	
}
