#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
	int n1;
	char c1,c2,c3,sum;
	printf("(getchar)please enter a word:");
	c1=getchar();
	printf("your word is ");
	putchar(c1);
	putchar('\n');
	
	printf("(getche)please enter a word:");
	c2=getche();
	printf("\nyour word is ");
	putchar(c2);
	putchar('\n');
	
	printf("(getch)please enter a word:");
	c3=getch();
	printf("\nyour word is ");
	putchar(c3);
	putchar('\n');
	/*sum = c1 + c2 + c3;
	printf("%d+%d+%d= %d",c1,c2,c3,sum);
	getchar, getche,getch 只能取得字元 無法取得整數 
	*/
	
	system("pause");
	return 0;
	
	
}
