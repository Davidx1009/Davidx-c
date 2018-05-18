#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>



int main(void)
{	int f1;
	srand(time(NULL));	
	int num[10],i;
	
	for(i=0;i<10;i++)
		num[i]=(rand()%16)+1;
	
	f1=open("rand.bin",O_RDWR|O_CREAT|O_BINARY,S_IWRITE);
	if(f1 != NULL)
	{	
		write(f1,&num,sizeof(num));
		
		close(f1);
		printf("file write finish.\n");
	}
	else
	printf("open file fail.\n");
	
	return 0;
	
	
}
