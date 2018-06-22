#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#define STARTUPFOLDER C:\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp

int flagcheck_driverinstall(void);
int flagcheck_setup(void);
void installflag(void);
void uninstallflag(void);
int startup(char *,int);



int main(int argc, char *argv[])
{
	FILE *config;
	int i=0,dc=0,j=0,dflag=0,count=0,df;
	char command[30][300],ch;
	installflag();
/*讀取config 檔*/
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
		command[dc][i]= dp[j]; 
		j++;
		i++;
		
		}
		command[dc][i] = '\0'; /*在字串結尾加上空字符(\0)確保不會讀到亂碼,(未加前會讀到)*/
		dc++;
		j+=15;
/*把driver 安裝路徑抓出來分開放*/
	while(dc<(df+1))
	{ 	i=0;
		printf("%d",dc);
			while(dp[j] != '\"')
			{
			command[dc][i]= dp[j]; 
			j++;
			i++;
		
			}
			command[dc][i] = '\0'; 
			printf("%c",dp[j]);
		j+=15;
		dc++;
			
	}
/*把uninstall driver 的執行指令抓出來分開放*/
	j+=2;
	while(dc<((df*2)+1))
	{ 	i=0;
		printf("%d",dc);
			while(dp[j] != '\"')
			{
			command[dc][i]= dp[j]; 
			j++;
			i++;
		
			}
			command[dc][i] = '\0'; 
			printf("%c",dp[j]);
		j+=17;
		dc++;
			
	}
		printf("%d\n",dc);
		for(i=0;i<dc;i++)
	{	printf("%d\n",i);
	printf("%s\n",command[i]);

	}
	startup(command[0],df);
		system("pause");
	
	for(i=0;i<dc;i++)
	{
	printf("%s\n",command[i]);
	system(command[i]);
	flagcheck_driverinstall();
	}	
	
	system("pause");
	return 0;
	
 } 
 /*===========Driver 等待機制==============*/
 int flagcheck_driverinstall()
 {	
 	FILE *flag;
 	flag=fopen("FAILURE.FLG","rb");
 	while(flag != NULL)
 	{
	flag=fopen("FAILURE.FLG","rb");
	Sleep(2000); 	
	}	
 }

 /*===========check 要install還是 uninstall==============*/
 int flagcheck_setup()
 {	
 	FILE *flag;
 	flag=fopen("INSTALL.FLG","rb");
 	if(flag != NULL)
 	{
	return 1;	
	}	
	flag=fopen("UNINSTALL.FLG","rb");
 	if(flag != NULL)
 	{
	return 2;	
	}
 }
  /*===========製作flag 斷點==============*/
 void installflag()
 {
 	creat("INSTALL.FLG",S_IWRITE);
 }
  void uninstallflag()
 {
 	creat("UNINSTALL.FLG",S_IWRITE);
 }
 
/*===========startup 迴圈準備 在startup folder 做出bat檔讓系統可以在restart後自動執行IUT.exe==============*/
int startup(char *start,int a)
{	
char f1,f2,b[10];
int i=strlen(start),e;
sprintf(b, "%d", a);
f1=creat("IUT.bat",S_IWRITE);
write(f1,start,i);
write(f1,&e,1);
write(f1,&b,1);
close(f1);

system("xcopy IUT.bat \"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\" /y");

}
 
 
 
 
 
 
 
