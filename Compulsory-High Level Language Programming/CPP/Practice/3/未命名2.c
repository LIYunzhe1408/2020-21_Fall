#include <stdio.h>
#include <math.h>
int pri(int a)  //�ж�����
{
	int i;
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0) return 1;//�ҵ��ˣ�����1
    }
    return 0;//���򷵻�0
}
int main()
{
    int n,a,b,c, i, j;
    scanf("%d",&n);
    for( i=2;i<n;i++)//�ҵ���һ����
    {
        if(pri(i)==0)
        for(j=2;j<n-i;j++)//�жϵ�һ�����Ƿ�Ϊ�����������,Ѱ�ҵڶ�����
        {
            if(pri(j)==0&&pri(n-i-j)==0) //�ҵ�2������Ȼȷ���˵������� �����жϵڶ��͵�������Ϊ����
            {
                printf("%d %d %d\n",i,j,n-i-j);
                return 0;
            }
        }
    }
}
