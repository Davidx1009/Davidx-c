#include <stdio.h>
#include <stdlib.h>

int tentotwo(int);

int main(void)
{
	int a;
	printf("please enter a number:");
	scanf("%d",&a);
	tentotwo(a);
	
	system("pause");
	return 0;		
}

int tentotwo(int num)
{
	int i;
	while(num>0)
	{
	i=num%2;
    num=num/2;
    printf("%d",i);
    }
	
	
}
