#include <stdio.h>
int main()
{
	int x;
	int n = 0;
	
	scanf("%d",&x);//ò��Ŀǰ���ֻ�ܵ�ʮλ�� 
	
	n = n + 1;
	x = x / 10;
	while(x>0){	//x>0Ϊ������ѭ������Ҫ�д��ڸı������Ļ��� 
	n = n + 1;
	x = x / 10;//���о�Ϊ�ı������Ļ��� 
	}
	printf("n = %d",n);
	return 0;
}
