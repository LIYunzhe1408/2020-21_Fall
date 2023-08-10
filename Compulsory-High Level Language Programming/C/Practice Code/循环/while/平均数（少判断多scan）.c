#include <stdio.h>
int main()
{
	int count = 0;
	double number=0,sum,result;
	
	scanf("%lf",&number);
	while (number!=-1){
		sum+=number;
		count ++; 
		scanf("%lf",&number);
	} 
	result = sum / count;//改成小数，也可int result再在本句（1.0*sum)即可改为浮点数  ##浮点数*整数可改变字符类型 
	printf("%f\n",result);
	return 0;
 } 
