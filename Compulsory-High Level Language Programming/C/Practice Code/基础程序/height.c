#include <stdio.h>
int main ()
{
	printf("Please input your foot and inch:");
	double foot, inch;
	scanf("%lf %lf",&foot, &inch);
	printf("Your height is %f meters\n",((foot+inch/12)*0.3048));
	return 0 ;
	
}   
