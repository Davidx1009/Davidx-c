#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct word
{
	char worddata;
	struct word *right;
	struct word *left;
	struct word *up;
	struct word *down;
};
typedef struct word NODE;

NODE *traceback(NODE *, int );
void colorit(void);
void uncolorit(void);
NODE *tracen(NODE *);
void normalmove(void);

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //��GetConsoleScreenBufferInfo���o�@�Ӧ�GENERIC_READ access���Ѽ� 
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD current_screencolor;
int kin[2];

int num,i=0,enterflag=0,changeline=0,ecount=0,line=1,tmpflag=0,firstword =0,wordtmp=0,nflag=0;
NODE *first,*current,*previous,*uplayer,*tmp,*move,*movetmp,*ntmp;

int main()
{
	/* �O�s�ثe���C�⪬�A*/
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    current_screencolor = consoleInfo.wAttributes;
	
	current = NULL;
	
	do
	{	start:
		system("CLS");
		if(i !=0)
		current = first;		// �p�Gi���O0,���mcurrent����m�M����Ӥ�󭫷s�L�X�� 
		if(i==0)
		move = current;
	 
		while(current !=NULL)		
		{
		//printf("adress= %p, " ,current);
		if(current == move)
		colorit();
		printf("%c", current->worddata);

		uncolorit();
		//printf("next= %p, " ,current->right);
		//printf("before= %p\n, " ,current->left);
		current = current->right;
		}	
		 
			current =(NODE *)malloc(sizeof(NODE)); 
			
		normalmove();
	
	}while(current->worddata != 27);
		current->worddata ='\0';
		current = previous; 
	
/*	while(current !=NULL)
	{	
		printf("adress= %p, " ,current);
		printf("data= %c,", current->worddata);
		printf("before= %p\n, " ,current->left);
		
	
		current = current->left;
		
	}
*/	

	system("pause");
	return 0;
	
}
/*����ɬ��F��uplayer �g��Ӧ檺�Ĥ@��*/
NODE * traceback(NODE *trace, int a)
{	int j;
	NODE *tracetmp;
	//printf("%d\n",a);	
	
	for(j=0;j<a;j++)
	{/*	printf("===before==\n");
		printf("adress= %p, " ,trace);
		printf("data= %c,", trace->worddata);
		printf("next= %p\n, " ,trace->left);
	*/	
		tracetmp = trace->left;
		trace = tracetmp;
		/*	printf("===after==\n");
			printf("adress= %p, " ,trace);
			printf("data= %c,", trace->worddata);
			printf("adress= %p\n, " ,trace);
		*/	
	}

	return trace;
	
}
/*��W�@�Ӵ���r��\n
NODE * tracen(NODE *trace)
{	int j;
	NODE *tracetmp;
	while(trace->worddata != '\n')
	{
		tracetmp = trace->left;
		trace = tracetmp;
	
	}
	
	return trace->left;
}
*/
void colorit()
{ 		
    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE|FOREGROUND_INTENSITY); //���ܨt���C��// 
	
}

//=============��t���C��զ^�h=================//
void uncolorit()
{	
	SetConsoleTextAttribute(hConsole, current_screencolor);	
}

