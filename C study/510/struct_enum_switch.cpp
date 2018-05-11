#include <stdio.h>
#include <stdlib.h>
	enum color
	{
		red=114,
		green=103,
		blue=98,
	};
	
int main(void)
{	char e;
	
	do
	{
	printf("please enter a color:(r,g,b)");
	scanf("%c",&e);
	fflush(stdin);
	}while(e != red && e!= green && e != blue);
	
	switch(e)
	{
		case red:
		printf("you chose red\n");
		break;
		case green:
		printf("you chose green\n");
		break;
		case blue:
		printf("you chose blue\n");
		break;
		
	}
	return 0;
}
