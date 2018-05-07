#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	const char *ptr="We are best firends.";
	int i=0,j=0;
	const char *p;
	while(1)
	{	
		p=ptr+i;
		if(p != "\0")
		{	if(*p >= 97 && *p <= 122)
			j++;
					
			i++;
		}
		else
		break;
	}
	
	
	printf("ptr have %d word.",i-1);
	printf("and there have %d ¤p¼g.",j);
	
	return 0;
	
}
