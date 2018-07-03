#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void colorit(void);
void uncolorit(void);
int startup(void);
int systeminfo(void);
int setup(void);

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //為GetConsoleScreenBufferInfo取得一個有GENERIC_READ access的參數 
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD current_screencolor;
int kin[2]={27,27},tmp,menuchoice = 1;

int main() 
{
	 /* 保存目前的顏色狀態*/
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
//=============調系統顏色=================//
void colorit()
{ 		
    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE|FOREGROUND_INTENSITY); //改變系統顏色// 
	
}

//=============把系統顏色調回去=================//
void uncolorit()
{	
	SetConsoleTextAttribute(hConsole, current_screencolor);	
}

//==================start up menu ====================//
int startup()
{	
	while(1)
	{
	
	tmp = kin[1];//暫存狀態 kin預設是27在 esc //
    printf("Start Up Menu\n");
    printf("______________________________________________________________\n");
    printf("\t\t");
	if(kin[1]==59) //根據kin[1]的值來看要在選擇那個option並上色 //
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
    /*抓取按鍵的keyin值來進行menu 操作*/
    kin[0] =	getch();
    if(kin[0]== 224 || kin[0]== 0) //因為某些鍵會輸出2組key code ex:F1,2,3,4....up,left.... 所以設2個暫存給 keyin   //
    kin[1] =	getch();           //kin[0]主要用來判斷是不是上面提到的特殊key, kin[1] 用來存真正需要的值 //
    else
    kin[1] = kin[0];
        
    if(kin[1]==72)//在strat up menu 讓 上下鍵可以動作 //
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
	
	    if(kin[1]==13) //enter 鍵 選擇option 
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
	
	
	if(kin[1] == 59 || kin[1] == 60 || kin[1] == 61 || kin[1] == 27 || kin[1] == 72 || kin[1] == 80 ) //如果是有function的key才寫入tmp   //
		tmp= kin[1];
		else
		kin[1]=tmp;    //不是有function的key 把tmp 寫回去 kin[1] 讓option不要動 //
	
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
	
	tmp = kin[1];//暫存狀態 kin預設是27在 esc //
    printf("System Info\n");
    printf("______________________________________________________________\n");
    printf("\t\t");
	if(kin[1]==59) //根據kin[1]的值來看要在選擇那個option並上色 //
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
    /*抓取按鍵的keyin值來進行menu 操作*/
    kin[0] =	getch();
    if(kin[0]== 224 || kin[0]== 0) //因為某些鍵會輸出2組key code ex:F1,2,3,4....up,left.... 所以設2個暫存給 keyin   //
    kin[1] =	getch();           //kin[0]主要用來判斷是不是上面提到的特殊key, kin[1] 用來存真正需要的值 //
    else
    kin[1] = kin[0];
        
    if(kin[1]==75)//在menu 讓 左右鍵可以動作 //
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
	
	    if(kin[1]==13) //enter 鍵 選擇option 
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
	
	if(kin[1] == 59 || kin[1] == 27 || kin[1] == 75 || kin[1] == 77 ) //如果是有function的key才寫入tmp ,enter 不寫, 因為option位置不用移動  //
		tmp= kin[1];
		else
		kin[1]=tmp;    //不是有function的key 把tmp 寫回去 kin[1] 讓option不要動 //
	
	system("CLS"); 

	}
}
//==================setup menu ====================//
int setup()
{   
	int setupinfo=3,optionchoice=0,maxoption=0,minoption=1,option;
	
	while(1)
	{
	
	tmp = kin[1];//暫存狀態 kin預設是27在 esc //
    printf("Setup Menu\n");
    printf("______________________________________________________________\n");
    printf("|");
	if(kin[1]==59) //根據kin[1]的值來看要在選擇那個option並上色 //
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
    	option=3;	//設定這個分頁有多少選項 
		if(optionchoice==0)
		{	minoption=1;  //選項頂端的flag, 按上會跳到選項尾端 
		colorit();
		}
    	printf("whatever, just dummy1\n");
	    uncolorit();
    	if(optionchoice==1)
		colorit();
    	printf("whatever, just dummy2\n");
    	uncolorit();
    	if(optionchoice==2)
    	{	maxoption=1; //選項尾端的flag, 按下會跳到選項頂端
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
    /*抓取按鍵的keyin值來進行menu 操作*/
    kin[0] =	getch();
    if(kin[0]== 224 || kin[0]== 0) //因為某些鍵會輸出2組key code ex:F1,2,3,4....up,left.... 所以設2個暫存給 keyin   //
    kin[1] =	getch();           //kin[0]主要用來判斷是不是上面提到的特殊key, kin[1] 用來存真正需要的值 //
    else
    kin[1] = kin[0];
  
    if(kin[1]==75)
    {	optionchoice=0; //設定在換頁後option會回到第一項 
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
		optionchoice = option - 1; //如果選項在頂端,按上可以跳到最尾端. 然後把flag 歸0.  
		minoption=0;
		}
		else
		optionchoice--;		
		
		
	}
	if(kin[1]==80)
	{
		if(maxoption ==1)
		{
		optionchoice = 0; //如果選項在尾端,按下可以跳到最頂端. 然後把flag 歸0.  
		maxoption=0;
		}
		else
		optionchoice++;	
		
	}
	
	if(kin[1]==59) {setupinfo=0;optionchoice=0;} //設定F1,2,3 鍵的顯示 
	if(kin[1]==60) {setupinfo=1;optionchoice=0;}
	if(kin[1]==61) {setupinfo=2;optionchoice=0;}
	if(kin[1]==27) {setupinfo=3;optionchoice=0;}
	
	
	 if(kin[1]==13) //enter 鍵 目前只有exit 作動. 可以根據需要自己加function 
    {
		if(setupinfo == 3) //先判斷是在哪一個分頁 
			{
				if(optionchoice==0) //再判斷要執行的function 
				{
				return 1;
				break;
				}
			}
	}
	if(kin[1] == 59 || kin[1] == 60 || kin[1] == 61 || kin[1] == 27 || kin[1] == 75 || kin[1] == 77 ) //如果是有function的key才寫入tmp   //
		tmp= kin[1];
		else
		kin[1]=tmp;    //不是有function的key 把tmp 寫回去 kin[1] 讓option不要動 //
	
	system("CLS"); 

	}
}





