#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fptr;
	char str[80];
	int byte;
	
	fptr=fopen("outtest.txt","r");
	while(!feof(fptr))
	{
		byte = fread(str,sizeof(char),80,fptr);
		if(byte < 80)
			str[byte]='\0';
		printf("%s\n",str);
	
	}	
	fclose(fptr);
	system("pause");
	return 0;
	
	
}


