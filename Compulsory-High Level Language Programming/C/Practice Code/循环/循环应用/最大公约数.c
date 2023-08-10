/*

辗转相除法（计算两个正整数最大公约数的一般方法 ） 

如果b=0，计算结束，a就是最大公约数;
否则，计算a除以b的余数，让a等于b，而b等于那个余数； 
回到第一步；*/

#include <stdio.h>
int main()
{
	int a,b,t;
	scanf("%d %d",&a,&b);
	while (b!=0){
	t = a%b;
	a=b;
	b=t;
	}
	printf("%d",a);
	return 0;
 } 
