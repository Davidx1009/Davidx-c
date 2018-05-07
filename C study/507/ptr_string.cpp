#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	const char *ptr = "hello,how are you."; 
	char name[20];
	
	printf("please enter your name,");
	gets(name);
	printf("your name, is %s.\n",name);
	puts(ptr);


	return 0;	
}
