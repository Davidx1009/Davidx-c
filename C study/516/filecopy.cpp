#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	FILE *fptr,*fptr2;
	char ch;
	int count=0;
	
	fptr=fopen("test.txt","r");
	fptr2=fopen("out.txt","w");
	
	if(fptr!=NULL && fptr2!= NULL)
	{
		while((ch=getc(fptr))!= EOF)
		{
			putc(ch,fptr2);
			count++;
			
		}
		fclose(fptr);
		fclose(fptr2);
		printf("\ntotal %d word in file.\n",count);
		
	}
	else
	printf("open file fail!\n");
	
	system("pause");
	return 0;
	
}
