#include <stdio.h>
#include <stdlib.h>
#define MAX 2
int main(void)
{
	struct data
	{
		char name[10];
		int score;
	}student[MAX];
	int i;
	for(i=0;i<MAX;i++)
	{
	
	printf("please enter your name\n");
	scanf("%s",&student[i].name);
	printf("please enter your score\n");
	scanf("%d",&student[i].score);
	fflush(stdin);
	}

	for(i=0;i<MAX;i++)
	{
	printf("your name is %s\n",student[i].name);
	printf("your score is %d\n",student[i].score);
	}
	
	return 0;
}
