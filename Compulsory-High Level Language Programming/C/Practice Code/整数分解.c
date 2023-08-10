#include <stdio.h>
int main ()
{
	int x = 70000, t = 0 , digit = 10000, cnt = 0;
	
	do{
		x /= 10;
		cnt ++;
	}while (x>0);
	printf("%d",cnt);
	
	
	do {
		t = x / digit;
		printf ("%d",t);
		if ( digit >=10 ){
			printf(" ");
		}
		x %= digit;
		digit /= 10;
	}while (digit>0);
	return 0;
	
 } 
 
// 逆序（只适合末尾没有零的数字） 
// x= ... 
// int t = 0 ;
// do {
// 	int  d = x%10;
//	t = t*10 +d;
//	x/= 10; 
// }  while (x>0);
// printf ("t = %d\n,t");
// x= t
