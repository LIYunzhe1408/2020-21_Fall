#include <stdio.h>
int main()
{
	double price, bill;//初始化 
	
	printf("please input the price and your bill:");
	scanf("%lf %lf",&price,&bill);//输入 切记：输入浮点数为%lf，输出为%f 
	if (price < bill){//if判断语句，切记：判断条件要加（） 
	double change = bill - price ;
	printf("your change is :%f",change);
}else{//else：否则的话 
	double change1 = price - bill;
	printf("your bill is not enough,you still need %f dollars.",change1);
}
return 0;

}
