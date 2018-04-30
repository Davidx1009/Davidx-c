#include <stdlib.h>
#include <stdio.h>

int main(void) 
{
	int score;
	
	printf("please enter a score:\n");
    scanf("%d",&score);
	
	if(score >= 90)	
		printf("your score is %d, rank A",score);
		else if(score >= 60 && score < 90)
			printf("your score is %d, rank B",score);
				else
				printf("your score is %d, rank C",score);
	
	system("pause");
	return 0;
	
}
