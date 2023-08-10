#include <stdio.h>
int main()
{
	int x;
	int n = 0;
	
	scanf("%d",&x);//貌似目前最大只能到十位数 
	
	n = n + 1;
	x = x / 10;
	while(x>0){	//x>0为条件，循环体内要有存在改变条件的机会 
	n = n + 1;
	x = x / 10;//此行就为改变条件的机会 
	}
	printf("n = %d",n);
	return 0;
}
