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
/*Ū��config ��*/
	config=fopen("config.txt","rb");
		while((ch=getc(config)) != EOF)
	{	
		count++; /*���o�һݪŶ�*/
	}
	fclose(config);
	config=fopen("config.txt","rb");
	char dp[count];
	while(!feof(config))
	{
	fread(dp,sizeof(char),count,config);
	}
	fclose(config);
		/*��l�ݭn�ۤv��J���*/
	if(argv[1] == NULL)
	{
	printf("how many driver you would like to install?");
	scanf("%d",&df);
	}
	else
	{
		df =atoi(argv[1]);
	}
	
/*��IUT tool�w�˸��|��X�ө�*/
		j=13;
		while(dp[j] != '\"')
		{
		command[dc][i]= dp[j]; 
		j++;
		i++;
		
		}
		command[dc][i] = '\0'; /*�b�r�굲���[�W�Ŧr��(\0)�T�O���|Ū��ýX,(���[�e�|Ū��)*/
		dc++;
		j+=15;
/*��driver �w�˸��|��X�Ӥ��}��*/
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
/*��uninstall driver ��������O��X�Ӥ��}��*/
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
 /*===========Driver ���ݾ���==============*/
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

 /*===========check �ninstall�٬O uninstall==============*/
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
  /*===========�s�@flag �_�I==============*/
 void installflag()
 {
 	creat("INSTALL.FLG",S_IWRITE);
 }
  void uninstallflag()
 {
 	creat("UNINSTALL.FLG",S_IWRITE);
 }
 
/*===========startup �j��ǳ� �bstartup folder ���Xbat�����t�Υi�H�brestart��۰ʰ���IUT.exe==============*/
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
 
 
 
 
 
 
 
