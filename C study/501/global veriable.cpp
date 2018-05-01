#include <stdio.h>
#include <stdlib.h>

int a;
static int b=100;

void globala(void);
void staticb(void);
int main(void)
{
	a=50;
	printf("before globala a= %d\n",a);
	globala(); 
	printf("after globala, a= %d\n",a);
	
	
	printf("before staticb b= %d\n",b);
	staticb(); 
	printf("after staticb b= %d\n",b);
	staticb(); 
	return 0;
	
}

void globala()
{
	a=100;
	printf("in globala, a= %d\n",a);
	
}

void staticb()
{
	b+=100;
	printf("in staticb, b= %d\n",b);
	
}
