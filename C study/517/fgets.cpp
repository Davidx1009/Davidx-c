#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fptr;
	char str[5];
	int i;
	
	fptr = fopen("welcome.txt","r");
	if( fptr != NULL)
	{
			while( feof(fptr) == 0)	
			{
			fgets(str,5,fptr);
			printf("%s",str);
			}			
		fclose(fptr);		
	}
	else
		printf("open file fail!\n");
	
	return 0;
}
