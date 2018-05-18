#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(void)
{
	int f1;
	int arr[4];
	int a,b,i;
	
	f1=open("hw12_12.bin",O_BINARY|O_RDWR,S_IWRITE);
	
	if(f1 != -1)
	{

		read(f1,&arr,sizeof(arr));
		read(f1,&a,sizeof(a));
		read(f1,&b,sizeof(b));
		
		printf("%d\n",a);
		printf("%d\n",b);
		for(i=0;i<4;i++)
		printf("arr[%d]=%d\n",i,arr[i]);
		
		close(f1);
	}
	else
		printf("open file fail!\n");
	
	return 0;
}
