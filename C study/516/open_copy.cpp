#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#define MAX 512

int main(void)
{
	int f1,f2,bytes;
	char buffer[MAX];
	f1=open("outtest.txt",O_RDONLY|O_TEXT);
	f2=creat("outfile.txt",S_IWRITE);
	
	if(f1!=-1 && f2 != -1)
	{
		while(!eof(f1))
		{
			bytes = read(f1,buffer,MAX);
			write(f2,buffer,bytes);
						
		}
		
		close(f1);
		close(f2);
		printf("copy file finish!\n");
	}
	else
	printf("open file fail.");
	
	system("pause");
	return 0;
	
	
}
