#include <stdio.h>

int main()
{
	int x ;
	int i= 0;
	int cnt = 0;
	 
	for (x = 2; cnt<50 ; x++){

	int isPrime = 1;
	for (i = 2;i<x;i++){
	if (x % i ==0){
		isPrime = 0; 
		break;
	}
	}
	if (isPrime == 1){//���������߼�����������Բ���=����== 
		cnt++;
		printf("%d\t",x); //�� %d��Ŀո��Ϊ��б��t���ܽ����ֶ��� 
		if (cnt % 5 ==0){//��֤ÿ5������һ�� 
			printf("\n");
		}
	}
}
	return 0 ;
	
 } 
