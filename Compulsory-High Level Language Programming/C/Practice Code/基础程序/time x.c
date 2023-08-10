#include <stdio.h>
int main()
{
	int hour1, min1;
	int hour2, min2;
	printf("please input first time:");
	scanf("%d %d",&hour1, &min1);
	printf("please input second time:");
	scanf("%d %d",&hour2, &min2);
	
	int t1=hour1*60 + min1;
	int t2=hour2*60  + min2;
	int x = (t2-t1);
	
	printf("the time you want is %d hour %d min",x/60,x%60);
	return 0 ;
	
}
