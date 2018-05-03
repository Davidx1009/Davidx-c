#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a,i,s[5],temp;

	for(i=0;i<5;i++)
	{
	printf("please enter score %d:",i+1);
	scanf("%d",&s[i]);
	printf("\n");
	}
	for(a=0;a<5;a++)
	{
		for(i=0;i<5;i++)
		{
			if(s[i]>s[i+1])
			{	
			temp=s[i]; 
			s[i]=s[i+1];
			s[i+1]=temp;
			}
		}
	}
	
	for(i=0;i<5;i++)
	printf("s[%d]=%d\n",i,s[i]);
	
	
	system("pause");
	return 0;
	
	
}
