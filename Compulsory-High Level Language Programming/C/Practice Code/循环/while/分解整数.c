#include <stdio.h>
int main ()
{//分解整数 
	int x ;
	scanf("%d",&x);
	int digit;
	int ret = 0 ;
	
	while(x!=0){
	digit = x % 10;
	//printf("%d",digit);//输出007时使用 
	ret = ret *10 + digit;//这一步做到了将每一次的个位向左移，解决700输出7而不是007的方法.很是精妙！！！！ 
	x/=10;
	}
	printf("%d",ret);
	
	return 0 ;
	
 }
