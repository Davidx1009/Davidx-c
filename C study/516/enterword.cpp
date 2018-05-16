#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 80
#define ENTER 13

int main(void)
{
	FILE *fptr;
	char ch,str[MAX];
	int i;
	
	fptr=fopen("outtest.txt","a");
	while((ch=getche()) != ENTER && i< MAX)
	str[i++]=ch;
	
	putc('\n',fptr);
	fwrite(str,sizeof(char),i,fptr);
	fclose(fptr);
	printf("\n enter word complete!\n");
	
	system("pause");
	return 0;
	
	
}
