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

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //��GetConsoleScreenBufferInfo���o�@�Ӧ�GENERIC_READ access���Ѽ� 
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD current_screencolor;
int kin[2];

int main()
{	int num,i=0,enterflag=0,changeline=0,ecount=1,line=1,tmpflag=0;
	NODE *first,*current,*previous,*uplayer,*tmp,*move,*movetmp;
	/* �O�s�ثe���C�⪬�A*/
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    current_screencolor = consoleInfo.wAttributes;
	
	current = NULL;
	
	do
	{	system("CLS");
		if(i !=0)
		current = first;		// �p�Gi���O0���mcurrent����m�M����Ӥ�󭫷s�L�X�� 
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
		
	kin[0] =	getch();
    if(kin[0]== 224 || kin[0]== 0) //�]���Y����|��X2��key code ex:F1,2,3,4....up,left.... �ҥH�]2�ӼȦs�� keyin   //
    kin[1] =	getch();           //kin[0]�D�n�ΨӧP�_�O���O�W�����쪺�S��key, kin[1] �ΨӦs�u���ݭn���� //
    else
    kin[1] = kin[0];
	
	
		if(kin[1] == 72) //up
		{
				if(tmpflag==0)
				{
					movetmp=previous;
					tmpflag=1;
				}
				move = movetmp->up;
				movetmp=movetmp->up;
			
		}
		else if(kin[1] == 75) //left
		{		if(tmpflag==0)
				{
					movetmp=previous;
					tmpflag=1;
				}
				move = movetmp->left;
				movetmp=movetmp->left;
		}
		else if(kin[1] == 77) //right
		{
				if(tmpflag==0)
				{
					movetmp=previous;
					tmpflag=1;
				}
				move = movetmp->right;
				movetmp=movetmp->right;
		}
		else if(kin[1] == 80) //down
		{
				if(tmpflag==0)
				{
					movetmp=previous;
					tmpflag=1;
				}
				move = movetmp->down;
				movetmp=movetmp->down;
		}
		else
		current->worddata=kin[1]; //���o����code 
		
		
		if(current->worddata== 13) //enter�� ���� 
		{	
		
		current->left = previous; 
		if(enterflag==0)
			uplayer = traceback(current, i);
		else
			uplayer = traceback(current, ecount);
		
		current->worddata='\n'; 
		enterflag =1; //enter flag ��1�e���O�Ĥ@�檺��� 
		changeline=1;
		
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
			if(kin[1] != 72 && kin[1] != 75 && kin[1] != 77 && kin[1] != 80 ) 
			move = current;
			i++;
	    }
		else //���Lenter �� enterflag=1 
		{		
		   if(changeline==1 && line == 1)
			{
			previous->right = current;
			previous->left =tmp; 
			previous->up = NULL;
			previous->down = NULL;
			}
			else
			{ 
			previous->right = current;
			previous->left =tmp; 
			previous->up = uplayer;
			previous->down = NULL;
			uplayer->down =previous;
			}
				
			current->right = NULL;	
			current->down = NULL;
			current->up = uplayer;
			current->left = previous;
			tmp=previous;
			
			previous = current;
			uplayer =uplayer->right;
			if(changeline==1)
				{
				changeline=0;
				line++;
				}
			ecount++;
			if(kin[1] != 72 && kin[1] != 75 && kin[1] != 77 && kin[1] != 80 ) 
			move = current;
		}
	}
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

	printf("\nup\n");
	uplayer = traceback(current, i);
		printf("adress= %p, " ,uplayer);
		printf("data= %c,", uplayer->worddata);
		printf("left= %p\n, " ,uplayer->left);
		printf("right= %p\n, " ,uplayer->right);
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

void colorit()
{ 		
    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE|FOREGROUND_INTENSITY); //���ܨt���C��// 
	
}

//=============��t���C��զ^�h=================//
void uncolorit()
{	
	SetConsoleTextAttribute(hConsole, current_screencolor);	
}

