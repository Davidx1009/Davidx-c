#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>


int flagcheck_driverinstall(void);
int flagcheck_setup(void);
void installflag(void);
void uninstallflag(void);
int startup(char *,int);

int main(int argc, char *argv[])
{
	FILE *config,*result;
	int i=0,dc=0,j=0,count=0,df,cy;
	char command[50][300],ch,folder[300],nu;
	 /*==============================讀取result 開始==============================*/	
	result=fopen("result.txt","r");
	if(result == NULL)
	result=fopen("result.txt","wt");
	char cycle[6];

	fread(cycle,sizeof(char),6,result);
	fclose(result);

		cy =atoi(cycle);
system("CLS");
		switch(flagcheck_setup())
{
	case 3:
		printf("current cycle : 1 initializing Install\n");
		cy++;
		result=fopen("result.txt","wt");
		fprintf(result,"%d",cy);
		fclose(result);
		break;
	/*安裝流程*/	
	case 1:	
	cy++;
	printf("current cycle : %d Installing driver\n",cy);
	result=fopen("result.txt","wt");
	fprintf(result,"%d",cy);
	fclose(result);
	break;
	/*反安裝流程*/
	case 2:
	printf("current cycle : %d Uninstalling driver\n",cy);
}
	count =0;
                                   /*==============================讀取config 開始==============================*/	
	config=fopen("config.txt","rb");
		while((ch=getc(config)) != EOF)
	{	
		count++; /*取得所需空間*/
	}
	fclose(config);
	config=fopen("config.txt","rb");
	char dp[count];
	while(!feof(config))
	{
	fread(dp,sizeof(char),count,config);
	}
	fclose(config);
	
		/*初始需要自己輸入初值*/
	if(argv[1] == NULL)
	{
	printf("how many driver you would like to install?");
	scanf("%d",&df);
	}
	else
	{
		df =atoi(argv[1]);
	}
	
/*把IUT tool安裝路徑抓出來放*/
		j=13;
		while(dp[j] != '\"')
		{
				if(dp[j]== ' ')/*資料夾有空格的對策*/
				{
					command[dc][i]='\"';
					command[dc][i+1]= dp[j];
					command[dc][i+2]='\"';
					i+=2;
				}
				else
		command[dc][i]= dp[j]; 
		j++;
		i++;
		
		}
		command[dc][i] = '\0'; /*在字串結尾加上空字符(\0)確保不會讀到亂碼,(未加前會讀到)*/
		dc++;
		j+=15;
/*把install driver 的執行指令抓出來分開放*/
	while(dc<(df*2+1))
	{ 	i=0;
	
		/*抓取執行指令的路徑*/
			while(dp[j] != '\"')
			{
				if(dp[j]== ' ')
				{
					command[dc][i]='\"';
					command[dc][i+1]= dp[j];
					command[dc][i+2]='\"';
					i+=2;
				}
				else
				command[dc][i]= dp[j]; 
			j++;
			i++;
		
			}
			command[dc][i] = '\0'; 
		
		j+=15;
		dc++;
		/*抓取執行指令*/
		i=0;
		while(dp[j] != '\"')
			{	/*拿掉空格對策避免引值誤加*/
			command[dc][i]= dp[j]; 
			j++;
			i++;
		
			}
			command[dc][i] = '\0'; 

		j+=15;
		dc++;
			
	}
/*把uninstall driver 的執行指令抓出來分開放*/
	j+=2;
	while(dc<((df*4)+1))
	{ 	i=0;

		/*抓取執行指令的路徑*/
			while(dp[j] != '\"')
			{
				if(dp[j]== ' ')
				{
					command[dc][i]='\"';
					command[dc][i+1]= dp[j];
					command[dc][i+2]='\"';
					i+=2;
				}
				else
				command[dc][i]= dp[j]; 
			j++;
			i++;
		
			}
			command[dc][i] = '\0'; 

		j+=15;
		dc++;
		/*抓取執行指令*/
		i=0;
		while(dp[j] != '\"')
			{	/*拿掉空格對策避免引值誤加*/
			command[dc][i]= dp[j]; 
			j++;
			i++;
		
			}
			command[dc][i] = '\0'; 

		j+=17;
		dc++;		
	}
/* 抓取的數目跟路徑
 
	for(i=0;i<dc;i++)
	{	printf("%d\n",i);
		printf("%s\n",command[i]);
	}*/
                                              /*==============================讀取config 結束==============================*/	
	
	
	switch(flagcheck_setup())
{
	
	case 3:

	startup(command[0],df);
	system("pause");
	
	/*安裝流程*/
	case 1:
	printf("============================install process starting.============================\n");
	Sleep(5000);
	for(i=1;i<(dc/2)+1;i++)
	{
	printf("%s%s\n",command[i],command[i+1]);
	sprintf(folder, "%s%s", command[i],command[i+1]);
	system(folder);
	i++;
	flagcheck_driverinstall();
	}	
	printf("install process finish.\ngoing to do restart.\n");
	Sleep(1000);
	sprintf(folder, "cd %s", command[0]);
	system("erase /f /q INSTALL.FLG");
	system(folder);
	uninstallflag();
	for(i=0;i<10;i++)
	{
		printf("%d...\n",i);
		Sleep(1000);
	}
	system("shutdown /r");
	break;
	/*反安裝流程*/
	case 2:
	printf("============================uninstall process starting.============================\n");
	Sleep(5000);
	for(i=(1+dc/2);i<dc+1;i++)
	{
	printf("%s%s\n",command[i],command[i+1]);
	sprintf(folder, "%s%s", command[i],command[i+1]);
	system(folder);
	i++;
	flagcheck_driverinstall();
	}		
	printf("uninstall process finish.\ngoing to do restart.\n");
	Sleep(1000);
	sprintf(folder, "cd %s", command[0]);
	system(folder);
	system("erase /f /q UNINSTALL.FLG");
	installflag();
	for(i=0;i<10;i++)
	{
		printf("%d...\n",i);
		Sleep(1000);
	}
	system("shutdown /r");
}
	return 0;
	
 } 
 /*===========Driver 等待機制==============*/
 int flagcheck_driverinstall()
 {	
	system("EXIT /B \%ERRORLEVEL\%");
 }

 /*===========check 要install還是 uninstall==============*/
 int flagcheck_setup()
 {	
 	FILE *flag;
 	flag=fopen("INSTALL.FLG","rb");
 	if(flag != NULL)
 	{fclose(flag);
	return 1;	
	}	
	flag=fopen("UNINSTALL.FLG","rb");
 	if(flag != NULL)
 	{fclose(flag);
	return 2;	
	}
	fclose(flag);
	return 3;
 }
  /*===========製作flag 斷點==============*/
 void installflag()
 {	
 	int flag1;
 	flag1=creat("INSTALL.FLG",S_IWRITE);
 	close(flag1);
 }
  void uninstallflag()
 {	int flag2;
 	flag2=creat("UNINSTALL.FLG",S_IWRITE);
 	close(flag2);
 }
 
/*===========startup 迴圈準備 在startup folder 做出bat檔讓系統可以在restart後自動執行IUT.exe==============*/
int startup(char *start,int a)
{	
FILE *f1;
char b[10],e;
int i=strlen(start);
f1=fopen("IUT.bat","wt");
fprintf(f1,"cd %s",start);
fprintf(f1,"\nIUTV1.exe %d",a);
fclose(f1);

system("xcopy IUT.bat \"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\" /y");

}
 
 
 
 
 
 
 
