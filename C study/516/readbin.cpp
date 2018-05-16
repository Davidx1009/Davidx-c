#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	double a;
	int b,c;
	
	FILE *fptr;
	
	fptr= fopen("number.bin","rb");
	if( fptr != NULL)
	{fread(&a,sizeof(double),1,fptr);
	fread(&b,sizeof(int),1,fptr);
	fread(&c,sizeof(int),1,fptr);
	printf("file read finish\n");
	
	printf("a=%4.2f,b=%d,c=%d",a,b,c);
	
	fclose(fptr);
	}
	else
		printf("file open fail\n");
	
	return 0;
	
}
