#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

struct data
{
	char name[10];
	int age;
	
}student;

int main(void)
{
	int f2;
	
	f2=open("student.bin",O_RDONLY|O_BINARY,S_IREAD);
	if(f2 != -1)
	{
		read(f2,&student,sizeof(student));
		printf("name=%s\n",student.name);
		printf("age=%d\n",student.age);
		
		printf("read finish!\n");
		
		
		
		
	}
	else
	printf("open file fail!\n");
	
	return 0;
	
}
