#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int number = rand()%100+1;//+1��Ϊ�˱�֤ȡ����������1-100֮����ܳ��ֵ�0��99������� 
	int count = 0;
	int a = 0;
	printf ("i have had a number in 1 to 100.\n");

	 
	//���۵�һ�γ�ʼֵ�Ƿ���ȣ��û�������Ҫ��һ�εģ�����do while ������ 
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
	
 } //���7�ξ��ܳɹ������ַ�2��7�η�128 
