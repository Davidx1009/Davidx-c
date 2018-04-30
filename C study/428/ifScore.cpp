#include <stdlib.h>
#include <stdio.h>

int main(void)
{
int g1;

printf("please enter your score:"); 
scanf("%d",&g1);
if(g1 < 0 || g1 > 100)
printf("error score.\n"); 
else	
	if(g1<60)
	printf("you need retest.\n"); 
	else
	printf("you pass test.\n"); 

return 0;

}
