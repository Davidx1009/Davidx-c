#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int n1;
	char c1;
	
	printf("please enter a number:");
	scanf("%d",&n1);
	fflush(stdin); 
	
	printf("please enter a word:");
	scanf("%c",&c1);
	
	printf("number is %d, word is %c and it's ASCII is %d\n", n1,c1,c1);
	
	system("pause");
	return 0;
	
 } 
