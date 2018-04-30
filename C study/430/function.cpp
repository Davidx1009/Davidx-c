#include <stdlib.h>
#include <stdio.h>

int add(int,int);

int main(void)
{
	int a,b,sum;
	printf("please enter 2 number:");
	scanf("%d%d",&a,&b);
	sum = add(a,b);
	
	printf("%d+%d=%d",a,b,sum);
	
	return 0;
}

int add(int num1,int num2)
{
	return num1+num2;
	
}
