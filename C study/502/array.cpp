#include <stdio.h>
#include <stdio.h>

int main(void)
{
	int i,score[4];
	
	score[0]=44;
	score[1]=55;
	score[2]=66;
	score[3]=77;
	
	for(i=0;i<4;i++)
	printf("score[%d]=%d\n",i,score[i]);
	
	int score2[4]={43,23,57,75};
	for(i=0;i<4;i++)
	printf("score2[%d]=%d\n",i,score2[i]);
	
	return 0;
 } 
