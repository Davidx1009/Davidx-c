#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char title[7][20]={"�P���","���~A(12)","���~B(16)","���~C(10)","���~D(14)","���~E(15)","�~�Z"};
	int data[3][7]={{1,33,32,56,45,33,},{2,77,33,68,45,23,},{3,43,55,43,67,65,}};
	int price[5]={12,16,10,14,15};
	int sale[3][5];
	int i,j,sum,p,p2;
	
	for(i=0;i<7;i++)
	printf("%s  ",title[i]);
	printf("\n");
	
	for(i=0;i<3;i++)
	{	sum=0;
		p=0;
		p2=0;
		printf("%d\t",data[i][0]);
		for(j=1;j<6;j++)
		{
			printf("%d\t    ",data[i][j]);
			sum+=data[i][j]*price[p];
			sale[i][p2]=data[i][j]*price[p];
			p++;
			p2++;
		}	
		printf("%d",sum);
		printf("\n");
	}	
	printf("�U�P����B");
	for(i=0;i<5;i++)
	{   sum=0;
		for(j=0;j<3;j++)
		{	sum+=sale[j][i];
		
		}
		printf("%d\t",sum);
	
	}
		printf("\n");
	
	
	return 0;
	
	
	
}
