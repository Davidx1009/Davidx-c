#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void colorit(void);
void uncolorit(void);
int startup(void);
int systeminfo(void);
int setup(void);

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //��GetConsoleScreenBufferInfo���o�@�Ӧ�GENERIC_READ access���Ѽ� 
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD current_screencolor;
int kin[2]={27,27},tmp,menuchoice = 1;

int main() 
{
	 /* �O�s�ثe���C�⪬�A*/
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    current_screencolor = consoleInfo.wAttributes;

	while(menuchoice != 0)
	{	
		switch(menuchoice)
		{	
			case 1:
			menuchoice = startup();
			break;
			case 2:
			menuchoice = systeminfo();
			break;			
			case 3:
			menuchoice = setup();
			break;
			case 4:
			menuchoice = startup();
			break;
			case 0:
			break;
		}
		kin[1]=27;
		system("CLS");
	}
uncolorit();
printf("END\n");

    return 0;
}
//=============�ըt���C��=================//
void colorit()
{ 		
    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE|FOREGROUND_INTENSITY); //���ܨt���C��// 
	
}

//=============��t���C��զ^�h=================//
void uncolorit()
{	
	SetConsoleTextAttribute(hConsole, current_screencolor);	
}

//==================start up menu ====================//
int startup()
{	
	while(1)
	{
	
	tmp = kin[1];//�Ȧs���A kin�w�]�O27�b esc //
    printf("Start Up Menu\n");
    printf("______________________________________________________________\n");
    printf("\t\t");
	if(kin[1]==59) //�ھ�kin[1]���ȨӬݭn�b��ܨ���option�äW�� //
    colorit();
    printf("System Information(F1)\n\n");
    uncolorit();
    printf("\t\t");
    if(kin[1]==60)
    colorit();
    printf("Setup(F2)\n\n");
    uncolorit();
    printf("\t\t");
    if(kin[1]==61)
    colorit();
    printf("dummy option, no function(F3)\n\n");
    uncolorit();
    printf("\t\t");
    if(kin[1]==27)
    colorit();
    printf("EXIT(ESC)\n\n");
    uncolorit();
    /*������䪺keyin�ȨӶi��menu �ާ@*/
    kin[0] =	getch();
    if(kin[0]== 224 || kin[0]== 0) //�]���Y����|��X2��key code ex:F1,2,3,4....up,left.... �ҥH�]2�ӼȦs�� keyin   //
    kin[1] =	getch();           //kin[0]�D�n�ΨӧP�_�O���O�W�����쪺�S��key, kin[1] �ΨӦs�u���ݭn���� //
    else
    kin[1] = kin[0];
        
    if(kin[1]==72)//�bstrat up menu �� �W�U��i�H�ʧ@ //
    {
			if(tmp == 27)
    		kin[1]= 61; 
    	if(tmp == 61)
    		kin[1]= 60; 
    	if(tmp == 60)
    		kin[1]= 59;     	
     	if(tmp == 59)
    		kin[1]= 27;    
	}
    if(kin[1]==80)
    {
		if(tmp == 27)
    		kin[1]= 59; 
    	if(tmp == 59)
    		kin[1]= 60; 
    	if(tmp == 60)
    		kin[1]= 61;     	
     	if(tmp == 61)
    		kin[1]= 27;    
	}
	
	    if(kin[1]==13) //enter �� ���option 
    {
		if(tmp == 27)
    	{
    		return 0;
    		break;
		}
    	if(tmp == 59)
    	{
    		return 2;
    		break;
		}
    	if(tmp == 60)
    	{
    		return 3;
    		break;
		}	
     	if(tmp == 61)
    	{
    		return 4;
    		break;
		}
	}
	
	
	if(kin[1] == 59 || kin[1] == 60 || kin[1] == 61 || kin[1] == 27 || kin[1] == 72 || kin[1] == 80 ) //�p�G�O��function��key�~�g�Jtmp   //
		tmp= kin[1];
		else
		kin[1]=tmp;    //���O��function��key ��tmp �g�^�h kin[1] ��option���n�� //
	
	//printf("%d\n",kin[1]);
	//system("pause");
	
	system("CLS"); 

	}
}

