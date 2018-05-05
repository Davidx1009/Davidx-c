#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char title[7][20]={"銷售員","產品A(12)","產品B(16)","產品C(10)","產品D(14)","產品E(15)","業績"};
	int produce;
	int data[3][7]={{1,33,32,56,45,33,},{2,77,33,68,45,23,},{3,43,55,43,67,65,}};
	int price[5]={12,16,10,14,15};
	int sale[3][5];   /*存放各人各產品的銷售額*/ 
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
		for(j=1;j<6;j++)     /*印出個產品的銷售量+算出各產品的銷售額+算出各銷售員的業績*/ 
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
	printf("金額   ");
	for(i=0;i<5;i++)
	{   sum=0;
		for(j=0;j<3;j++) /*算出每項產品的銷售總額*/ 
		{	ptotal[i]+=sale[j][i];
		
		}
		printf("%d\t     ",ptotal[i]);	
	}
		printf("\n");
	
	printf("最佳銷售員:");
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
		printf("%d, 銷售金額: %d\n",maxman,max);
	printf("各產品銷售額:\n");
	for(i=0;i<3;i++)
	{
			for(j=0;j<5;j++)
			printf("%d  ",sale[i][j]);
	printf("\n");
	}	
	printf("最佳銷售產品:");
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
		printf("%s, 銷售金額: %d\n",title[produce],max);
	return 0;
	
	
	
}
