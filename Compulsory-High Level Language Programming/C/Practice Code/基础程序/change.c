#include <stdio.h>
int main()
{
	double price, bill;//��ʼ�� 
	
	printf("please input the price and your bill:");
	scanf("%lf %lf",&price,&bill);//���� �мǣ����븡����Ϊ%lf�����Ϊ%f 
	if (price < bill){//if�ж���䣬�мǣ��ж�����Ҫ�ӣ��� 
	double change = bill - price ;
	printf("your change is :%f",change);
}else{//else������Ļ� 
	double change1 = price - bill;
	printf("your bill is not enough,you still need %f dollars.",change1);
}
return 0;

}
