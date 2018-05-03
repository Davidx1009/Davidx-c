#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
void show(int arr[]);
void add2(int arr[]);

int main(void)
{
	int a,b[SIZE]={5,3,7,9};
	
	printf("before call add2\n");
	show(b);	
	add2(b);
	printf("after call add2\n");
	show(b);
	
	return 0;
}

void show(int arr[])
{   int i;
	for(i=0;i<SIZE;i++)
		printf("b[%d]=%d\n",i,arr[i]);
	
}

void add2(int arr[])
{
	int i;
	for(i=0;i<SIZE;i++)
		arr[i]+=2;
}



