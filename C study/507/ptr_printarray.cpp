#include <stdio.h>
#include <stdlib.h>

int main(void)
{	int num[3][4]={{23,45,77,1},
					{44,78,99,83},
					{10,55,34,21}};
	int i,j;
	
	for(i=0;i<3;i++)
	{	
		for(j=0;j<4;j++)
		printf("%d,",*(*(num+i)+j));
		printf("\n");	
	}
	/*大於40轉換成40*/
		for(i=0;i<3;i++)
	{	
		for(j=0;j<4;j++)
		{
		if(*(*(num+i)+j)>= 40)
		*(*(num+i)+j)= 40;	
		}
		
	}
	
		for(i=0;i<3;i++)
	{	
		for(j=0;j<4;j++)
		printf("%d,",*(*(num+i)+j));
		printf("\n");	
	}
	
	return 0;
}
	
