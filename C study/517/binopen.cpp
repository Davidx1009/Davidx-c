#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

struct data
{
	char name[10];
	int age;
	
}student={"james",22};

int main(void)
{	
	int f1;
	
	f1=open("student.bin",O_CREAT|O_WRONLY|O_BINARY,S_IWRITE);
	if(f1!=-1)
	{
		write(f1,&student,sizeof(student));
		close(f1);
		printf("data write sucess.\n");
		
	}
	else
	printf("open file fail.\n");
	
	return 0;
	
}
