/* 给定不超过6的正整数A，考虑从A开始的连续4个数字，请输出所有由它们组成的无重复数字的3位数
输入格式：输入在一行中给出A
输出格式：输出满足条件的3位数，要求从小到大，每行6个整数，整数间以空格分隔，但行末不能有多余的空格
输入样例：2
输出样例：
234 235 243 253 254
xxx

523 524 534 542 543*/

#include <stdio.h>
int main()
{
	int A,cnt;
	scanf("%d",&A);
	int i ,j ,k ;//三位数，需要三个变量 
//需要的是一个三位数，所以需要三重循环，每一重循环要让A走到A+3 
	i = A;
	while (i<= A+3){
		j = A;
		while (j <= A+3){
			k = A ;
			while ( k <= A+3){
				if ( i!=j){
					if (i!= k ){
						if(j!=k){
							cnt++;
							printf("%d%d%d",i,j,k);
							if (cnt ==6){
								cnt=0; 
								printf("\n");
							}else{
								printf(" ");
							}
						} 
					}
				}
				k++;
			}
			j ++;
		}
		i++;
	}
	return 0 ;
  }  
