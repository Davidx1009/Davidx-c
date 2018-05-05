#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *ptr; 
	int a=5;
	
	ptr=&a;
	
	printf("*ptr=%d,ptr=%d\n",*ptr,ptr);
	
	return 0;
	
	
}
