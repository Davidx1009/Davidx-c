#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int y=1900,sum=0; 
	check:
		if(y%4==0 && y%100!=0)
		printf("%d是閏年\n",y);
			else if(y%4==0 && y%100==0)
				if(y%400==0)
				printf("%d是閏年\n",y);
	if(y< 2000)
	{y++;
	 goto check;	
	}
	
	system("pause");
	return 0;
	
}
