#include <stdio.h>
#include <math.h>
int pri(int a)  //判断质数
{
	int i;
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0) return 1;//找到了，返回1
    }
    return 0;//否则返回0
}
int main()
{
    int n,a,b,c, i, j;
    scanf("%d",&n);
    for( i=2;i<n;i++)//找到第一个数
    {
        if(pri(i)==0)
        for(j=2;j<n-i;j++)//判断第一个数是否为质数，如果是,寻找第二个数
        {
            if(pri(j)==0&&pri(n-i-j)==0) //找到2个数自然确定了第三个数 ，并判断第二和第三个数为质数
            {
                printf("%d %d %d\n",i,j,n-i-j);
                return 0;
            }
        }
    }
}
