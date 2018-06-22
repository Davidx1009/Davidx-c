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
	 /*==============================Ū��result �}�l==============================*/	
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
	/*�w�ˬy�{*/	
	case 1:	
	cy++;
	printf("current cycle : %d Installing driver\n",cy);
	result=fopen("result.txt","wt");
	fprintf(result,"%d",cy);
	fclose(result);
	break;
	/*�Ϧw�ˬy�{*/
	case 2:
	printf("current cycle : %d Uninstalling driver\n",cy);
}
	count =0;
                                   /*==============================Ū��config �}�l==============================*/	
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
				if(dp[j]== ' ')/*��Ƨ����Ů檺�ﵦ*/
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
		command[dc][i] = '\0'; /*�b�r�굲���[�W�Ŧr��(\0)�T�O���|Ū��ýX,(���[�e�|Ū��)*/
		dc++;
		j+=15;
/*��install driver ��������O��X�Ӥ��}��*/
	while(dc<(df*2+1))
	{ 	i=0;
	
		/*���������O�����|*/
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
		/*���������O*/
		i=0;
		while(dp[j] != '\"')
			{	/*�����Ů�ﵦ�קK�ޭȻ~�[*/
			command[dc][i]= dp[j]; 
			j++;
			i++;
		
			}
			command[dc][i] = '\0'; 

		j+=15;
		dc++;
			
	}
/*��uninstall driver ��������O��X�Ӥ��}��*/
	j+=2;
	while(dc<((df*4)+1))
	{ 	i=0;

		/*���������O�����|*/
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
		/*���������O*/
		i=0;
		while(dp[j] != '\"')
			{	/*�����Ů�ﵦ�קK�ޭȻ~�[*/
			command[dc][i]= dp[j]; 
			j++;
			i++;
		
			}
			command[dc][i] = '\0'; 

		j+=17;
		dc++;		
	}
/* ������ƥظ���|
 
	for(i=0;i<dc;i++)
	{	printf("%d\n",i);
		printf("%s\n",command[i]);
	}*/
                                              /*==============================Ū��config ����==============================*/	
	
	
	switch(flagcheck_setup())
{
	
	case 3:

	startup(command[0],df);
	system("pause");
	
	/*�w�ˬy�{*/
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
	/*�Ϧw�ˬy�{*/
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
 /*===========Driver ���ݾ���==============*/
 int flagcheck_driverinstall()
 {	
	system("EXIT /B \%ERRORLEVEL\%");
 }

 /*===========check �ninstall�٬O uninstall==============*/
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
  /*===========�s�@flag �_�I==============*/
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
 
/*===========startup �j��ǳ� �bstartup folder ���Xbat�����t�Υi�H�brestart��۰ʰ���IUT.exe==============*/
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
 
 
 
 
 
 
 
