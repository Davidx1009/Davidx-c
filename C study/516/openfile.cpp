#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	FILE *fptr;
	char ch;
	int count=0;
	
	fptr=fopen("test.txt","r");
	if(fptr!=NULL)
	{
		while((ch=getc(fptr))!= EOF)
		{
			printf("%c",ch);
			count++;
			
		}
		fclose(fptr);
		
		printf("\ntotal %d word in file.\n",count);
		
	}
	else
	printf("open file fail!\n");
	
	system("pause");
	return 0;
	
}
