#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	FILE *f1;
	int arr[]={12,4,5,6};
	int c=8,d=7;

	
	f1=fopen("hw12_14.bin","wb");
	if(f1 != NULL)
	{
		fwrite(&arr,sizeof(int),4,f1);
		fwrite(&c,sizeof(int),1,f1);
		fwrite(&d,sizeof(int),1,f1);
			
		fclose(f1);
		printf("file write over!\n");
	}
	else
		printf("open file fail!\n");
	
	return 0;
}
