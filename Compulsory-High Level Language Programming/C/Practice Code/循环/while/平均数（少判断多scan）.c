#include <stdio.h>
int main()
{
	int count = 0;
	double number=0,sum,result;
	
	scanf("%lf",&number);
	while (number!=-1){
		sum+=number;
		count ++; 
		scanf("%lf",&number);
	} 
	result = sum / count;//�ĳ�С����Ҳ��int result���ڱ��䣨1.0*sum)���ɸ�Ϊ������  ##������*�����ɸı��ַ����� 
	printf("%f\n",result);
	return 0;
 } 
