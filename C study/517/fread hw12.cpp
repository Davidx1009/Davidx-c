#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	FILE *f1;
	int arr[4];
	int c,d,i;
	
	f1=fopen("hw12_14.bin","rb");
	
	if(f1 != NULL)
	{

		fread(&arr,sizeof(int),4,f1);	
		fread(&c,sizeof(int),1,f1);

		fread(&d,sizeof(int),1,f1);

		printf("%d\n",c);
		printf("%d\n",d);
		for(i=0;i<4;i++)
		printf("arr[%d]=%d\n",i,arr[i]);
		
		fclose(f1);
	}
	else
		printf("open file fail!\n");
	
	return 0;
}
