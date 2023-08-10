#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int number = rand()%100+1;//+1是为了保证取到的数字在1-100之间可能出现的0和99的情况。 
	int count = 0;
	int a = 0;
	printf ("i have had a number in 1 to 100.\n");

	 
	//无论第一次初始值是否相等，用户总是需要猜一次的，所以do while 更合适 
	do{
		printf("please input a number within 1 to 100\n ");
		scanf("%d",&a);
		count++;
		if (a>number){
			printf("bigger\n");
		}else if (a<number){
			printf("smaller\n");
		}
	}while (a!=number);
	printf("congratulations,you guess it for%d times",count);
	return 0 ;
	
 } //最多7次就能成功。二分法2的7次方128 
