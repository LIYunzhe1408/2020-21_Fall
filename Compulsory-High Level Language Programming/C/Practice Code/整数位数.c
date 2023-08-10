#include<stdio.h>
int main ()
{
	int x , n= 0,mask= 1;
	scanf ("%d",&x);
	
	while ( x> 9)
	{ 
	x /= 10 ;
	mask *= 10;
	n++;
	}
	printf("n = %d, mask = %d",n,mask);
	return 0 ;
	
	} 
