#include <stdio.h>

int main()
{
	int x ;
	scanf("%d",&x);
	int i;
	int isPrime = 1;
	
	for (i = 2;i<x;i++){
	if (x % i ==0){
		isPrime = 0;
		break;
	}
	}
	if (isPrime == 1){//括号内是逻辑运算符，所以不能=而是== 
		printf("是素数"); 
	}else {
		printf("不是素数");
		
	}
	return 0 ;
	
 } 
