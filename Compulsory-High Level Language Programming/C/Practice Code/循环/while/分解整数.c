#include <stdio.h>
int main ()
{//�ֽ����� 
	int x ;
	scanf("%d",&x);
	int digit;
	int ret = 0 ;
	
	while(x!=0){
	digit = x % 10;
	//printf("%d",digit);//���007ʱʹ�� 
	ret = ret *10 + digit;//��һ�������˽�ÿһ�εĸ�λ�����ƣ����700���7������007�ķ���.���Ǿ�������� 
	x/=10;
	}
	printf("%d",ret);
	
	return 0 ;
	
 }
