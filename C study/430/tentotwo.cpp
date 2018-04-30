#include <stdio.h>
#include <stdlib.h>

void tentotwo(int);

int main(void)
{
	int a;
	printf("please enter a number:");
	scanf("%d",&a);
	tentotwo(a);
	
	system("pause");
	return 0;		
}

void tentotwo(int num)
{
	
	int i[10],x=0;
	while(num>0)
	{
	i[x]=num%2;
    num=num/2;
    printf("%d\n",num);
    x++;
    }
    printf("%d\n",x);
    while(x>0)
	{	x--;	
	printf("%d",i[x]);
	
    }
}
