#include <stdio.h>

int main()
{
	int x ;
	int i= 0;
	int isPrime = 1;
	
	for (x = 2; x<= 100; x++){

	int isPrime = 1;
	for (i = 2;i<x;i++){
	if (x % i ==0){
		isPrime = 0;
		break;
	}
	}
	if (isPrime == 1){//括号内是逻辑运算符，所以不能=而是== 
		printf("%d\n",x); 
	}
}
	return 0 ;
	
 } 
