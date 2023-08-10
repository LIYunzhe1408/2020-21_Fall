#include <stdio.h>
int main()
{
	double score;
	
	printf("plz input your score:");
	scanf("%lf",&score);
	int grade = score / 10;
	switch ( grade){
		case 10:
		case 9:
			printf("your score is A\n");
		break;
		case 8:
			printf("your score is B\n");
		break;
		default :
			printf("you fail");
			break;
	}
	return 0;
	
}
