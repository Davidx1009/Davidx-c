#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(void)
{
	int f2,i,j,tmp,avg;
	int num[10];
	
	f2=open("rand.bin",O_RDONLY);
	
	if(f2 != NULL)
	{	
		while(!eof(f2))
		{
			read(f2,&num,sizeof(num));
		
		}
		close(f2);
	}
	else
	printf("open file fail.\n");
	
		for(i=1;i<10;i++)
			for(j=0;j<10-i;j++)
				if(num[j] < num [j+1])
				{	tmp = num[j+1];
					num[j+1]=num[j];
					num[j] = tmp;
				}
	
		for(i=0;i<10;i++)
		printf("num[%d]= %d\n",i,num[i]);
	
	
	return 0;
	
	
}
