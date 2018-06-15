#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	
};
typedef struct node NODE;

int main(void)
{
	int i,num,data;
	NODE *first,*current,*previous;
	printf("number of nodes:");
	scanf("%d",&num);
	
	for(i=0;i<num;i++)
	{
		current =(NODE *) malloc(sizeof(NODE));
		printf("data for nodes %d:",i+1);
		scanf("%d",&(current->data));
		if(i==0)
			first=current;
		else
			previous->next=current;
		current->next = NULL;
		previous = current; 		
		
	}
	current=first;
	while(current != NULL)
	{
		printf("address=%p, ",current);
		printf("data=%d, ",current->data);
		printf("next=%p\n",current->next);
		current=current->next;
		
		
	}
	
	system("pause");
	return 0;
	
}
