#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main()
{
	FILE *note;
	char ch,command;
	int count=0;
/*	if(argv[1] == NULL)
	note=fopen("newdoc.txt","w");
	fclose(note);
	else
	note=fopen(argv[1],"r");
*/
	while(1)
	{
	count=0;

	note=fopen("newdoc.txt","rt");
	
		while((ch=getc(note)) != EOF)
	{	
		count++; /*取得所需空間*/
	}
	fclose(note);
	note=fopen("newdoc.txt","rt");
	
	char dp[count];
	while(!feof(note))
	{
	fread(dp,sizeof(char),count,note);
	}
	fclose(note);
	dp[count]='\0';
	printf("%s",dp);
	command= getche();
	if( command == 8)
	break; 
	
	dp[count]=command;
	//printf("\n%s",dp);
	//system("pause");
	
	note=fopen("newdoc.txt","w+t");
	fwrite(dp,sizeof(char),count+1,note);
	
	fclose(note);
	
	
	system("CLS");
		
		
	}
    fclose(note);

	return 0;
	
}
