#include <stdio.h>
#include <stdlib.h>
#define number 4
#define name 10

int main(void)
{
	char s[number][name]={"Mary","koko","david","john"};
	char s2[number][name];
	int i,j;
	for(i=0;i<number;i++)
		printf("S1=%s\n",s[i]);
	
	for(i=0;i<number;i++)
		for(j=0;j<name;j++)
			s2[i][j]=s[i][j];
			
	for(i=0;i<number;i++)
		printf("S2=%s\n",s2[i]);	
	
	
	return 0;
	
 } 
