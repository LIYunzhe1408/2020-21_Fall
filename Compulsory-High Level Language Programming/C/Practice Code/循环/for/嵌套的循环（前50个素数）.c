#include <stdio.h>

int main()
{
	int x ;
	int i= 0;
	int cnt = 0;
	 
	for (x = 2; cnt<50 ; x++){

	int isPrime = 1;
	for (i = 2;i<x;i++){
	if (x % i ==0){
		isPrime = 0; 
		break;
	}
	}
	if (isPrime == 1){//括号内是逻辑运算符，所以不能=而是== 
		cnt++;
		printf("%d\t",x); //将 %d后的空格改为反斜杠t就能将数字对齐 
		if (cnt % 5 ==0){//保证每5个数分一行 
			printf("\n");
		}
	}
}
	return 0 ;
	
 } 
