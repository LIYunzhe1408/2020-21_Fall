#include <stdio.h>
int main()
{
	int count = 0;
	double number=0,sum,result;
	
	while (number!=-1){
			scanf("%lf",&number);
		if (number !=-1){
		sum+=number;
		count ++;
		} 
		
	} 
	result = sum / count;
	printf("%f",result);
	return 0;
 } 