void normalmove()
{
	re:
	kin[0] =	getch();
    if(kin[0]== 224 || kin[0]== 0) //�]���Y����|��X2��key code ex:F1,2,3,4....up,left.... �ҥH�]2�ӼȦs�� keyin   //
    kin[1] =	getch();           //kin[0]�D�n�ΨӧP�_�O���O�W�����쪺�S��key, kin[1] �ΨӦs�u���ݭn���� //
    else
    kin[1] = kin[0];
	
	
		if(kin[1] == 72) //up
		{		if(i == 0 )
				goto re;
				if(tmpflag==0)
				{
					movetmp=previous;
					tmpflag=1;		
				}
			
				if(movetmp->up != NULL)
				{
				move = movetmp->up;
				movetmp=movetmp->up;
				}
				else
				{
					move = movetmp;
				}
			//	printf("%p",move->up);
				//	system("pause");
		}
		else if(kin[1] == 75) //left
		{		if(i == 0 )
				goto re;		
				if(tmpflag==0)
				{
					movetmp=previous;
					tmpflag=1;
				}
				if(movetmp->left != NULL)
				{
				move = movetmp->left;
				movetmp=movetmp->left;
				}
				else
				{
					move = movetmp;
				}
		}
		else if(kin[1] == 77) //right
		{		if(i == 0 )
				goto re;
				if(tmpflag==0)
				{
					movetmp=previous;
					tmpflag=1;
				}
				if(movetmp->right != NULL)
				{
				move = movetmp->right;
				movetmp=movetmp->right;
				}
				else
				{
					move = movetmp;
				}
		}
		else if(kin[1] == 80) //down
		{		if(i == 0 )
				goto re;
				if(tmpflag==0)
				{
					movetmp=previous;
					tmpflag=1;
				}
				if(movetmp->down != NULL)
				{
				move = movetmp->down;
				movetmp=movetmp->down;
				}
				else
				{
					move = movetmp;
				}
		}
		else
		current->worddata=kin[1]; //���o����code 
	
		
		if(current->worddata== 13) //enter�� ���� 
		{	
			if(i==0)
			{	first= current;
				uplayer = first;
				current->left = first;
				previous=first;
				
			}
			else
			{
				
			ecount= i-wordtmp;
			current->left = previous; 
			if(enterflag==0)
			uplayer = traceback(current, i);
			else
			uplayer = traceback(current, ecount-1);
			wordtmp=i;
			//printf("%d ",i);
			//printf("%d",wordtmp);
			}
		current->worddata='\n'; 
		
		enterflag =1; //enter flag ��1�e���O�Ĥ@�檺��� 
		changeline=1;
		firstword =0;
		nflag=0;
		}
	
	if(kin[1] != 72 && kin[1] != 75 && kin[1] != 77 && kin[1] != 80 ) 
	{
			if(enterflag ==0)
		{
			if(i==0) // i=0 �Nfirst �]��current . �]���O�Ĥ@��, �����W��,�U�賣�ONULL. 
				{
				first = current;
				first->left = NULL;	
				first->up = NULL;	
				first->down = NULL;
				}
			else if(i==1)
				{
				previous->right = current;
				previous->up = NULL;
				previous->down = NULL;
				}
			else	
				{
				previous->right = current;
				previous->left =tmp; // ��2�Ӧr�����tmp�����г]��left 
				previous->up = NULL;
				previous->down = NULL;
				}
			current->right = NULL;	
			current->down = NULL;
			current->up = NULL;
			
			if(i!=0)
			current->left = previous;	//i����0�����A�Ucurrent ������N�Oprevious 
			if(i==1)
			tmp=first; 
			if(i>1)
			tmp=previous;
			
			previous = current;
			if(kin[1] != 72 && kin[1] != 75 && kin[1] != 77 && kin[1] != 80 && tmpflag != 1 ) 
			move = current;
			i++;
	    }
		else //���Lenter �� enterflag=1 
		{	
		   if(changeline==1 && line == 1)
			{
				if(i==0)
				previous =current;
				else
				previous->right = current;
			
			previous->left =tmp;
			
			previous->up = NULL;
			previous->down = NULL;
			changeline = 2;
			firstword =1;
			
			}
			else if(changeline==2 && line == 1 && firstword ==1)
			{ 	
			previous->right = current;
			previous->left =tmp->left; 
			previous->up = NULL;
			previous->down = NULL;
				changeline=0;
				firstword =0;
			}
		   else if(changeline==1 && line > 1)
			{
			previous->right = current;
			
			previous->left =tmp;	
			previous->down = NULL;
			changeline = 2;
			firstword =1;
			
			}
			else if(changeline==2 && line > 1 && firstword ==1)
			{ 	
			previous->right = current;
			previous->left =tmp->left; 

			previous->down = NULL;
				changeline=0;
				firstword =0;
			}
			else 
			{ 
			//printf("data= %c,", uplayer->worddata);
			previous->right = current;
			previous->left =tmp; 
			//previous->up = uplayer;
			previous->down = NULL;
			//uplayer->down =previous;
			}
				
			current->right = NULL;	
			current->down = NULL;
			current->up = uplayer;
					 
			uplayer->down = current;
					 
			current->left = previous;
		
			tmp=previous;

			previous = current;

			if(uplayer->worddata == '\n')
			{
			ntmp= tmp->up;
			nflag=1;
			
			}
			if(nflag==1)
			current->up = ntmp;
		//	printf("%c",ntmp->worddata);
			if(firstword != 1)
			uplayer =uplayer->right;
			if(changeline==2)
				{
			//	changeline=0;
				line++;
				}
			i++;
			//ecount++;
			if(kin[1] != 72 && kin[1] != 75 && kin[1] != 77 && kin[1] != 80 && tmpflag != 1 ) 
			move = current;
			
		
		}
	}
	
}


