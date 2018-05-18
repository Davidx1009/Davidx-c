#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(void)
{
	int f1;
	int arr[]={12,4,5,6};
	int a=8,b=7;

	
	f1=open("hw12_12.bin",O_CREAT|O_BINARY|O_RDWR,S_IWRITE);
	if(f1 != -1)
	{
		write(f1,&arr,sizeof(arr));
		write(f1,&a,sizeof(a));
		write(f1,&b,sizeof(b));
		
		close(f1);
		printf("file write over!\n");
	}
	else
		printf("open file fail!\n");
	
	return 0;
}
