#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	struct data
	{
		char name[10];
		int score;
	};
	struct data student={"mary",90};

	printf("name is %s\n",student.name);
	printf("score is %d\n",student.score);
	
	return 0;
}
