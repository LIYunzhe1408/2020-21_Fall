#include <stdio.h>
int main()
{
	int equal=0 ;
	int i = 1;
	for (i= 1;i<=10;i++){//括号中第一个i = 1 可以不要，但；不能省略 
		equal = equal + i;
	}
	printf("equal = %d",equal);
	return 0;
	
}
