#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char title[7][20]={"�P���","���~A(12)","���~B(16)","���~C(10)","���~D(14)","���~E(15)","�~�Z"};
	int produce;
	int data[3][7]={{1,33,32,56,45,33,},{2,77,33,68,45,23,},{3,43,55,43,67,65,}};
	int price[5]={12,16,10,14,15};
	int sale[3][5];   /*�s��U�H�U���~���P���B*/ 
	int psale[3]={0,0,0};
	int saleman[3]={1,2,3};
	int ptotal[5]={0,0,0,0,0};
	int i,j,sum,p,p2,max,maxman;
	
	for(i=0;i<7;i++)
	printf("%s    ",title[i]);
	printf("\n");
	
	for(i=0;i<3;i++)
	{	sum=0;
		p=0;
		p2=0;
		printf("%d\t",data[i][0]);
		for(j=1;j<6;j++)     /*�L�X�Ӳ��~���P��q+��X�U���~���P���B+��X�U�P������~�Z*/ 
		{
			printf("%d\t       ",data[i][j]);
			psale[i]+=data[i][j]*price[p];
			sale[i][p2]=data[i][j]*price[p];
			p++;
			p2++;
		}	
		printf("%d    ",psale[i]);
		printf("\n");
	}	
	printf("���B   ");
	for(i=0;i<5;i++)
	{   sum=0;
		for(j=0;j<3;j++) /*��X�C�����~���P���`�B*/ 
		{	ptotal[i]+=sale[j][i];
		
		}
		printf("%d\t     ",ptotal[i]);	
	}
		printf("\n");
	
	printf("�̨ξP���:");
	for(i=0;i<2;i++)
	{
			if(psale[i]>psale[i+1])
		{
			max=psale[i];
			maxman=saleman[i];
		}
		else
		{
			max=psale[i+1];
			maxman=saleman[i+1];
		}

	}
		printf("%d, �P����B: %d\n",maxman,max);
	printf("�U���~�P���B:\n");
	for(i=0;i<3;i++)
	{
			for(j=0;j<5;j++)
			printf("%d  ",sale[i][j]);
	printf("\n");
	}	
	printf("�̨ξP�ⲣ�~:");
		for(i=0;i<4;i++)
	{
			if(ptotal[i]>ptotal[i+1])
		{
			max=ptotal[i];
			produce=i+1;
		}
		else
		{
			max=ptotal[i+1];
			produce=i+2;
		}
	}
		printf("%s, �P����B: %d\n",title[produce],max);
	return 0;
	
	
	
}