//==================system info menu ====================//
int systeminfo()
{   int advinfo=0;
	while(1)
	{
	
	tmp = kin[1];//�Ȧs���A kin�w�]�O27�b esc //
    printf("System Info\n");
    printf("______________________________________________________________\n");
    printf("\t\t");
	if(kin[1]==59) //�ھ�kin[1]���ȨӬݭn�b��ܨ���option�äW�� //
    colorit();
    if(advinfo==1)
    printf("Detail information(F1)");
    else
    printf("Basic information(F1)");
    uncolorit();
    printf("\t\t");
    if(kin[1]==27)
    colorit();
    printf("EXIT(ESC)\n");
    uncolorit();
    printf("==============================================================\n");
    if(advinfo==0)
    {
    	printf("just demo, need press enter in option to change this page\n");
	}
	else
	{	
		printf("just demo,show advance information in here\n");
		printf(" press enter in option again to change back to basic page\n");
	}
    /*������䪺keyin�ȨӶi��menu �ާ@*/
    kin[0] =	getch();
    if(kin[0]== 224 || kin[0]== 0) //�]���Y����|��X2��key code ex:F1,2,3,4....up,left.... �ҥH�]2�ӼȦs�� keyin   //
    kin[1] =	getch();           //kin[0]�D�n�ΨӧP�_�O���O�W�����쪺�S��key, kin[1] �ΨӦs�u���ݭn���� //
    else
    kin[1] = kin[0];
        
    if(kin[1]==75)//�bmenu �� ���k��i�H�ʧ@ //
    {
		if(tmp == 27)
    		kin[1]= 59; 	
     	if(tmp == 59)
    		kin[1]= 27;    
	}
    if(kin[1]==77)
    {
		if(tmp == 27)
    		kin[1]= 59; 
     	if(tmp == 59)
    		kin[1]= 27;    
	}
	
	    if(kin[1]==13) //enter �� ���option 
    {
		if(tmp == 27)
    	{
    		return 1;
    		break;
		}
    	if(tmp == 59)
    	{
    		if(advinfo==1)
 		    	advinfo = 0;
 		    else
 		    	advinfo = 1;
		}

	}
	
	if(kin[1] == 59 || kin[1] == 27 || kin[1] == 75 || kin[1] == 77 ) //�p�G�O��function��key�~�g�Jtmp ,enter ���g, �]��option��m���β���  //
		tmp= kin[1];
		else
		kin[1]=tmp;    //���O��function��key ��tmp �g�^�h kin[1] ��option���n�� //
	
	system("CLS"); 

	}
}
//==================setup menu ====================//
int setup()
{   
	int setupinfo=3,optionchoice=0,maxoption=0,minoption=1,option;
	
	while(1)
	{
	
	tmp = kin[1];//�Ȧs���A kin�w�]�O27�b esc //
    printf("Setup Menu\n");
    printf("______________________________________________________________\n");
    printf("|");
	if(kin[1]==59) //�ھ�kin[1]���ȨӬݭn�b��ܨ���option�äW�� //
    colorit();
    printf("System setup(F1)");
    uncolorit();
	printf("|");
    if(kin[1]==60)
    colorit();
    printf("Device setup(F2)");
    uncolorit();
	printf("|");
    if(kin[1]==61)
    colorit();
    printf("Advance setup(F3)");
    uncolorit();
    printf("|");
    if(kin[1]==27)
    colorit();
    printf("EXIT(ESC)\n");
    uncolorit();
    printf("==============================================================\n");
    if(setupinfo==0)
    {
    	printf("demo page of System setup(F1) ,no need to press enter to change page\n");
    	option=3;	//�]�w�o�Ӥ������h�ֿﶵ 
		if(optionchoice==0)
		{	minoption=1;  //�ﶵ���ݪ�flag, ���W�|����ﶵ���� 
		colorit();
		}
    	printf("whatever, just dummy1\n");
	    uncolorit();
    	if(optionchoice==1)
		colorit();
    	printf("whatever, just dummy2\n");
    	uncolorit();
    	if(optionchoice==2)
    	{	maxoption=1; //�ﶵ���ݪ�flag, ���U�|����ﶵ����
		colorit();
		}
    	printf("whatever, just dummy3\n");
    	uncolorit();  
	}
	else if(setupinfo==1)
	{	
		printf("demo page of Device setup(F2) ,no need to press enter to change page\n");
		option=5;	
		if(optionchoice==0)
		{	minoption=1;
		colorit();
		}
    	printf("whatever, just dummy1\n");
	    uncolorit();
    	if(optionchoice==1)
		colorit();
    	printf("whatever, just dummy2\n");
    	uncolorit();
    	if(optionchoice==2)
		colorit();
    	printf("whatever, just dummy3\n");
    	uncolorit();
    	if(optionchoice==3)
		colorit();
    	printf("whatever, just dummy4\n");
    	uncolorit();
    	if(optionchoice==4)
    	{	maxoption=1;
		colorit();
		}
    	printf("whatever, just dummy5\n");
    	uncolorit();  
	}
	else if(setupinfo==2)
	{	
		printf("demo page of Advance setup(F3) ,no need to press enter to change page\n");
		option=4;	
		if(optionchoice==0)
		{	minoption=1;
		colorit();
		}
    	printf("whatever, just dummy1\n");
	    uncolorit();
    	if(optionchoice==1)
		colorit();
    	printf("whatever, just dummy2\n");
    	uncolorit();
    	if(optionchoice==2)
		colorit();
    	printf("whatever, just dummy3\n");
    	uncolorit();
    	if(optionchoice==3)
    	{	maxoption=1;
		colorit();
		}
    	printf("whatever, just dummy4\n");
    	uncolorit();   			
	}
	else if(setupinfo==3)
	{option=2;	
	if(optionchoice==0)
	{	minoption=1;
	colorit();
	}
    printf("EXIT\n");
    uncolorit();
    if(optionchoice==1)
    {	maxoption=1;
	colorit();
	}
    printf("whatever, just dummy\n");
    uncolorit();

	}
    /*������䪺keyin�ȨӶi��menu �ާ@*/
    kin[0] =	getch();
    if(kin[0]== 224 || kin[0]== 0) //�]���Y����|��X2��key code ex:F1,2,3,4....up,left.... �ҥH�]2�ӼȦs�� keyin   //
    kin[1] =	getch();           //kin[0]�D�n�ΨӧP�_�O���O�W�����쪺�S��key, kin[1] �ΨӦs�u���ݭn���� //
    else
    kin[1] = kin[0];
  
    if(kin[1]==75)
    {	optionchoice=0; //�]�w�b������option�|�^��Ĥ@�� 
		if(tmp == 27)
    	{
			kin[1]= 61; 
			setupinfo=2;
		}
    	if(tmp == 61)
    	{
			kin[1]= 60; 
			setupinfo=1;
		}
    	if(tmp == 60)
    	{
			kin[1]= 59; 
			setupinfo=0;
		}
     	if(tmp == 59)
    	{
			kin[1]= 27; 
			setupinfo=3;
		}
	}
    if(kin[1]==77)
    {	optionchoice=0;
		if(tmp == 27)
    	{
			kin[1]= 59; 
			setupinfo=0;
		}
    	if(tmp == 59)
    	{
			kin[1]= 60; 
			setupinfo=1;
		}
    	if(tmp == 60)
    	{
			kin[1]= 61; 
			setupinfo=2;
		}
     	if(tmp == 61)
    	{
			kin[1]= 27; 
			setupinfo=3;
		}
	}
	if(kin[1]==72)
	{
		if(minoption==1)
		{
		optionchoice = option - 1; //�p�G�ﶵ�b����,���W�i�H����̧���. �M���flag �k0.  
		minoption=0;
		}
		else
		optionchoice--;		
		
		
	}
	if(kin[1]==80)
	{
		if(maxoption ==1)
		{
		optionchoice = 0; //�p�G�ﶵ�b����,���U�i�H����̳���. �M���flag �k0.  
		maxoption=0;
		}
		else
		optionchoice++;	
		
	}
	
	if(kin[1]==59) {setupinfo=0;optionchoice=0;} //�]�wF1,2,3 �䪺��� 
	if(kin[1]==60) {setupinfo=1;optionchoice=0;}
	if(kin[1]==61) {setupinfo=2;optionchoice=0;}
	if(kin[1]==27) {setupinfo=3;optionchoice=0;}
	
	
	 if(kin[1]==13) //enter �� �ثe�u��exit �@��. �i�H�ھڻݭn�ۤv�[function 
    {
		if(setupinfo == 3) //���P�_�O�b���@�Ӥ��� 
			{
				if(optionchoice==0) //�A�P�_�n���檺function 
				{
				return 1;
				break;
				}
			}
	}
	if(kin[1] == 59 || kin[1] == 60 || kin[1] == 61 || kin[1] == 27 || kin[1] == 75 || kin[1] == 77 ) //�p�G�O��function��key�~�g�Jtmp   //
		tmp= kin[1];
		else
		kin[1]=tmp;    //���O��function��key ��tmp �g�^�h kin[1] ��option���n�� //
	
	system("CLS"); 

	}
}





