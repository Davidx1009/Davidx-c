#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int flagcheck(void);

int main()
{
	FILE *config;
	int i=0,dc=0,j=12,dflag=0,count=0,df;
	char command[30][300],ch;
	
	config=fopen("config.txt","rb");
		while((ch=getc(config)) != EOF)
	{	
		count++;
	}
	fclose(config);
	config=fopen("config.txt","rb");
	char dp[count];
	while(!feof(config))
	{
	fread(dp,sizeof(char),count,config);
	}
	fclose(config);
	printf("how many driver you would like to install?");
	scanf("%d",&df);
	while(dc<df)
	{ 	i=0;	/*��driver �w�˸��|��X�Ӥ��}��*/
		printf("%d",df);
			while(dp[j] != '\"')
			{
			command[dc][i]= dp[j]; 
			j++;
			i++;
		
			}
			command[dc][i] = '\0'; /*�b�r�굲���[�W�Ŧr��(\0)�T�O���|Ū��ýX,(���[�e�|Ū��)*/
			printf("%c",dp[j]);
		j+=15;
		dc++;
			
	}
		system("pause");
	
	for(i=0;i<dc;i++)
	{
	printf("%s\n",command[i]);
	system(command[i]);
	flagcheck();
	}	
	
	system("pause");
	return 0;
	
 } 
 /*Driver ���ݾ���*/
 int flagcheck()
 {	
 	FILE *flag;
 	flag=fopen("FAILURE.FLG","rb");
 	while(flag != NULL)
 	{
	flag=fopen("FAILURE.FLG","rb");
	Sleep(2000); 	
	}
 	
 	
 }
