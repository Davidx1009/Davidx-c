#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void createdeck(struct data *);
void playcard(void);
void printdeck(void);
int changecard(int);
int compare(void);

/*enum deckrank
{
	onepair,
	twopairs,
	threeofakind,
	straight,
	flush,
	fullhouse,
	fourofakind,
	straightflush
	
}rank;*/

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
};
struct data maindeck[52];
struct data playerdeck[5];
struct data tmpdeck;

int main(void)
{	
	int i,j,quit=1;
	char option;
	srand(time(NULL));

	
	do
	{	
	system("CLS");
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

int i,j,a,count,numtmp,ftmp;

for(i=0;i<52;i++) /*分配數字*/
{
	start:
	do /*檢查是否超過4個同樣數字*/
	{	count =0;
		numtmp=rand()%13+1;
		j=0;
		for(a=0;a<i;a++)
			if(numtmp == (deckc+a)->num)
				count++;
			if(count >= 4)
				continue;
		j++;
	}while(j==0);
		(deckc+i)->num=numtmp;	
	do/*檢查是否超過13個同樣花色*/
	{	count =0;
		ftmp=rand()%4;
		j=0;
		for(a=0;a<i;a++)
			if(ftmp == (deckc+a)->num)
				count++;
			if(count >= 13)
				continue;
		j++;
	}while(j==0);
		
	switch(ftmp)
	{
	case 0:
	(deckc+i)->flower=clubs;
	break;
	case 1:
	(deckc+i)->flower=diamonds;
	break;
	case 2:
	(deckc+i)->flower=heart;
	break;
	case 3:
	(deckc+i)->flower=spades;
	break;	
	} 
	
	for(a=0;a<i;a++)   /*檢查有無重複, 有的話goto 到start 重作一張*/
		if((deckc+a)->num == (deckc+i)->num && (deckc+a)->flower == (deckc+i)->flower)
		{	
			goto start;
			
		}
}		

}

/*===============================================================*/

void playcard()
{	system("CLS");
	createdeck(&maindeck[0]);
	int i,j,card=51,quit=1,money=1000,bet,prize;
	int *pcard;
	char option;

	do
	{   	system("CLS");
			printf("PC: let's play !\n ");
			printf("how much money you want to bet?:");
			scanf("%d",&bet);
			fflush(stdin);
			money = money - bet;
			pcard = &card; 
			printf("distributing card!\n ");
			for(i=0;i<5;i++)
		{	
			playerdeck[i]=maindeck[card];
			card--;
		}        
			
			printdeck();
			puts("\n");		
			printf("your money: %d, you bet %d , deck: %d card left\n",money,bet,card+1);
			todo:
			printf("What you want to do?\n");
			printf("change card(c),no need change(n),quit(q)\n");
			scanf("%c",&option);
			fflush(stdin);
			
			if(option == 'c' || option == 'q' || option == 'n')
			switch(option)
			{
			/*===========================change card====================================*/	
			case 'c':			
			card -= changecard(card);
			case 'n':
			prize=compare();
			money = money + bet * prize;
			bet = 0;			
			printf("your money: %d, you bet %d , deck: %d card left\n",money,bet,card+1);			
			if(card < 10)
			{
				printf("do not have enough card,shuffle deck.\n");
				createdeck(&maindeck[0]);
				card = 51;
			}
					todo2:
					printf("What you want to do?\n");
					printf("play again(a),shuffle deck and play again(s),quit(q)\n");
					scanf("%c",&option);
					fflush(stdin);
					if(option == 'a' || option == 's' || option == 'q')
					{
						switch(option)
						{	case 'a':
							continue;
							case 's':
							createdeck(&maindeck[0]);
							card = 51;	
							continue;
							case 'q':
							quit=0;
						
						}
					}
					else
						{	printf("please enter a correct option!\n");
							goto todo2;
						}
			/*===========================quit====================================*/	
			case 'q':
			quit=0;
			}
			else 
			{	printf("please enter a correct option!\n");
				goto todo;
			}

	}while(quit);
	
	
}
/*=============print deck==============*/
void printdeck()
{	int i;
	

		printf("your deck is:\n");

			for(i=0;i<5;i++)
			{	printf("%d:",i+1);
			if(playerdeck[i].num >1 && playerdeck[i].num < 10)
		 		printf("| %d   ", playerdeck[i].num);
			else			
			switch(playerdeck[i].num)
				{
				case 1:
				printf("| A   ");	
				break;
				case 10:
				printf("| 10  ");	
				break;
				case 11:
				printf("| J   ");	
				break;
				case 12:
				printf("| Q   ");	
				break;
				case 13:
				printf("| K   ");	
				break;
				}
				switch(playerdeck[i].flower)
				{
				case 0:
				printf(" , Clubs    |\n");	
				break;
				case 1:
				printf(" , Diamonds |\n");	
				break;
				case 2:
				printf(" , Heart    |\n");	
				break;
				case 3:
				printf(" , Spades   |\n");
				break;
				}			
			}
	
}
/*=============change deck==============*/
int changecard(int ccard)
{	
	int changetmp[5],i,j;
	char cf;

	changecard:
	i=0; /*控制要換幾張*/
	do
	{
		printf("which card you want to change?(1-5,enter 0 to end):");	/*先選要換的卡*/
		scanf("%d",&changetmp[i]);
		fflush(stdin);
		if(changetmp[i] == 0 || i + 1 > 5)
			break;
		if(changetmp[i] < 0 || changetmp[i] > 5)
		{	printf("\n Please enter a correct number!\n");
			continue;	
		}
		for(j=0;j<i;j++)
		if(changetmp[i]==changetmp[j])
			printf("\n number %d already chose, please enter another number!\n",changetmp[i]);	
		i++;
	}while(1);

	printf("the card you want to change is:|");/*確認*/
	for(j=0;j<i;j++)
	printf("%d |",changetmp[j]);
	printf("\n");
	
	printf("confirm?(y/n)");
		confirm:
	scanf("%c",&cf);
	fflush(stdin);
	if(cf != 'y' && cf != 'n')
	{	printf("\n Please enter a correct answer!\n");
		goto confirm;
	}	
	if(cf == 'n')
		goto changecard;
	if(cf == 'y')
	{	for(j=0;j<i;j++)
		{
		playerdeck[(changetmp[j]-1)] = maindeck[ccard];	/*原本ccard是用指標型態. 不過換超過3張卡會遇到Segment fault, google後 發現應該是指標分配到記憶體保護空間,所以把ccard 改成整數*/ 
		ccard--;

		}
		
	}
	printf("After change:");
	printdeck();/*換完後 把新的deck印出來,再把換了幾張卡傳回去*/

	return i;
	
}
/*=============compare ==============*/
int compare(void)
{	int i,j,rank=0,pair=0;
	int onepair=0,twopairs=0,threek=0,flush=0,straight=0,fullh=0,fourk=0,flushs=0;
	for(i=0;i<5;i++)
	{	for(j=0;j<5;j++)
		if(playerdeck[i].num < playerdeck[j].num)
		{
			tmpdeck=playerdeck[i];
			playerdeck[i] = playerdeck[j];
			playerdeck[j] = tmpdeck;
		}
	}
	
	/*======pairs====== 已經先排序了,所以同數字會在下一個*/ 
	i=0;
	while(i<5)
	{
			if(playerdeck[i].num == playerdeck[i+1].num)
			{
					pair++;		
					i++;
					continue;		
			}
		
			if(pair == 1 && onepair == 0)
			{ 	onepair=1;
			  	pair=0;			 }
			if(pair == 1 && onepair == 1)
			{ 	twopairs=1;
			  	pair=0;			 }
			if(pair == 2 && onepair == 0)
			{ 	threek=1;
			  	pair=0;			 }
			if(pair == 2 && onepair == 1)
			{ 	fullh=1;
			  	pair=0;			 }
			if(pair == 3)
			{ 	fourk=1;
			  	pair=0;			 }

		i++;	
	}
	/*======stright====== 已經先排序了,所以檢查下一個數字是不是少一*/ 		

	j=0;
	for(i=0;i<5;i++)
		if(playerdeck[i].num == (playerdeck[i+1].num-1))
				j++;
		if(j==4)
		straight = 1;

	j=0;
	if(playerdeck[0].num == 1 && playerdeck[1].num == 10  ) /*10 J Q K A 特殊規則*/ 
		for(i=1;i<5;i++)
			if((playerdeck[i].num) == (playerdeck[i+1].num-1))
				j++;
			if(j==3)
			straight = 1;
		
	/*======flush====== 單純對花色都一樣就好*/ 

	j=0;
	for(i=0;i<5;i++)
		if(playerdeck[0].flower == playerdeck[i].flower)
				j++;
		if(j==5)
		flush = 1;

	/*======flush straight====== */ 
	if(straight == 1 && flush == 1)
		flushs=1;
	
	if(	flushs==1)	
	{	printf("You got a Flush Straight!");
			rank=250;}		
	else if(fourk==1)	
	{	printf("You got a Four of kind!");
			rank=100;}
	else if(fullh==1)	
	{	printf("You got a Full House!");
			rank=50;}
	else if(flush==1)	
	{	printf("You got a Flush!");
			rank=10;}	
	else if(straight == 1)	
	{	printf("You got a Straight!");
			rank=5;}
	else if(threek==1)	
	{	printf("You got a Three of a kind!");
			rank=3;}		
	else if(twopairs==1)	
	{	printf("You got a Two Pairs!");
			rank=2;}		
	else if(onepair==1)	
	{	printf("You got a One Pair!");
			rank=0;}
	else
	{	printf("You got Nothing!");
			rank=0;}
	printf("\n");

	return rank;
	
}


