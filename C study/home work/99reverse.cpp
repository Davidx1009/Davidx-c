#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,itmp;
	char ctmp[2];
	
	for(i=1;i<10;i++)
	{
		for(j=1;j<10;j++)
		{	itmp = i * j;
			sprintf(ctmp, "%d", itmp);
			printf("%d*%d=%s |" ,i,j,ctmp);
		
		}
		printf("\n");
		
	}
	
	printf("reverse\n\n");
	
		for(i=1;i<10;i++)
	{
		for(j=1;j<10;j++)
		{	itmp = i * j;
			sprintf(ctmp, "%d", itmp);
			if(ctmp[1] != NULL)
			printf("%c",ctmp[1]);
			
			printf("%c=%d*%d|",ctmp[0],j,i);
		}
		printf("\n");
		
	}
	
	
	return 0;
	
	
}
