#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	short sum , s = 32767 ; 
	long num = 10000L ;
	sum = s + 1;
	printf("sum= %d\n", sum);
	sum = s + 2;
	printf("sum= %d\n", sum);
	num = num +1 ;
	printf("num= %d\n", num);
	
	return 0;
 } 
