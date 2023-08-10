#include <stdio.h>
#include <math.h>
int main()
{
	int y;
	
	scanf("%d",&y);
	int x = fabs (y)/y;
	
	switch (x){
		case -1:
		printf("-1");
		break;
		case 0:
			printf("0");
			break;
		case 1:
			printf("1");
			break;
			
	}
	return 0;
	
}
