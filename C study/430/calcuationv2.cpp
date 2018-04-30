#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int a,b,sum;
	char oper;
	printf("please enter a calculation(ex:2+3)\n");
	scanf("%d%c%d",&a,&oper,&b); 
	
	switch(oper)
	{
		case '+':
			sum = a+b;
		printf("%d %c %d = %d",a,oper,b,sum);
		break;
		case '-':
			sum = a-b;
		printf("%d %c %d = %d",a,oper,b,sum);
		break;	
		case '*':
			sum = a*b;
		printf("%d %c %d = %d",a,oper,b,sum);
		break;
		case '/':
			sum = a/b;
		printf("%d %c %d = %d",a,oper,b,sum);
		break;
		default:
		printf("oper not correct.");		
	}
	
	system("pause");
	return 0;
	
	
}
