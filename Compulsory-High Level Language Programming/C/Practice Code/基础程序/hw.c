#include <stdio.h>
int main()
{
	int amount,price;
	printf("请输入金额和票面：");
	scanf("%d %d",&price,&amount);
	
	
	int change = amount - price;
	printf("找您%d元。\n",change);
	return 0  ;
	
	

	
}
