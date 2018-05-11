#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void createdeck(struct data *);
void playcard(void);

enum deckflower
{
	clubs,
	diamonds,
	heart,
	spades
}flower;
struct data 
{
	int num;
	enum deckflower flower;	
	int mark;
};
struct data maindeck[52];
struct data playerdeck[5];


int main(void)
{	
	int i,j,quit=1;
	char option;
	srand(time(NULL));

	
	do
	{	
	printf("Welcome! What you want to do?\n");
	printf("play card(p),quit(q)\n");
	scanf("%c",&option);
	fflush(stdin);
		switch(option)
		{
		case 'p':
		playcard();	
		continue;	
		case 'q':
		quit=0;
		}	
		
	}while(quit);
	return 0;
	
} 

/*===============================================================*/
void createdeck(struct data *deckc)
{

int i,j,a,count,tmp;
for(i=0;i<52;i++) /*分配數字*/
{

	do /*檢查是否超過4個同樣數字*/
	{	count =0;
		tmp=rand()%13+1;
		j=0;
		for(a=0;a<i;a++)
			if(tmp == (deckc+a)->num)
				count++;
			if(count >= 4)
				continue;
		j++;
	}while(j==0);
		(deckc+i)->num=tmp;
}

for(i=0;i<52;i++)/*分配花色*/
{
	
	do/*檢查是否超過13個同樣花色*/
	{	count =0;
		tmp=rand()%4;
		j=0;
		for(a=0;a<i;a++)
			if(tmp == (deckc+a)->num)
				count++;
			if(count >= 13)
				continue;
		j++;
	}while(j==0);
		
	switch(tmp)
	{
	case 0:
	(deckc+i)->flower=clubs;
	(deckc+i)->mark= 5;
	break;
	case 1:
	(deckc+i)->flower=diamonds;
	(deckc+i)->mark= 4;
	break;
	case 2:
	(deckc+i)->flower=heart;
	(deckc+i)->mark= 3;
	break;
	case 3:
	(deckc+i)->flower=spades;
	(deckc+i)->mark= 6;
	break;	
	} 
}
}

/*===============================================================*/

void playcard()
{	system("CLS");
	printf("PC: let's play !\n ");

	createdeck(&maindeck[0]);
	int i,j,card=51,quit=1,money=1000,bet;
	char option;
	printf("how much money you want to bet?:");
	scanf("%d",&bet);
	fflush(stdin);
	money = money - bet;
	do
	{	printf("distributing card!\n ");
		printf("your deck is:");
		for(i=0;i<5;i++)
		{
			playerdeck[i]=maindeck[card];
			card--;
		}
			for(i=0;i<5;i++)
			{
			printf("| %d , %c |",playerdeck[i].num,playerdeck[i].mark);
			}
			puts("\n");
			printf("your money: %d, you bet %d\n",money,bet);
			printf("What you want to do?\n");
			printf("change card(p),quit(q)\n");
			scanf("%c",&option);
			fflush(stdin);
			switch(option)
			{
			case 'p':
			
			continue;	
			case 'q':
			quit=0;
			}
		
		
		
		
		
	}while(quit);
	
	
}






