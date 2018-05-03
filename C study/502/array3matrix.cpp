#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ar[2][4][3]={
	{{33,25,11},{55,37,88},{87,23,45},{65,34,11}},
	{{55,47,23},{78,94,23},{23,45,99},{34,65,21}}
	};
	
	int a,b,c,max;
	
	for(a=0;a<2;a++)
		for(b=0;b<4;b++)
			for(c=0;c<3;c++)
				if(max < ar[a][b][c])
					max =ar[a][b][c];
					
	
	printf("max number is %d\n",max);
	
	system("pause");
	return 0;
	
}
