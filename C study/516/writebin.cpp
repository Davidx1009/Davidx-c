#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	double a=3.14;
	int b=4,c=9;
	
	FILE *fptr;
	
	fptr= fopen("number.bin","wb");

	fwrite(&a,sizeof(double),1,fptr);
	fwrite(&b,sizeof(int),1,fptr);
	fwrite(&c,sizeof(int),1,fptr);
	printf("file write finish");
	fclose(fptr);

	
	return 0;
	
}
