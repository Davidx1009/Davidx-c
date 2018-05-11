#include <stdio.h>
#include <stdlib.h>
	struct data
	{
		char name[10];
		int score;
	};

void swap(struct data *,struct data *);

int main(void)
{
	struct data s1={"mary",60};
	struct data s2={"dav",80};

	printf("before swap,s1=%s,%d\n",s1.name,s1.score);
	swap(&s1,&s2);
	printf("after swap,s1=%s,%d\n",s1.name,s1.score);

	return 0;
}

void swap(struct data *p1,struct data *p2)
{
	struct data tmp;
	tmp=*p1;
	*p1=*p2;
	*p2=tmp;
	
}
