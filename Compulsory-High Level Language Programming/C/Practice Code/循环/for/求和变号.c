#include <stdio.h>
int main ()
{
	int i, n;
	double sum = 0.0;
	double sign = 1.0;
	 
	
	scanf("%d",&n);
	for (i = 1 ; i <= n; i++){
		
		sum += sign * 1.0/i; 
		sign = - sign;//每一步结束变号 !!!!
	}
	printf("f(%d) = %f",n,sum);
	return  0 ;
	
	
 }
	 
